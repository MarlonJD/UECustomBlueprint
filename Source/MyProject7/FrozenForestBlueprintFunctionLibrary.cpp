// Fill out your copyright notice in the Description page of Project Settings.


#include "FrozenForestBlueprintFunctionLibrary.h"


struct A {
	static FString response0;
	static bool isSuccess;
};
FString A::response0;
bool A::isSuccess;
FCallBackIsSuccessBP UFrozenForestBlueprintFunctionLibrary::CallBackIsSuccessBP;

void UFrozenForestBlueprintFunctionLibrary::TestFFBluePrint(const int a, const int b, int& sonuc1, int& sonuc2)
{
	sonuc1 = (a + b);
	sonuc2 = (a - b);
}


void UFrozenForestBlueprintFunctionLibrary::fMyHttpCall(const FString url, TEnumAsByte<TreeType> method, FString& response)
{
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();

	if (method == TreeType::get) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "GET Secildi");
	}

	else if (method == TreeType::post) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "POST Secildi");
	}

	else if (method == TreeType::put) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "PUT Secildi");
	}

	else if (method == TreeType::del) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "DELETE Secildi");
	}

	//Request->OnProcessRequestComplete().BindStatic(&UFrozenForestBlueprintFunctionLibrary::fOnHttpRecieve);
	//Callback.Broadcast(A::isSuccess);
	//FCallBackIsSuccessBP UFrozenForestBlueprintFunctionLibrary::CallBackIsSuccessBP;
	//Request->OnProcessRequestComplete().BindUObject(CallBackIsSuccessBP.);

	Request->OnProcessRequestComplete().BindStatic([](FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
	{
		//A::response0 = ->GetContentAsString();
	});

	response = A::response0;

	if (!url.IsEmpty()) {
		Request->SetURL(url);
		Request->SetVerb("GET");
		Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
		Request->SetHeader(TEXT("Content-Type"), TEXT("Application/json"));
		Request->ProcessRequest();
	}
}


void UFrozenForestBlueprintFunctionLibrary::fOnHttpRecieve(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, Response->GetContentAsString());
	//Response->GetContentAsString();
	//std::bind(&UMyBlueprintFunctionLibrary::LastResponse, Response->GetContentAsString());

	//CallBackIsSuccessBP.
	//A::response0 = HttpResponse;
	//A::isSuccess = bSucceeded;
}



void UFrozenForestBlueprintFunctionLibrary::fMyHttpResponse(FString& response)
{
	response = A::response0;
}
