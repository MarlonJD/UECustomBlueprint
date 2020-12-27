// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#include "WebServer.h"
#include "UnrealWebServerPrivatePCH.h"
#include "mongoose.h"

UWebServer* UWebServer::Instance = nullptr;

UWebServer* UWebServer::GetOrCreateWebServerInstance()
{
	return Get();
}

UWebServer* UWebServer::Get()
{
	if (Instance == nullptr)
	{
		Instance = NewObject<UWebServer>();
	}

	return Instance;
}

void UWebServer::StartServer(const int32 Port, const FString& DocumentRoot)
{
	this->AddToRoot(); // Trick to avoid GC

	FString WwwDir = DocumentRoot;
	if (FPaths::IsRelative(DocumentRoot))
	{
		WwwDir = FPaths::Combine(FPaths::ProjectContentDir(), DocumentRoot);
	}

	char chPort[20];
	_itoa_s(Port, chPort, 10);
	const char* chPath = TCHAR_TO_UTF8(*FPaths::ConvertRelativePathToFull(WwwDir));
	const char* options[] = {
		"listening_ports", chPort,
		"document_root", chPath,
		nullptr
	};

	memset(&Callbacks, 0, sizeof(Callbacks));

	Callbacks.begin_request = BeginRequestHandler;
	// TODO : maybe more callbacks
	Context = mg_start(&Callbacks, nullptr, options);

	if (Context == nullptr)
	{
		UE_LOG(UnrealWebServer, Error, TEXT("WebServer not started on port %d and path %s\n"), Port, *FPaths::ConvertRelativePathToFull(WwwDir));
	}
	else
	{
		bStarted = true;
		UE_LOG(UnrealWebServer, Log, TEXT("WebServer started on port %d and path %s\n"), Port, *FPaths::ConvertRelativePathToFull(WwwDir));
	}
}

void UWebServer::StopServer()
{
	if (Context != nullptr)
	{
		mg_stop(Context);
	}

	bStarted = false;

	Instance = nullptr; // Let GC delete *this
}

void UWebServer::AddURIHandler(const FString& Path, const FRESTServerCallDelegate& Callback, EHttpRequestMethod Method, bool ExecuteInGameThread)
{
	FUrlConfiguration config;
	config.Callback = Callback;
	config.Method = Method;
	config.Path = Path;
	config.ExecuteInGameThread = ExecuteInGameThread;

	string sPath = TCHAR_TO_UTF8(*Path);
	string sMathod = TCHAR_TO_UTF8(*HttpRequestMethodToString(Method));

	if (!UrlConfigs.Contains(config))
	{
		UrlConfigs.Add(config);
	}
}


int UWebServer::BeginRequestHandler(struct mg_connection* Conn)
{
	bool processed = false;
	const struct mg_request_info* ri = mg_get_request_info(Conn);
	UE_LOG(UnrealWebServer, Log, TEXT("Request incoming : %s - %s"), ri->request_method, ri->uri);


	for (FUrlConfiguration url : Instance->UrlConfigs)
	{
		//if (mg_isMapped(conn, TCHAR_TO_UTF8(*HttpRequestMethodToString(url.method)), TCHAR_TO_UTF8(*url.path)))
		if (MatchRequestUri(ri->uri, url.Path) &&
			(ri->request_method == HttpRequestMethodToString(url.Method) || url.Method == EHttpRequestMethod::VE_ALL))
		{
			UConnection* connection = NewObject<UConnection>();
			connection->SetConnection(Conn);
			connection->SetRequestInfo(ri);
			UE_LOG(UnrealWebServer, Log, TEXT("Unreal callback => %s\n"), *url.Callback.GetFunctionName().ToString());

			// Run in game thread?
			if(url.ExecuteInGameThread)
			{
				FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([&]()
				{
					url.Callback.ExecuteIfBound(connection);
				}, TStatId(), NULL, ENamedThreads::GameThread);

				// Await for the execution
				FTaskGraphInterface::Get().WaitUntilTaskCompletes(Task);
			}
			else
			{
				url.Callback.ExecuteIfBound(connection);
			}

			processed = true;
		}
	}

	if (!processed)
	{
		UE_LOG(UnrealWebServer, Warning, TEXT("NO Unreal callback found\n"));
	}

	return processed; // Mark request as processed
}

bool UWebServer::MatchRequestUri(const FString& InUri, const FString& CompareUri)
{
	const FString In = InUri.ToUpper();
	const FString Compare = CompareUri.ToUpper();
	if (In == Compare) return true;
	if (!Compare.Contains("*")) return false;
	const FString regex = Compare.Replace(TEXT("*"), TEXT("[a-zA-Z0-9_]+"));
	const FRegexPattern pattern(regex);
	FRegexMatcher matcher(pattern, In);
	return matcher.FindNext();
}