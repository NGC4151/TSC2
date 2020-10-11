// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/STSCHUDWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Images/SImage.h"
#include "UI/Style/TSCMenuWidgetStyle.h"
#include "UI/Style/TSCStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STSCHUDWidget::Construct(const FArguments& InArgs)
{
	//获取编辑器里的MenuStyle
	MenuStyle = &FTSCStyle::Get().GetWidgetStyle<FTSCMenuStyle>("bp");

	
	ChildSlot
		[
			SNew(SImage)
			.Image(&MenuStyle->MenuBackgroundBrush)
		];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION


