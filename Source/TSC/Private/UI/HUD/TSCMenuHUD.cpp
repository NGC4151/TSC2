// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/TSCMenuHUD.h"
#include "UI/Widget/STSCHUDWidget.h"
#include "SlateBasics.h"

ATSCMenuHUD::ATSCMenuHUD()
{
	//���widget���ӿ�
	if (GEngine&&GEngine->GameViewport)
	{
		SAssignNew(MenuHUDWidget, STSCHUDWidget);
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MenuHUDWidget.ToSharedRef()));
	}
}
