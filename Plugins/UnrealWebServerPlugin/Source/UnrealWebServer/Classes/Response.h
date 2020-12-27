// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#pragma once

#include "HttpStatusCode.h"  // https://answers.unrealengine.com/questions/427309/ustruct-type-must-be-a-uclass-ustruct-or-uenum.html
#include "Cookie.h"
#include "MediaType.h"

#include "Response.generated.h"

/**
* The UResponse class is used to build an HTTP response to send back to the client
* This class is needed by the SendResponse method of UConnection 
* @author Isara Technologies.
* @version 1.0
*/
UCLASS(BlueprintType)

class UNREALWEBSERVER_API UResponse : public UObject
{
	GENERATED_BODY()
public:

	/**
	* Constructs a new empty response
	* @param WorldContextObject autofilled param from Unreal
	*/
	UFUNCTION(BlueprintPure, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "UnrealWebServer")
	static UResponse* ConstructResponse(UObject* WorldContextObject);

	/**
	* Constructs a new response with an http content
	* The HTTPStatus code will be automatically set to 200
	* @param WorldContextObject autofilled param from Unreal
	* @param content the HTTP content
	*/
	UFUNCTION(BlueprintPure, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "UnrealWebServer")
	static UResponse* ConstructResponseExt(UObject* WorldContextObject, const FString& content);


	FString GetResponseData();

	/**
	 * Sets a specific http response status code
	 * @param statusCode The HTTP status code
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	void SetResponseStatusCode(EHttpStatusCode statusCode); // Dont use const& : we cant select enum in this blueprint node

	/**
	 * Adds a cookie to the response.
	 * Multiple cookies can be add to a single response
	 * @param cookie The cookie
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	void AddResponseCookie(UCookie* cookie);

	/**
	 * Sets a response redirection
	 * It is wished to use a specific HTTP status code with a redirection (such as Permanently moved)
	 * @param redirection the URL to redirect the user to
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	void SetResponseRedirection(const FString& redirection);

	/**
	 * Sets the response mime content type
	 * @param contentType the media type of the content
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	void SetResponseContentType(EMediaType contentType);

	/**
	 * Sets a response content (http body)
	 * @param content the body of the http response
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	void SetResponseContent(const FString& content);


private:
	const FString CrLf = "\r\n";
	const FString HttpVersion = "HTTP/1.1";

	EHttpStatusCode StatusCode = EHttpStatusCode::VE_OK;
	TArray<UCookie*> Cookies;
	FString Redirection;
	EMediaType ContentType = EMediaType::TEXT_HTML;
	FString Content;
};
