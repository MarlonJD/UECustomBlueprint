// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#pragma once

#include "HttpStatusCode.h"  // https://answers.unrealengine.com/questions/427309/ustruct-type-must-be-a-uclass-ustruct-or-uenum.html
#include "Response.h"
#include "mongoose.h"
#include "Connection.generated.h"


/**
 * The UConnection class is used to store all informations about the HTTP connection established with the client.
 * The connection is fulfilled with all HTTP and client informations
 * Getters can easily access to the connection variables (headers, etc...)
 * @author Isara Technologies.
 * @version 1.3
 */
UCLASS(BlueprintType)

class UNREALWEBSERVER_API UConnection : public UObject
{
	GENERATED_BODY()
public:
	void SetConnection(mg_connection* Conn);
	void SetRequestInfo(const mg_request_info* Rq);

	/**
	 * Send the response to the client
	 * @param response The fulfilled response to send to the client
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	void SendResponse(UResponse* response) const;

	/**
	* Send a raw response to the client
	* @param response The string containing the response : it must include headers, such as response code and so on...
	*/
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer", meta = (ToolTip = "This raw responde must include http headers and response code"))
	void SendRawResponse(const FString& responseData) const;

	/**
	* Send a raw response single byte to the client
	* @param responseByte The byte containing data to send to response
	*/
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	void SendRawResponseByte(const uint8& responseByte) const;

	/**
	* Send a raw response bytes to the client
	* @param buffer Bytes containing data to send to response
	* @param length The size of the data
	*/
	void SendRawResponseBytes(const void* buffer, size_t length) const;

	/**
	 * Gets the value of the wished header
	 * @param name The header name to find the value of
	 * @return the header value if found
	 * Empty string if not found.
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	FString GetHeader(const FString& name) const;

	/**
	* Gets the whole data available in the request
	* @return the data 
	*/
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	FString GetData() const;

	/**
	* Gets the value of the wished GET variable
	* @param name The GET var name to find the value of
	* @return the GET var value if found
	* Empty string if not found.
	*/
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	FString GetGETVar(const FString& name) const;

	/**
	* Gets the value of the wished POST variable
	* @param name The POST var name to find the value of
	* @return the POST var value if found
	* Empty string if not found.
	*/
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	FString GetPOSTVar(const FString& name) const;

	/**
	* Gets the value of the wished COOKIE variable
	* @param name The COOKIE var name to find the value of
	* @return the COOKIE var value if found
	* Empty string if not found.
	*/
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	FString GetCOOKIEVar(const FString& name) const;

	/**
	* Gets the uri path used for this connection
	* @return the URI path
	*/
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	FString GetUriPath() const;

	/**
	* Gets the uri method for this connection
	* @return the URI
	*/
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	FString GetUriMethod() const;

	/**
	 * Gets the data blob
	 * @return the data blob
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")
	TArray<uint8> GetDataBlob() const;

private:
	mg_connection* Connection;
	const mg_request_info* RequestInfo;
};
