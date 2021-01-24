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
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SAssignNew(MenuWidget, STSCMenuWidget)
					]

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
														SNew(SBox)
                                                            .HeightOverride(60.f)
														    .WidthOverride(150.f)
														    [
																SNew(SButton)
																    .HAlign(HAlign_Center)
														            .VAlign(VAlign_Center)
														            .ButtonStyle(&MenuStyle->TopButtonStyle)
														            .OnClicked(this, &STSCHUDWidget::onPress)
														            [
																		SNew(STextBlock)
																		.TextStyle(&MenuStyle->MyTextStyle)
                                                                        .Text(NSLOCTEXT("TSCMenu", "Battle", "Battle"))
																	]
															]
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
														SNew(SBox)
                                                            .HeightOverride(60.f)
														    .WidthOverride(150.f)
														    [
																SNew(SButton)
																    .HAlign(HAlign_Center)
														            .VAlign(VAlign_Center)
														            .OnClicked(this, &STSCHUDWidget::onPress)
														            .ButtonStyle(&MenuStyle->TopButtonStyle)
														            [
																		SNew(STextBlock)
																		.TextStyle(&MenuStyle->MyTextStyle)
                                                                        .Text(NSLOCTEXT("TSCMenu", "Cooperation", "Cooperation"))
																	]
													
															]
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
														SNew(SBox)
                                                            .HeightOverride(60.f)
														    .WidthOverride(150.f)
														    [
																SNew(SButton)
																    .HAlign(HAlign_Center)
														            .VAlign(VAlign_Center)
														            .OnClicked(this, &STSCHUDWidget::onPress)
														            .ButtonStyle(&MenuStyle->TopButtonStyle)
														            [
																		SNew(STextBlock)
																		.TextStyle(&MenuStyle->MyTextStyle)
                                                                        .Text(NSLOCTEXT("TSCMenu", "Against", "Against"))
																	]
													
															]
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
														SNew(SBox)
                                                            .HeightOverride(60.f)
														    .WidthOverride(150.f)
														    [
																SNew(SButton)
																    .HAlign(HAlign_Center)
														            .VAlign(VAlign_Center)
														            .OnClicked(this, &STSCHUDWidget::onPress)
														            .ButtonStyle(&MenuStyle->TopButtonStyle)
														            [
																		SNew(STextBlock)
																		.TextStyle(&MenuStyle->MyTextStyle)
                                                                        .Text(NSLOCTEXT("TSCMenu", "Custom", "Custom"))
																	]
													
															]
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
														SNew(SBox)
                                                            .HeightOverride(60.f)
														    .WidthOverride(150.f)
														    [
																SNew(SButton)
																    .HAlign(HAlign_Center)
														            .VAlign(VAlign_Center)
														            .OnClicked(this, &STSCHUDWidget::onPress)
														            .ButtonStyle(&MenuStyle->TopButtonStyle)
														            [
																		SNew(STextBlock)
																		.TextStyle(&MenuStyle->MyTextStyle)
                                                                        .Text(NSLOCTEXT("TSCMenu", "Collection", "Collection"))
																	]
													
															]
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
														SNew(SBox)
                                                            .HeightOverride(60.f)
														    .WidthOverride(150.f)
														    [
																SNew(SButton)
																    .HAlign(HAlign_Center)
														            .VAlign(VAlign_Center)
                                                                    .OnClicked(this,&STSCHUDWidget::onPress)
														            .ButtonStyle(&MenuStyle->TopButtonStyle)
														            [
																		SNew(STextBlock)
																		.TextStyle(&MenuStyle->MyTextStyle)
                                                                        .Text(NSLOCTEXT("TSCMenu", "Replay", "Replay"))
																	]
													
															]
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

FReply STSCHUDWidget::onPress()
{

	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Blue, FString("add!"));
	return FReply::Handled();
}

