// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#include "HttpRequestMethod.h"

#include "UnrealWebServerPrivatePCH.h"

FString HttpRequestMethodToString(const EHttpRequestMethod httpRequestMethod)
{
	switch (httpRequestMethod) {
	case EHttpRequestMethod::VE_GET:
		return FString("GET");
	case EHttpRequestMethod::VE_POST:
		return FString("POST");
	case EHttpRequestMethod::VE_HEAD:
		return FString("HEAD");
	case EHttpRequestMethod::VE_PUT:
		return FString("PUT");
	case EHttpRequestMethod::VE_OPTIONS:
		return FString("OPTIONS");
	case EHttpRequestMethod::VE_PROPFIND:
		return FString("PROPFIND");
	case EHttpRequestMethod::VE_MKCOL:
		return FString("MKCOL");
	case EHttpRequestMethod::VE_ALL:
		return FString("*");
	default:
		return FString("");
	}
}