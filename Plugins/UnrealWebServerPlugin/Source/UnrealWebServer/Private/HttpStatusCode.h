// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#pragma once

#include "UnrealWebServerPrivatePCH.h"

/**
* The EHttpStatusCode enum stores all HTTP status codes
* This enum is needed to fulfill The UResponse with SetResponseStatusCode method
* @author Isara Technologies.
* @version 1.0
*/
UENUM(BlueprintType)
enum class EHttpStatusCode : uint8
{
	VE_Continue							UMETA(DisplayName = "100 Continue"),
	VE_SwitchingProtocols				UMETA(DisplayName = "101 Switching Protocols"),
	VE_Processing						UMETA(DisplayName = "102 Processing"),

	VE_OK								UMETA(DisplayName = "200 OK"),
	VE_Created		 					UMETA(DisplayName = "201 Created"),
	VE_Accepted		 					UMETA(DisplayName = "202 Accepted"),
	VE_NonAuthoritativeInformation 		UMETA(DisplayName = "203 Non-Authoritative Information"),
	VE_NoContent						UMETA(DisplayName = "204 No Content"),
	VE_ResetContent	 					UMETA(DisplayName = "205 Reset Content"),
	VE_PartialContent	 				UMETA(DisplayName = "206 Partial Content"),
	VE_MultiStatus	 					UMETA(DisplayName = "207 Multi-Status"),
	VE_AlreadyReported	 				UMETA(DisplayName = "208 Already Reported"),
	VE_ImUsed		 					UMETA(DisplayName = "226 IM Used"),

	VE_MultipleChoices 					UMETA(DisplayName = "300 Multiple Choices"),
	VE_MovedPermanently					UMETA(DisplayName = "301 Moved Permanentely"),
	VE_Found		 					UMETA(DisplayName = "302 Found"),
	VE_SeeOther 						UMETA(DisplayName = "303 See Other"),
	VE_NotModified		 				UMETA(DisplayName = "304 Not Modified"),
	VE_UseProxy	 						UMETA(DisplayName = "305 Use Proxy"),
	VE_SwitchProxy	 					UMETA(DisplayName = "306 Switch Proxy"),
	VE_TemporaryRedirect		 		UMETA(DisplayName = "307 Temporary Redirect"),
	VE_PermanentRedirect	 			UMETA(DisplayName = "308 Permanent Redirect"),

	VE_BadRequest						UMETA(DisplayName = "400 Bad Request"),
	VE_Unauthorized						UMETA(DisplayName = "401 Unauthorized"),
	VE_PaymentRequired					UMETA(DisplayName = "402 Payment Required"),
	VE_Forbidden						UMETA(DisplayName = "403 Forbidden"),
	VE_NotFound							UMETA(DisplayName = "404 Not Found"),
	VE_MethodNotAllowed					UMETA(DisplayName = "405 Method Not Allowed"),
	VE_NotAcceptable					UMETA(DisplayName = "406 Not Acceptable"),
	VE_ProxyAuthenticationRequired		UMETA(DisplayName = "407 Proxy Authentication Required"),
	VE_RequestTimeout					UMETA(DisplayName = "408 Request Timeout"),
	VE_Conflict							UMETA(DisplayName = "409 Conflict"),
	VE_Gone								UMETA(DisplayName = "410 Gone"),
	VE_LengthRequired					UMETA(DisplayName = "411 Length Required"),
	VE_PreconditionFailed				UMETA(DisplayName = "412 Precondition Failed"),
	VE_PayloadTooLarge					UMETA(DisplayName = "413 Payload Too Large"),
	VE_UriTooLong						UMETA(DisplayName = "414 URI Too Long"),
	VE_UnsupportedMediaType				UMETA(DisplayName = "415 Unsupported Media Type"),
	VE_RangeNotSatisfiable				UMETA(DisplayName = "416 Range Not Satisfiable"),
	VE_ExpectationFailed				UMETA(DisplayName = "417 Expectation Failed"),
	VE_ImATeapot						UMETA(DisplayName = "418 I'm a teapot"),
	VE_MisdirectedRequest				UMETA(DisplayName = "421 Misdirected Request"),
	VE_UnprocessableEntity				UMETA(DisplayName = "422 UnprocessableEntity"),
	VE_Locked							UMETA(DisplayName = "423 Locked"),
	VE_Failed							UMETA(DisplayName = "424 Failed"),
	VE_UpgradeRequired					UMETA(DisplayName = "426 Upgrade Required"),
	VE_PreconditionRequired				UMETA(DisplayName = "428 Precondition Required"),
	VE_TooManyRequests					UMETA(DisplayName = "429 Too Many Requests"),
	VE_RequestHeaderFieldsTooLarge		UMETA(DisplayName = "431 Request Header Fields Too Large"),
	VE_UnavailableForLegalReasons		UMETA(DisplayName = "451 UnavailableForLegalReasons"),

	VE_InternalServerError				UMETA(DisplayName = "500 Internal Server Error"),
	VE_NotImplemented					UMETA(DisplayName = "501 Not Implemented"),
	VE_BadGateway						UMETA(DisplayName = "502 Bad Gateway"),
	VE_ServiceUnavailable				UMETA(DisplayName = "503 Service Unavailable"),
	VE_GatewayTimeout					UMETA(DisplayName = "504 Gateway Time-out"),
	VE_HttpVersionNotSupported			UMETA(DisplayName = "505 HTTP Version Not Supported"),
	VE_VariantAlsoNegotiates			UMETA(DisplayName = "506 Variant Also Negotiates"),
	VE_InsufficientStorage				UMETA(DisplayName = "507 Insufficient Storage"),
	VE_LoopDetected						UMETA(DisplayName = "508 Loop Detected"),
	VE_NotExtended						UMETA(DisplayName = "510 Not Extended"),
	VE_NetworkAuthenticationRequired	UMETA(DisplayName = "511 Network Authentication Required")
};

FString HttpStatusCodeToString(const EHttpStatusCode httpStatusCode);
int32 HttpStatusCodeToInt(const EHttpStatusCode httpStatusCode);