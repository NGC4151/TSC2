// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include <Data/TSCTypes.h>

/**
 * 
 */
class ATSCMenuGameMode;

class TSC_API STSCHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STSCHUDWidget)
	{}
	
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FReply onPress();

private:
	//��ȡUIscaler
	float GetUIScaler()const;
	//��ȡ��Ļ�ߴ�
	FVector2D GetViewportSize()const;
	//
	ATSCMenuGameMode* MyGameMode;
	
private:
	//��ȡMenuStyle
	const struct FTSCMenuStyle* MenuStyle;
	//DPIScaler
	TAttribute<float>UIScaler;
	//�˵�ָ��	
	TSharedPtr<class STSCMenuWidget> MenueWidget;

};
