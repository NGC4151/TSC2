// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/STSCHUDWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Images/SImage.h"
#include "UI/Style/TSCMenuWidgetStyle.h"
#include "UI/Style/TSCStyle.h"
#include <Widgets/SOverlay.h>
#include <Engine/Engine.h>
#include <Widgets/Layout/SDPIScaler.h>
#include <UI/Widget/STSCMenuWidget.h>

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STSCHUDWidget::Construct(const FArguments& InArgs)
{
	//绑定UIScaler到GetUIscaler函数
	UIScaler.Bind(this, &STSCHUDWidget::GetUIScaler);
	//获取Content对应目录下的BP_MenuStyle
	MenuStyle = &FTSCStyle::Get().GetWidgetStyle<FTSCMenuStyle>("BP_MenuStyle");

	
	ChildSlot
		[
			SNew(SDPIScaler)
			.DPIScale(UIScaler)[
				SNew(SOverlay)
					+ SOverlay::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					[
						SNew(SImage)
						.Image(&MenuStyle->MenuBackgroundBrush)

					]
				+ SOverlay::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SAssignNew(MenuWidget,STSCMenuWidget)

					]

			]


		];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

float STSCHUDWidget::GetUIScaler() const
{
	return GetViewportSize().Y / 1080.f;
}

FVector2D STSCHUDWidget::GetViewportSize() const
{
	//默认的屏幕分辨率
	FVector2D Result(1920, 1080);
	//将实际的屏幕的分辨率存至Result
	if (GEngine && GEngine->GameViewport)
		GEngine->GameViewport->GetViewportSize(Result);

	return Result;
	
}

