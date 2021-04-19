// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include <Data/TSCTypes.h>

/**
 * 
 */
class ATSCMenuGameMode;

UENUM()
enum class ESubMenu : uint8 {
	None,
	Battle,
	Cooperation,
	Against,
	Custom,
	Collection,
	Replay

};

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
	UPROPERTY(EditAnywhere, Category = "Health")
		TSubclassOf<class UUserWidget> HUDWidgetClass;
	UPROPERTY(EditAnywhere, Category = "Health")
		class UUserWidget* CurrentWidget;
	//��ȡMenuStyle
	const struct FTSCMenuStyle* MenuStyle;
	//DPIScaler
	TAttribute<float>UIScaler;
	//�˵�ָ��	
	TSharedPtr<class STSCMenuWidget> MenueWidget;
	//
	bool bIsPress;

};
