// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Http.h"
//#include <Interfaces\IHttpRequest.h>
//#include <Interfaces\IHttpResponse.h>
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT7_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

    public:
        FHttpModule* Http;

        UFUNCTION(BlueprintCallable, Category = "Frozen Forest")
        static void TestFFBluePrint(const int a, const int b, int& sonuc1, int& sonuc2);

        UFUNCTION(BlueprintCallable, Category = "Frozen Forest")
        static void fMyHttpCall(const FString url);

        static void fOnHttpRecieve(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

        UFUNCTION(BlueprintCallable, Category = "Frozen Forest")
        static void fMyHttpResponse(FString& response);
};
