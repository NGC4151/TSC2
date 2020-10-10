// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TSCMenuController.generated.h"

/**
 * 
 */
UCLASS()
class TSC_API ATSCMenuController : public APlayerController
{
	GENERATED_BODY()

public:
	ATSCMenuController();
protected:
	virtual void BeginPlay() override;
	
};
