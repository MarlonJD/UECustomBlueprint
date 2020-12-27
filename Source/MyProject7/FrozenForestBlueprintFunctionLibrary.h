// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HttpModule.h"
#include "Http.h"
#include "GameFramework/Actor.h"
//#include <Interfaces\IHttpRequest.h>
//#include <Interfaces\IHttpResponse.h>
#include "MyEnums.h"
#include "FrozenForestBlueprintFunctionLibrary.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE_ThreeParams(FCallBackIsSuccessBP, FHttpRequestPtr, FHttpResponsePtr, bool);

UCLASS()
class MYPROJECT7_API UFrozenForestBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

    public:
        FHttpModule* Http;
        FTimerHandle TimerHandle;
        static FCallBackIsSuccessBP CallBackIsSuccessBP;
        
        
        UFUNCTION(BlueprintCallable, Category = "Frozen Forest")
        static void TestFFBluePrint(const int a, const int b, int& sonuc1, int& sonuc2);

        UFUNCTION(BlueprintCallable, 
            meta = (
                DisplayName = "FF HTTP: Create HTTP Request",
                Keywords = "HTTP Call Request Create",
                AdvancedDisplay = "2",
                ToolTip = "FF HTTP: Create HTTP Request"
            ),
            Category = "Frozen Forest")
        static void fMyHttpCall(const FString url, TEnumAsByte<TreeType> method, FString& response);

        static void fOnHttpRecieve(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

        UFUNCTION(BlueprintCallable, Category = "Frozen Forest")
        static void fMyHttpResponse(FString& response);
};
