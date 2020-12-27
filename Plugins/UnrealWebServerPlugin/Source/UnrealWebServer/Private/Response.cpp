// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#include "Response.h"
#include "UnrealWebServerPrivatePCH.h"

FString UResponse::GetResponseData()
{
	FString response = "";
	response += HttpVersion + " " + HttpStatusCodeToString(StatusCode) + CrLf;
	if (Content != "")
		response += FString::Printf(TEXT("Content-Length: %d"), Content.Len()) + CrLf;
	response += "Content-Type: " + MediaTypeToString(ContentType) + CrLf;
	if (Redirection != "")
		response += "Location: " + Redirection + CrLf;
	for(UCookie* cookie : Cookies)
		response += cookie->ToString() + CrLf;
	response += CrLf;
	response += Content;
	return response;
}

UResponse* UResponse::ConstructResponse(UObject* WorldContextObject)
{
	return NewObject<UResponse>();
}

UResponse* UResponse::ConstructResponseExt(UObject* WorldContextObject, const FString& content)
{
	UResponse* response = ConstructResponse(WorldContextObject);
	response->SetResponseContent(content);
	return response;
}

void UResponse::SetResponseStatusCode(EHttpStatusCode HttpStatusCode)
{
	this->StatusCode = HttpStatusCode;
}

void UResponse::AddResponseCookie(UCookie* Cookie)
{
	this->Cookies.Add(Cookie);
}

void UResponse::SetResponseRedirection(const FString& ResponseRedirection)
{
	this->Redirection = ResponseRedirection;
}

void UResponse::SetResponseContentType(EMediaType ResponseContentType)
{
	this->ContentType = ResponseContentType;
}

void UResponse::SetResponseContent(const FString& ResponseContent)
{
	this->Content = ResponseContent;
}
