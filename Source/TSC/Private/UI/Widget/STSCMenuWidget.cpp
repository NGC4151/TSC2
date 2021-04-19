// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/STSCMenuWidget.h"
#include "SlateOptMacros.h"
#include <UI/Style/TSCStyle.h>
#include <UI/Style/TSCMenuWidgetStyle.h>
#include <Widgets/Layout/SBox.h>
#include <UI/Widget/STSCMenuItemWidget.h>
#include "Widgets/SBoxPanel.h"
#include "UI/Widget/STSCGameOptionWidget.h"
#include <Common/TSCHelper.h>
#include "Widgets/Images/SImage.h"
#include <Data/TSCDataHandle.h>
#include <UI/Widget/STSCNewGameWidget.h>
#include <UI/Widget/STSCChooseSaveDataWidget.h>


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
			SNew(STSCChooseSaveDataWidget)
			/*
			SNew(STSCGameOptionWidget)
			.ChangeLanguage(this, &STSCMenuWidget::ChangeLanguage)
		    .ChangeVolume(this, &STSCMenuWidget::ChangeVolume)
			*/
		];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void STSCMenuWidget::OnMenuItemClicked(EMenuItem::Type ItemType)
{
	TSSCHelper::Debug(FString("Button Pressed!"),FColor::Yellow,5.0f);
}

void STSCMenuWidget::ChangeLanguage(ECultrueTeam Culture)
{
	//
	TSCDataHandle::Get()->ChangeLanguage(Culture);
}

void STSCMenuWidget::ChangeVolume(const float MusicVol, const float SoundVol)
{
	TSCDataHandle::Get()->SetVolume(MusicVol, SoundVol);
}

/*
UE_LOG(LogTemp, Warning, TEXT("Button Had Preesed!"));

// UE_LOG message with arguments
int intVar = 5;
float floatVar = 3.7f;
FString fstringVar = "an fstring variable";
UE_LOG(LogTemp, Warning, TEXT("Text, %d %f %s"), intVar, floatVar, *fstringVar);

//格式化字符串
FString name = "Tim";
int32 mana = 450;
TArray< FStringFormatArg > args;
args.Add(FStringFormatArg(name));
args.Add(FStringFormatArg(mana));
FString string = FString::Format(TEXT("Name = {0} Mana ={1}"), args);

UE_LOG(LogTemp, Warning, TEXT("Your string: %s"), *string);
*/
