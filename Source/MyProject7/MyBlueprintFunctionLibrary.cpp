// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

struct A {
	static FString response0;
};
FString A::response0;

void UMyBlueprintFunctionLibrary::TestFFBluePrint(const int a, const int b, int& sonuc1, int& sonuc2)
{
	sonuc1 = (a + b);
	sonuc2 = (a - b);
}

void UMyBlueprintFunctionLibrary::fMyHttpCall(const FString url)
{
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindStatic(&UMyBlueprintFunctionLibrary::fOnHttpRecieve);

	if (!url.IsEmpty()) {
		Request->SetURL(url);
		Request->SetVerb("GET");
		Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
		Request->SetHeader(TEXT("Content-Type"), TEXT("Application/json"));
		Request->ProcessRequest();
	}
}


void UMyBlueprintFunctionLibrary::fOnHttpRecieve(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, Response->GetContentAsString());
	//Response->GetContentAsString();
	//std::bind(&UMyBlueprintFunctionLibrary::LastResponse, Response->GetContentAsString());
	A::response0 = Response->GetContentAsString();
}

void UMyBlueprintFunctionLibrary::fMyHttpResponse(FString& response)
{
	response = A::response0;
}
