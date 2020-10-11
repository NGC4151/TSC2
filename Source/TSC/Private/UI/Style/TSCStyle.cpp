// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Style/TSCStyle.h"
#include "Slate/SlateGameResources.h"

TSharedPtr<FSlateStyleSet> FTSCStyle::MenuStyleInstance = NULL;

void FTSCStyle::Initialize()
{
	if (!MenuStyleInstance.IsValid())
	{
		MenuStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*MenuStyleInstance);
	}
}

void FTSCStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*MenuStyleInstance);
	ensure(MenuStyleInstance.IsUnique());
	MenuStyleInstance.Reset();
}

FName FTSCStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MenuStyles"));
	return StyleSetName;
}

TSharedRef<FSlateStyleSet> FTSCStyle::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FTSCStyle::GetStyleSetName(), "/Game/UI/Style", "/Game/UI/Style");
	return StyleRef;
}

const ISlateStyle& FTSCStyle::Get()
{
	return *MenuStyleInstance;
}