// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/TSCMenuGameMode.h"
#include"UI/HUD/TSCMenuHUD.h"
#include "Gameplay/TSCMenuController.h"

ATSCMenuGameMode::ATSCMenuGameMode()
{
	//在game mode构造函数里指定控制器、hud等
	PlayerControllerClass = ATSCMenuController::StaticClass();
	HUDClass = ATSCMenuHUD::StaticClass();
}
