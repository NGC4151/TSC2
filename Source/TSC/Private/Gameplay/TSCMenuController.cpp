// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/TSCMenuController.h"

ATSCMenuController::ATSCMenuController()
{
	//显示鼠标指针
	bShowMouseCursor = true;
}

void ATSCMenuController::BeginPlay()
{
	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputMode);
}
