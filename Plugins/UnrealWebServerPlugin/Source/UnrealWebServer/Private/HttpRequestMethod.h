// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#pragma once

#include "UnrealWebServerPrivatePCH.h"

/**
* The EHttpRequestMethod enum stores all HTTP request methods
* This enum is needed to fulfill the AddURIHandler method of UWebServer
* @author Isara Technologies.
* @version 1.0
*/
UENUM(BlueprintType)

enum class EHttpRequestMethod : uint8
{
	VE_ALL UMETA(DisplayName = "*"),
	VE_GET UMETA(DisplayName = "GET"),
	VE_POST UMETA(DisplayName = "POST"),
	VE_HEAD UMETA(DisplayName = "HEAD"),
	VE_CONNECT UMETA(DisplayName = "CONNECT"),
	VE_PUT UMETA(DisplayName = "PUT"),
	VE_OPTIONS UMETA(DisplayName = "OPTIONS"),
	VE_PROPFIND UMETA(DisplayName = "PROPFIND"),
	VE_MKCOL UMETA(DisplayName = "MKCOL")
};

FString HttpRequestMethodToString(const EHttpRequestMethod httpRequestMethod);
