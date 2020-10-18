// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/STSCMenuWidget.h"
#include "SlateOptMacros.h"
#include <UI/Style/TSCStyle.h>
#include <UI/Style/TSCMenuWidgetStyle.h>
#include <Widgets/Layout/SBox.h>
#include <UI/Widget/STSCMenuItemWidget.h>
#include "Widgets/SBoxPanel.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STSCMenuWidget::Construct(const FArguments& InArgs)
{
	//获取编辑器里的MenuStyle
	MenuStyle = &FTSCStyle::Get().GetWidgetStyle<FTSCMenuStyle>("BP_MenuStyle");
	
	ChildSlot
	[
		SAssignNew(RootSizeBox, SBox)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SImage)
			.Image(&MenuStyle->MenuImage)
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		.Padding(FMargin(0.f, 50.f, 0.f, 0.f))
		[
			SAssignNew(TitileText, STextBlock)
			.Text(NSLOCTEXT("TSCMenu", "Menu", "Menu"))
            .Font(MenuStyle->Font_30)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		.Padding(FMargin(0.f, 100.f, 0.f, 0.f))
		[
			SAssignNew(ContentBox,SVerticalBox)
		]
		]
	];

	RootSizeBox->SetWidthOverride(519.f);
	RootSizeBox->SetHeightOverride(800.f);

	ContentBox->AddSlot()
		[
			SNew(STSCMenuItemWidget)
			.ItemText(NSLOCTEXT("TSCMenu", "StartGame", "StartGame"))
		    .ItemType(EMenuItem::StartGame)
.OnClicked(this,&STSCMenuWidget::OnMenuItemClicked)

		];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void STSCMenuWidget::OnMenuItemClicked(EMenuItem::Type ItemType)
{

}
