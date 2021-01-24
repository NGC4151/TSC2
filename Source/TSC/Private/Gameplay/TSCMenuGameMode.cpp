// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/TSCMenuGameMode.h"
#include"UI/HUD/TSCMenuHUD.h"
#include "Gameplay/TSCMenuController.h"

ATSCMenuGameMode::ATSCMenuGameMode()
{
	//在game mode中指定玩家控制类和HUD类
	PlayerControllerClass = ATSCMenuController::StaticClass();
	HUDClass = ATSCMenuHUD::StaticClass();
}

void ATSCMenuGameMode::BeginPlay()
{
	Super::BeginPlay();

	//addui();
}

FReply ATSCMenuGameMode::onPressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Blue, FString("add!"));

	return FReply::Handled();

}

