// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/TSCMenuController.h"

ATSCMenuController::ATSCMenuController()
{
	//œ‘ æ Û±Í÷∏’Î
	bShowMouseCursor = true;
}

void ATSCMenuController::BeginPlay()
{
	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputMode);
}
