// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/TSCMenuGameMode.h"
#include"UI/HUD/TSCMenuHUD.h"
#include "Gameplay/TSCMenuController.h"

ATSCMenuGameMode::ATSCMenuGameMode()
{
	//��game mode���캯����ָ����������hud��
	PlayerControllerClass = ATSCMenuController::StaticClass();
	HUDClass = ATSCMenuHUD::StaticClass();
}
