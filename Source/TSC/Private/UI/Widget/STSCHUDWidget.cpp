// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/STSCHUDWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Input/SButton.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STSCHUDWidget::Construct(const FArguments& InArgs)
{
	
	ChildSlot
		[
			SNew(SButton)
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION


