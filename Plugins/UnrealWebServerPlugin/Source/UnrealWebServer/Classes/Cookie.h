// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#pragma once

#include "Cookie.generated.h"

/**
* An UCookie can store all informations about HTTP cookies
* This UCookie can be used to fulfill an UResponse
* @see UResponse
* @author Isara Technologies.
* @version 1.0
*/
UCLASS(BlueprintType)

class UNREALWEBSERVER_API UCookie : public UObject
{
	GENERATED_BODY()
public:

	/**
	 * Constructs a new empty cookie
	 * @param WorldContextObject autofilled param from Unreal
	 */
	UFUNCTION(BlueprintPure, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "UnrealWebServer")
	static UCookie* ConstructCookie(UObject* WorldContextObject);

	/**
	* Constructs a new cookie with a defined name and value
	* @param WorldContextObject autofilled param from Unreal
	* @param Name the cookie name
	* @param Value the cookie value
	*/
	UFUNCTION(BlueprintPure, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "UnrealWebServer")
	static UCookie* ConstructCookieExt(UObject* WorldContextObject, const FString& Name, const FString& Value);

	/**
	 * Sets the name of the cookie
	 * @param name the cookie name
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")

	void SetName(const FString& name)
	{
		Name = name;
	}

	/**
	 * Sets the value of the cookie
	 * @param value the cookie value
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")

	void SetValue(const FString& value)
	{
		Value = value;
	}

	/**
	 * Sets the max age of the cookie
	 * @param max_age the max age of the cookie
	 */
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")

	void SetMaxAge(int32 max_age)
	{
		MaxAge = max_age;
	}

	/**
	* Sets the domain of the cookie
	* @param domain the max age of the cookie
	*/
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")

	void SetDomain(const FString& domain)
	{
		Domain = domain;
	}

	/**
	* Sets the path of the cookie
	* @param path the max age of the cookie
	*/
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")

	void SetPath(const FString& path)
	{
		Path = path;
	}

	/**
	* Sets if the cookie is HTTP ONLY or not
	* @param http_only is the cookie http_only ?
	*/
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")

	void SetHttpOnly(bool http_only)
	{
		HttpOnly = http_only;
	}

	/**
	* Sets if the cookie is SECURE or not
	* @param secure is the cookie secure ?
	*/
	UFUNCTION(BlueprintCallable, Category = "UnrealWebServer")

	void SetSecure(bool secure)
	{
		Secure = secure;
	}

	FString ToString() const;

	bool operator==(const UCookie& lhs) const;

private:

	FString Name;
	FString Value;
	int32 MaxAge;
	FString Domain;
	FString Path;
	bool HttpOnly;
	bool Secure;
};
