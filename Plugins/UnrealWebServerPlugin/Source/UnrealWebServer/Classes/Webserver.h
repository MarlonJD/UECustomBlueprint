// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#pragma once

#include "HttpRequestMethod.h"
#include "mongoose.h"

#include "WebServer.generated.h"

using namespace std;

DECLARE_DYNAMIC_DELEGATE_OneParam(FRESTServerCallDelegate, UConnection*, Connection);

/**
 * Internal struct used by UWS
 */
struct FUrlConfiguration
{
	FString Path;
	FRESTServerCallDelegate Callback;
	EHttpRequestMethod Method;
	bool ExecuteInGameThread;

	bool operator==(const FUrlConfiguration& UrlConfiguration) const
	{
		return (UrlConfiguration.Path == Path) && (UrlConfiguration.Method == Method);
	}
};

/**
* UWebServer is the main singleton of the UnrealWebServer plugin.
* Its job is to manage and monitor the web server status.
* @author Isara Technologies.
* @version 1.3
*/
UCLASS(BlueprintType)

class UNREALWEBSERVER_API UWebServer : public UObject
{
	GENERATED_BODY()
public:

	/**
	 * Gets or creates a Web Server instance
	 * @return Returns an instance of the singleton
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	static UWebServer* GetOrCreateWebServerInstance();

	static UWebServer* Get();

	/**
	 * Starts the web server
	 * @param Port the port of the server
	 * @param DocumentRoot the location of static files (html, js, css, etc...)
	 * The path can be either absolute or relative (using Game Contents folder)
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	void StartServer(const int32 Port, const FString& DocumentRoot);

	/**
	 * Stops the web server
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	void StopServer();

	/**
	 * Adds an URI handler
	 * @param Path the URI path 
	 * @param Callback the function called (this function needs a UConnection object as parameter)
	 * @param Method the HTTP method to filters
	 * @param ExecuteInGameThread does this callback must be executed in game thread?
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	void AddURIHandler(const FString& Path, const FRESTServerCallDelegate& Callback, EHttpRequestMethod Method, bool ExecuteInGameThread); // Dont use const& : we cant select enum in this blueprint node

	/**
	 * Returns <code>true</code> if the server is started, <code>false</code> otherwise
	 * @return <code>true</code> if the server is started, <code>false</code> otherwise
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")

	bool IsStarted() const
	{
		return bStarted;
	}

	static int BeginRequestHandler(struct mg_connection* conn);
	static bool MatchRequestUri(const FString& InUri, const FString& CompareUri);

private:

	static UWebServer* Instance;

	struct mg_context* Context;
	struct mg_callbacks Callbacks;
	TArray<FUrlConfiguration> UrlConfigs;

	bool bStarted = false;
};
