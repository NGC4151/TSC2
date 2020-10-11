// Copyright Epic Games, Inc. All Rights Reserved.

#include "TSC.h"
#include "Modules/ModuleManager.h"
#include"UI/Style/TSCStyle.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FTSCMoudule, TSC, "TSC");

void FTSCMoudule::StartupModule()
{
	//Hot reload hack
	FSlateStyleRegistry::UnRegisterSlateStyle(FTSCStyle::GetStyleSetName());
	FTSCStyle::Initialize();
}

void FTSCMoudule::ShutdownModule()
{
	FTSCStyle::Shutdown();
}




