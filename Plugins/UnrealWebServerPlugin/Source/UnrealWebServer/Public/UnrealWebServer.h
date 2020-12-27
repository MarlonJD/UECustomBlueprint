// Copyright (c) 2017 Isara Technologies. All Rights Reserved.

#pragma once

#include "Engine.h"
#if ENGINE_MINOR_VERSION < 22
#include "ModuleManager.h"		// This was OK before 4.22
#else
#include "Modules/ModuleManager.h"
#endif

class FUnrealWebServerModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};