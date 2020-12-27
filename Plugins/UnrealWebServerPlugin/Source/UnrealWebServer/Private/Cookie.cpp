// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#include "Cookie.h"

#include "UnrealWebServerPrivatePCH.h"

UCookie* UCookie::ConstructCookie(UObject* WorldContextObject)
{
	return NewObject<UCookie>();
}

UCookie* UCookie::ConstructCookieExt(UObject* WorldContextObject, const FString& Name, const FString& Value)
{
	UCookie* cookie = ConstructCookie(WorldContextObject);
	cookie->Name = Name;
	cookie->Value = Value;
	return cookie;
}

FString UCookie::ToString() const
{
	FString ret = "";
	ret += "Set-Cookie: ";
	ret += Name + "=" + Value;
	if (MaxAge != 0)
		ret += FString::Printf(TEXT("; Max-Age=%d"), MaxAge);
	if (Domain != "")
		ret += "; Domain=" + Domain;
	if (Path != "")
		ret += "; Path=" + Path;
	if (HttpOnly)
		ret += "; HttpOnly";
	if (Secure)
		ret += "; Secure";

	return ret;
}

bool UCookie::operator==(const UCookie& lhs) const
{
	return lhs.Name == Name
		&& lhs.Value == Value
		&& lhs.MaxAge == MaxAge
		&& lhs.Domain == Domain
		&& lhs.Path == Path
		&& lhs.HttpOnly == HttpOnly
		&& lhs.Secure == Secure;
}
