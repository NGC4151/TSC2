// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Style/TSCMenuWidgetStyle.h"

FTSCMenuStyle::FTSCMenuStyle()
{
}

FTSCMenuStyle::~FTSCMenuStyle()
{
}

const FName FTSCMenuStyle::TypeName(TEXT("FTSCMenuStyle"));

const FTSCMenuStyle& FTSCMenuStyle::GetDefault()
{
	static FTSCMenuStyle Default;
	return Default;
}

void FTSCMenuStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

