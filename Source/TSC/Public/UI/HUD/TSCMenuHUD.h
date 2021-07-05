// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TSCMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class TSC_API ATSCMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATSCMenuHUD();

	TSharedPtr<class STSCHUDWidget>MenuHUDWidget;

};
