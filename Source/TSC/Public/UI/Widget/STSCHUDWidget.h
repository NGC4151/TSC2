// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

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

private:
	//��ȡMenuStyle
	const struct FTSCMenuStyle* MenuStyle;
	//DPIScaler
	TAttribute<float>UIScaler;
	//�˵�ָ��
	TSharedPtr<class STSCMenuWidget>MenuWidget;
};
