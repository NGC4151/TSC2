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
#include "Widgets/Layout/SBackgroundBlur.h"
#include <UI/Widget/STSCMenuItemWidget.h>
#include <Gameplay/TSCMenuGameMode.h>
#include <Common/TSCHelper.h>
#include <Kismet/GameplayStatics.h>
#include <Blueprint/UserWidget.h>
#include "UObject/ConstructorHelpers.h"
#include <UI/Widget/SMainMenuItemWidget.h>

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STSCHUDWidget::Construct(const FArguments& InArgs)
{
	InitializedMenu();

	ChildSlot
		[
			SNew(SDPIScaler)
			.DPIScale(UIScaler)[
				SNew(SOverlay)

					+ SOverlay::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Top)
					[
						
						SNew(SBox)
                        .HeightOverride(60.f)
						    [
								SNew(SBackgroundBlur)
                                .BlurStrength(5.0f)
					                [
						                SNew(SOverlay)
								           +SOverlay::Slot()
					                        .HAlign(HAlign_Left)
					                        .VAlign(VAlign_Fill)
					                        [
                                                SNew(SImage)
										        .Image(&MenuStyle->StarCraftLogo)
									        ]
				                    
				                            +SOverlay::Slot()
					                        .HAlign(HAlign_Fill)
					                        .VAlign(VAlign_Fill)
                                            .Padding(FMargin(60.f,0.f,0.f,0.f))
					                        [
                                                SNew(SImage)
                                                .Image(&MenuStyle->TitleBackgroundBrush)
									        ]

											+ SOverlay::Slot()
											.HAlign(HAlign_Fill)
											.VAlign(VAlign_Fill)
											.Padding(FMargin(60.f, 0.f, 143.f, 0.f))
											[
												SNew(SHorizontalBox)
												    //1
												    +SHorizontalBox::Slot()
												    .HAlign(HAlign_Fill)
												    .VAlign(VAlign_Fill)
												    .AutoWidth()
												    [
														SNew(SBox)
													    .HeightOverride(60.f)
												        .WidthOverride(2.0f)
												        [
													        SNew(SImage)
													        .Image(&MenuStyle->SpacerImage)
												        ]
													]

											        +SHorizontalBox::Slot()
												    .HAlign(HAlign_Left)
												    .VAlign(VAlign_Fill)
													.AutoWidth()
												    [
														SNew(SMainMenuItemWidget)
														.ItemText(NSLOCTEXT("TSCMenu", "Battle", "Battle"))
														.ItemType(EMainMenuItem::Battle)
														.OnClicked(this, &STSCHUDWidget::OnMenuItemClicked)

													]
													//2
													+SHorizontalBox::Slot()
												    .HAlign(HAlign_Fill)
												    .VAlign(VAlign_Fill)
												    .AutoWidth()
												    [
														SNew(SBox)
														.HeightOverride(60.f)
														.WidthOverride(2.0f)
														[
															SNew(SImage)
															.Image(&MenuStyle->SpacerImage)
														]
													]

											        +SHorizontalBox::Slot()
												    .HAlign(HAlign_Left)
												    .VAlign(VAlign_Fill)
													.AutoWidth()
												    [
														SNew(SMainMenuItemWidget)
														.ItemText(NSLOCTEXT("TSCMenu", "Cooperation", "Cooperation"))
														.ItemType(EMainMenuItem::Cooperation)
														.OnClicked(this, &STSCHUDWidget::OnMenuItemClicked)
													]

													//3
													+SHorizontalBox::Slot()
												    .HAlign(HAlign_Fill)
												    .VAlign(VAlign_Fill)
												    .AutoWidth()
												    [
														SNew(SBox)
														.HeightOverride(60.f)
														.WidthOverride(2.0f)
														[
															SNew(SImage)
															.Image(&MenuStyle->SpacerImage)
														]
													]

											        +SHorizontalBox::Slot()
												    .HAlign(HAlign_Left)
												    .VAlign(VAlign_Fill)
													.AutoWidth()
												    [
														SNew(SMainMenuItemWidget)
														.ItemText(NSLOCTEXT("TSCMenu", "Against", "Against"))
														.ItemType(EMainMenuItem::Against)
														.OnClicked(this, &STSCHUDWidget::OnMenuItemClicked)
														
													]

													//4
													+SHorizontalBox::Slot()
												    .HAlign(HAlign_Fill)
												    .VAlign(VAlign_Fill)
												    .AutoWidth()
												    [
														SNew(SBox)
														.HeightOverride(60.f)
														.WidthOverride(2.0f)
														[
															SNew(SImage)
															.Image(&MenuStyle->SpacerImage)
														]
													]

											        +SHorizontalBox::Slot()
												    .HAlign(HAlign_Left)
												    .VAlign(VAlign_Fill)
													.AutoWidth()
												    [
														SNew(SMainMenuItemWidget)
														.ItemText(NSLOCTEXT("TSCMenu", "Custom", "Custom"))
														.ItemType(EMainMenuItem::Custom)
														.OnClicked(this, &STSCHUDWidget::OnMenuItemClicked)
														
													]

													//5
													+SHorizontalBox::Slot()
												    .HAlign(HAlign_Fill)
												    .VAlign(VAlign_Fill)
												    .AutoWidth()
												    [
														SNew(SBox)
														.HeightOverride(60.f)
														.WidthOverride(2.0f)
														[
															SNew(SImage)
															.Image(&MenuStyle->SpacerImage)
														]
													]

											        +SHorizontalBox::Slot()
												    .HAlign(HAlign_Left)
												    .VAlign(VAlign_Fill)
													.AutoWidth()
												    [
														SNew(SMainMenuItemWidget)
														.ItemText(NSLOCTEXT("TSCMenu", "Collection", "Collection"))
														.ItemType(EMainMenuItem::Collection)
														.OnClicked(this, &STSCHUDWidget::OnMenuItemClicked)												
													]

													//6
													+SHorizontalBox::Slot()
												    .HAlign(HAlign_Fill)
												    .VAlign(VAlign_Fill)
												    .AutoWidth()
												    [
															SNew(SBox)
													    .HeightOverride(60.f)
												        .WidthOverride(2.0f)
												        [
													        SNew(SImage)
													        .Image(&MenuStyle->SpacerImage)
												        ]
													]

											        +SHorizontalBox::Slot()
												    .HAlign(HAlign_Left)
												    .VAlign(VAlign_Fill)
													.AutoWidth()
												    [
														SNew(SMainMenuItemWidget)
														.ItemText(NSLOCTEXT("TSCMenu", "Replay", "Replay"))
														.ItemType(EMainMenuItem::Replay)
														.OnClicked(this, &STSCHUDWidget::OnMenuItemClicked)														
													]

													+SHorizontalBox::Slot()
												    .HAlign(HAlign_Right)
												    .VAlign(VAlign_Fill)
												    .AutoWidth()
												    [
															SNew(SBox)
													    .HeightOverride(60.f)
												        .WidthOverride(2.0f)
												        [
													        SNew(SImage)
													        .Image(&MenuStyle->SpacerImage)
												        ]
													]
																																			
											]

											+ SOverlay::Slot()
												.HAlign(HAlign_Right)
												.VAlign(VAlign_Fill)
												.Padding(FMargin(0.f, 0.f, 25.f, 0))
												[
													
													    SNew(SImage)
													    .Image(&MenuStyle->SpacerImage)
												    
												]

											+ SOverlay::Slot()
												.HAlign(HAlign_Right)
												.VAlign(VAlign_Fill)
												.Padding(FMargin(0.f, 0.f, 121.0f, 0))
												[

													SNew(SImage)
													.Image(&MenuStyle->SpacerImage)

												]

											+ SOverlay::Slot()
												.HAlign(HAlign_Right)
												.VAlign(VAlign_Fill)
												.Padding(FMargin(0.f, 0.f, 140.0f, 0))
												[

													SNew(SImage)
													.Image(&MenuStyle->SpacerImage)

												]

											+ SOverlay::Slot()
												.HAlign(HAlign_Right)
												.VAlign(VAlign_Fill)
												.Padding(FMargin(0.f, 0.f, 124.5f, 0))
												[

													SNew(SBox)
													.HeightOverride(60.f)
                                                    .WidthOverride(15.f)
												[
													SNew(SButton)
													 .HAlign(HAlign_Center)
												     .VAlign(VAlign_Center)                                                            
												     .ButtonStyle(&MenuStyle->TopButtonStyle)

												]

												]
									]
							]
					]


					+ SOverlay::Slot()
						.HAlign(HAlign_Right)
						.VAlign(VAlign_Top)
						.Padding(FMargin(0.f, 5.0f, 36.0f, 0))
						[

							SNew(SBox)
							.HeightOverride(76.f)
						    .WidthOverride(76.f)
						    [
							   SNew(SImage)
							   .Image(&MenuStyle->headeIcon)

						    ]

						]
					
			]
		];

}





END_SLATE_FUNCTION_BUILD_OPTIMIZATION


float STSCHUDWidget::GetUIScaler() const
{
	return GetViewportSize().Y / 1440.f;
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



void STSCHUDWidget::OnMenuItemClicked(EMainMenuItem::Type ItemType)
{
	switch (ItemType)
	{
	case EMainMenuItem::Battle:
		if (!BattleLock)
		{
			if (CurrentWidget)CurrentWidget->RemoveFromViewport();
			CurrentWidget = nullptr;
			if (BattleWidgetClass != nullptr)
			{
				CurrentWidget = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GWorld, 0)->GetWorld(), BattleWidgetClass);

				if (CurrentWidget)
				{
					CurrentWidget->AddToViewport();
					TSSCHelper::Debug(FString("Battle!"), FColor::Yellow, 5.f);
					SetLockState(1);
				}
			}
		}
		else
		{
			TSSCHelper::Debug(FString("Battle had Added!"), FColor::Yellow, 5.f);
		}
		break;
	case EMainMenuItem::Cooperation:
		if (!CooperationLock)
		{
			if (CurrentWidget)CurrentWidget->RemoveFromViewport();
			CurrentWidget = nullptr;
			if (CooperationWidgetClass != nullptr)
			{
				CurrentWidget = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GWorld, 0)->GetWorld(), CooperationWidgetClass);

				if (CurrentWidget)
				{
					CurrentWidget->AddToViewport();
					TSSCHelper::Debug(FString("Cooperation!"), FColor::Yellow, 5.f);
					SetLockState(2);
				}
			}
		}
		else
		{
			TSSCHelper::Debug(FString("Cooperation had Added!"), FColor::Yellow, 5.f);
		}
		break;
	case EMainMenuItem::Against:
		if (!AgainstLock)
		{
			if (CurrentWidget)CurrentWidget->RemoveFromViewport();
			CurrentWidget = nullptr;
			if (AgainstWidgetClass != nullptr)
			{
				CurrentWidget = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GWorld, 0)->GetWorld(), AgainstWidgetClass);

				if (CurrentWidget)
				{
					CurrentWidget->AddToViewport();
					TSSCHelper::Debug(FString("Against!"), FColor::Yellow, 5.f);
					SetLockState(3);
				}
			}
		}
		else
		{
			TSSCHelper::Debug(FString("Against had Added!"), FColor::Yellow, 5.f);
		}
		break;
	case EMainMenuItem::Custom:
		if (!CustomLock)
		{
			if (CurrentWidget)CurrentWidget->RemoveFromViewport();
			CurrentWidget = nullptr;
			if (CustomWidgetClass != nullptr)
			{
				CurrentWidget = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GWorld, 0)->GetWorld(), CustomWidgetClass);

				if (CurrentWidget)
				{
					CurrentWidget->AddToViewport();
					TSSCHelper::Debug(FString("Custom!"), FColor::Yellow, 5.f);
					SetLockState(4);
				}
			}
		}
		else
		{
			TSSCHelper::Debug(FString("Custom had Added!"), FColor::Yellow, 5.f);
		}
		break;
	case EMainMenuItem::Collection:
		if (!CollectionLock)
		{
			if (CurrentWidget)CurrentWidget->RemoveFromViewport();
			CurrentWidget = nullptr;
			if (CollectionWidgetClass != nullptr)
			{
				CurrentWidget = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GWorld, 0)->GetWorld(), CollectionWidgetClass);

				if (CurrentWidget)
				{
					CurrentWidget->AddToViewport();
					TSSCHelper::Debug(FString("Collection!"), FColor::Yellow, 5.f);
					SetLockState(5);
				}
			}
		}
		else
		{
			TSSCHelper::Debug(FString("Collection had Added!"), FColor::Yellow, 5.f);
		}
		break;
	case EMainMenuItem::Replay:
		if (!ReplayLock)
		{
			if (CurrentWidget)CurrentWidget->RemoveFromViewport();
			CurrentWidget = nullptr;
			if (ReplayWidgetClass != nullptr)
			{
				CurrentWidget = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GWorld, 0)->GetWorld(), ReplayWidgetClass);

				if (CurrentWidget)
				{
					CurrentWidget->AddToViewport();
					TSSCHelper::Debug(FString("Replay!"), FColor::Yellow, 5.f);
					SetLockState(6);
				}
			}
		}
		else
		{
			TSSCHelper::Debug(FString("Replay had Added!"), FColor::Yellow, 5.f);
		}
		break;
	}
}

void STSCHUDWidget::SetLockState(int32 num)
{
	switch (num)
	{
	case 1:
		BattleLock = true;
		CooperationLock = false;
		AgainstLock = false;
		CustomLock = false;
		CollectionLock = false;
		ReplayLock = false;
		break;
	case 2:
		BattleLock = false;
		CooperationLock = true;
		AgainstLock = false;
		CustomLock = false;
		CollectionLock = false;
		ReplayLock = false;
		break;
	case 3:
		BattleLock = false;
		CooperationLock = false;
		AgainstLock = true;
		CustomLock = false;
		CollectionLock = false;
		ReplayLock = false;
		break;
	case 4:
		BattleLock = false;
		CooperationLock = false;
		AgainstLock = false;
		CustomLock = true;
		CollectionLock = false;
		ReplayLock = false;
		break;
	case 5:
		BattleLock = false;
		CooperationLock = false;
		AgainstLock = false;
		CustomLock = false;
		CollectionLock = true;
		ReplayLock = false;
		break;
	case 6:
		BattleLock = false;
		CooperationLock = false;
		AgainstLock = true;
		CustomLock = false;
		CollectionLock = false;
		ReplayLock = true;
		break;
	}
}

void STSCHUDWidget::InitializedMenu()
{
	//绑定UIScaler到GetUIscaler函数
	UIScaler.Bind(this, &STSCHUDWidget::GetUIScaler);
	//获取Content对应目录下的BP_MenuStyle
	MenuStyle = &FTSCStyle::Get().GetWidgetStyle<FTSCMenuStyle>("BP_MenuStyle");

	static ConstructorHelpers::FClassFinder<UUserWidget> BattleObj(TEXT("/Game/UI/Battle"));
	BattleWidgetClass = BattleObj.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget> CooperationObj(TEXT("/Game/UI/Cooperation"));
	CooperationWidgetClass = CooperationObj.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget> AgainstObj(TEXT("/Game/UI/Against"));
	AgainstWidgetClass = AgainstObj.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget> CustomObj(TEXT("/Game/UI/Custom"));
	CustomWidgetClass = CustomObj.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget> CollectionObj(TEXT("/Game/UI/Collection"));
	CollectionWidgetClass = CollectionObj.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget>ReplayObj(TEXT("/Game/UI/Replay"));
	ReplayWidgetClass = ReplayObj.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget>CheatObj(TEXT("/Game/UI/Cheat"));
	cheatWidgetClass = CheatObj.Class;

	if (cheatWidgetClass!=nullptr)
	{
		CheatWidgetPtr= CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GWorld, 0)->GetWorld(), cheatWidgetClass);

		if (CheatWidgetPtr)
		{
			CheatWidgetPtr->AddToViewport();
		}
	}


	CurrentWidget = nullptr;

	BattleLock = false;
	CooperationLock = false;
	AgainstLock = false;
	CustomLock = false;
	CollectionLock = false;
	ReplayLock = false;

	//UGameplayStatics::OpenLevel(UGameplayStatics::GetPlayerController(GWorld, 0)->GetWorld(), FName("mymap"));
}


