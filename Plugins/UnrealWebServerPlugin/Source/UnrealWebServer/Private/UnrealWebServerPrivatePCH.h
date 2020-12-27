// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#pragma once

#include "Runtime/Launch/Resources/Version.h"

#if ENGINE_MINOR_VERSION >= 15
#include "CoreMinimal.h"
#include "EngineDefines.h"
#include "Engine/Engine.h"
#include "UObject/Object.h"
#include "UObject/ScriptMacros.h"
#else
#include "CoreUObject.h"
#include "Engine.h"
#endif

#include "Engine.h"
#if ENGINE_MINOR_VERSION < 22
#include "RunnableThread.h"		// This was OK before 4.22
#else
#include "HAL/RunnableThread.h"
#endif

#include <string>
#include <map>
#include <ctime>
#include <process.h>
#include <iostream>
#include <string>
#include <map>
#include <sstream>

#include "mongoose.h"
#include "WebServer.h"
#include "HttpRequestMethod.h"
#include "HttpStatusCode.h"
#include "MediaType.h"
#include "Connection.h"

DECLARE_LOG_CATEGORY_EXTERN(UnrealWebServer, Log, All);
#include "Engine.h"
#if ENGINE_MINOR_VERSION < 22
#include "ModuleManager.h"		// This was OK before 4.22
#else
#include "Modules/ModuleManager.h"
#endif
