// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include <Data/TSCTypes.h>

/**
 * 
 */

class TSC_API STSCHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STSCHUDWidget)
	{}
	
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	//��ȡUIscaler
	float GetUIScaler()const;
	//��ȡ��Ļ�ߴ�
	FVector2D GetViewportSize()const;

	//�󶨵�����MenuItem�ķ���
	void OnMenuItemClicked(EMainMenuItem::Type ItemType);

	void SetLockState(int32 num);

	void InitializedMenu();

	

private:
	UPROPERTY(EditAnywhere, Category = "HUD")
		TSubclassOf<class UUserWidget> BattleWidgetClass;

	UPROPERTY(EditAnywhere, Category = "HUD")
		TSubclassOf<class UUserWidget> CooperationWidgetClass;

	UPROPERTY(EditAnywhere, Category = "HUD")
		TSubclassOf<class UUserWidget> AgainstWidgetClass;

	UPROPERTY(EditAnywhere, Category = "HUD")
		TSubclassOf<class UUserWidget> CustomWidgetClass;

	UPROPERTY(EditAnywhere, Category = "HUD")
		TSubclassOf<class UUserWidget> CollectionWidgetClass;

	UPROPERTY(EditAnywhere, Category = "HUD")
		TSubclassOf<class UUserWidget> ReplayWidgetClass;

	UPROPERTY(EditAnywhere, Category = "HUD")
		TSubclassOf<class UUserWidget> cheatWidgetClass;

	UPROPERTY(EditAnywhere, Category = "HUD")
		class UUserWidget* CurrentWidget;

	UPROPERTY(EditAnywhere, Category = "HUD")
		class UUserWidget* CheatWidgetPtr;
	//��ȡMenuStyle
	const struct FTSCMenuStyle* MenuStyle;
	//DPIScaler
	TAttribute<float>UIScaler;
	//�˵�ָ��	
	TSharedPtr<class STSCMenuWidget> MenueWidget;

	
	bool BattleLock;

	bool CooperationLock;
	
	bool AgainstLock;
	
	bool CustomLock;

	bool CollectionLock;

	bool ReplayLock;

};
