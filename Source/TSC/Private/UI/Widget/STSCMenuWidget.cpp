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

//菜单结构体
struct MenuGroup 
{
	//菜单标题
	FText MenuName;
	//菜单高度
	float MenuHeight;
	//下属组件
	TArray<TSharedPtr<SCompoundWidget>>ChidWidget;
	//构造函数
	MenuGroup(const FText Name, const float Height, TArray<TSharedPtr<SCompoundWidget>>* ChidWid) 
	{
		MenuName = Name;
		MenuHeight = Height;
		for (TArray<TSharedPtr<SCompoundWidget>>::TIterator It(*ChidWid);It;++It)
		{
			ChidWidget.Add(*It);
		}
	}
};


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

	
	InitializedMenuList();

	InitializedAnimation();
	
}

void STSCMenuWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	switch (AnimState)
	{
	case EMenuAnim::Stop:
		break;
	case EMenuAnim::Close:
		//如果正在播放
		if (MenuAnimation.IsPlaying())
		{
			//实时修改菜单大小
			ResetWidgetSize(MenuAnimationCurve.GetLerp() * 600.f, -1.f);
			//在曲线播放到40％时销毁组件
			if (MenuAnimationCurve.GetLerp() < 0.6f && bIsMenuShow)ShowWidget(EMenuType::None);
		}
		else {
			//关闭动画完成，设置动画状态为打开
			AnimState = EMenuAnim::Open;
			//开始播放打开动画
			MenuAnimation.Play(this->AsShared());
		}
		break;
	case EMenuAnim::Open:
		//如果正在播放
		if (MenuAnimation.IsPlaying())
		{
			//实时修改菜单大小
			ResetWidgetSize(MenuAnimationCurve.GetLerp() * 600.f, CurrentHeight);
			//在曲线播放到60％时显示组件
			if (MenuAnimationCurve.GetLerp() > 0.6f && !bIsMenuShow)ShowWidget(CurrentMenu);
		}
		//如果播放完毕
		if (MenuAnimation.IsAtEnd())
		{
			AnimState = EMenuAnim::Stop;
			bIsLockButton = false;
		}
		break;
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void STSCMenuWidget::OnMenuItemClicked(EMenuItem::Type ItemType)
{
	if (bIsLockButton)return;
	bIsLockButton = true;

	switch (ItemType)
	{
	case EMenuItem::StartGame:
		PlayAnim(EMenuType::StartGame);
		break;
	case EMenuItem::GameOption:
		PlayAnim(EMenuType::GameOption);
		break;
	case EMenuItem::QuitGame:
		TSSCHelper::Debug(FString("QuitGame!"), FColor::Yellow, 5.f);
		bIsLockButton = false;
		break;
	case EMenuItem::NewGame:
		PlayAnim(EMenuType::NewGame);
		break;
	case EMenuItem::LoadSaveData:
		PlayAnim(EMenuType::ChooseSavaData);
		break;
	case EMenuItem::ReturnGame:
		PlayAnim(EMenuType::MainMenu);
		break;
	case EMenuItem::GameOptionGoBack:
		PlayAnim(EMenuType::MainMenu);
		break;
	case EMenuItem::NewGameGoBack:
		PlayAnim(EMenuType::StartGame);
		break;
	case EMenuItem::ChooseGoBack:
		PlayAnim(EMenuType::StartGame);
		break;
	case EMenuItem::EnterGame:
		TSSCHelper::Debug(FString("enter game!"), FColor::Yellow, 5.f);
		bIsLockButton = false;
		break;
	case EMenuItem::EnterSaveData:
		TSSCHelper::Debug(FString("EnterSaveData!"), FColor::Yellow, 5.f);
		bIsLockButton = false;
		break;
	}
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

void STSCMenuWidget::InitializedMenuList()
{

	//实例化主界面
	TArray<TSharedPtr<SCompoundWidget>>MainMenuList;
	MainMenuList.Add(SNew(STSCMenuItemWidget)
	.ItemText(NSLOCTEXT("TSCMenu", "StartGame", "StartGame"))
	.ItemType(EMenuItem::StartGame)
	.OnClicked(this, &STSCMenuWidget::OnMenuItemClicked));

	MainMenuList.Add(SNew(STSCMenuItemWidget)
		.ItemText(NSLOCTEXT("TSCMenu", "Option", "Option"))
		.ItemType(EMenuItem::GameOption)
		.OnClicked(this, &STSCMenuWidget::OnMenuItemClicked));

	MainMenuList.Add(SNew(STSCMenuItemWidget)
		.ItemText(NSLOCTEXT("TSCMenu", "Exit", "Exit"))
		.ItemType(EMenuItem::QuitGame)
		.OnClicked(this, &STSCMenuWidget::OnMenuItemClicked));
	//实例化出主界面三个按钮后将其添加进MenuMap中
	MenuMap.Add(EMenuType::MainMenu, MakeShareable(new MenuGroup(NSLOCTEXT("TSCMenu", "Menu", "Menu"), 510.0f, &MainMenuList)));

	//实例化开始游戏界面
	TArray<TSharedPtr<SCompoundWidget>>StartGamelist;
	StartGamelist.Add(SNew(STSCMenuItemWidget)
		.ItemText(NSLOCTEXT("TSCMenu", "NewGame", "NewGame"))
		.ItemType(EMenuItem::NewGame)
		.OnClicked(this, &STSCMenuWidget::OnMenuItemClicked));

	StartGamelist.Add(SNew(STSCMenuItemWidget)
		.ItemText(NSLOCTEXT("TSCMenu", "LoadSave", "LoadSave"))
		.ItemType(EMenuItem::LoadSaveData)
		.OnClicked(this, &STSCMenuWidget::OnMenuItemClicked));

	StartGamelist.Add(SNew(STSCMenuItemWidget)
		.ItemText(NSLOCTEXT("TSCMenu", "ReturnGame", "ReturnGame"))
		.ItemType(EMenuItem::ReturnGame)
		.OnClicked(this, &STSCMenuWidget::OnMenuItemClicked));
	//实例化出主界面三个按钮后将其添加进MenuMap中
	MenuMap.Add(EMenuType::StartGame, MakeShareable(new MenuGroup(NSLOCTEXT("TSCMenu", "StartGame", "StartGame"), 510.0f, &StartGamelist)));

	//实例化游戏设置界面
	TArray<TSharedPtr<SCompoundWidget>>GameOptionList;
	//实例化游戏设置控件
	SAssignNew(GameOptionWidget, STSCGameOptionWidget)
		.ChangeLanguage(this, &STSCMenuWidget::ChangeLanguage)
		.ChangeVolume(this, &STSCMenuWidget::ChangeVolume);
	//添加控件到数组
	GameOptionList.Add(GameOptionWidget);
	GameOptionList.Add(SNew(STSCMenuItemWidget)
		.ItemText(NSLOCTEXT("TSCMenu", "ReturnGame", "ReturnGame"))
		.ItemType(EMenuItem::GameOptionGoBack)
		.OnClicked(this, &STSCMenuWidget::OnMenuItemClicked));

	MenuMap.Add(EMenuType::GameOption, MakeShareable(new MenuGroup(NSLOCTEXT("TSCMenu", "Option", "Option"), 610.0f, &GameOptionList)));

	//实例化开始新游戏界面
	TArray<TSharedPtr<SCompoundWidget>>NewGameList;
	SAssignNew(NewGameWidget, STSCNewGameWidget);
	NewGameList.Add(NewGameWidget);
	NewGameList.Add(SNew(STSCMenuItemWidget)
		.ItemText(NSLOCTEXT("TSCMenu", "EnterGame", "EnterGame"))
		.ItemType(EMenuItem::EnterGame)
		.OnClicked(this, &STSCMenuWidget::OnMenuItemClicked));
	NewGameList.Add(SNew(STSCMenuItemWidget)
		.ItemText(NSLOCTEXT("TSCMenu", "ReturnGame", "ReturnGame"))
		.ItemType(EMenuItem::NewGameGoBack)
		.OnClicked(this, &STSCMenuWidget::OnMenuItemClicked));

	MenuMap.Add(EMenuType::NewGame, MakeShareable(new MenuGroup(NSLOCTEXT("TSCMenu", "NewGame", "NewGame"), 510.0f, &NewGameList)));

	//实例化选择存档界面
	TArray<TSharedPtr<SCompoundWidget>>ChooseSaveDataList;
	SAssignNew(ChooseSaveDataWidget, STSCChooseSaveDataWidget);
	ChooseSaveDataList.Add(ChooseSaveDataWidget);
	ChooseSaveDataList.Add(SNew(STSCMenuItemWidget)
		.ItemText(NSLOCTEXT("TSCMenu", "EnterSaveData", "EnterSaveData"))
		.ItemType(EMenuItem::EnterSaveData)
		.OnClicked(this, &STSCMenuWidget::OnMenuItemClicked));
	ChooseSaveDataList.Add(SNew(STSCMenuItemWidget)
		.ItemText(NSLOCTEXT("TSCMenu", "ReturnGame", "ReturnGame"))
		.ItemType(EMenuItem::ChooseGoBack)
		.OnClicked(this, &STSCMenuWidget::OnMenuItemClicked));

	MenuMap.Add(EMenuType::ChooseSavaData, MakeShareable(new MenuGroup(NSLOCTEXT("TSCMenu", "LoadSave", "LoadSave"), 510.0f, &ChooseSaveDataList)));

	

}

void STSCMenuWidget::ShowWidget(EMenuType::Type WidgetType)
{
	bIsMenuShow = WidgetType != EMenuType::None;
	//先移除所有里面的控件
	ContentBox->ClearChildren();
	//如果EMenuType是None跳出
	if (WidgetType == EMenuType::None)return;
	//循环添加组件
	for (TArray<TSharedPtr<SCompoundWidget>>::TIterator It((*MenuMap.Find(WidgetType))->ChidWidget);It;++It)
	{
		ContentBox->AddSlot().AutoHeight()[(*It)->AsShared()];
	}
	//更改标题
	TitileText->SetText((*MenuMap.Find(WidgetType))->MenuName);
	
}

void STSCMenuWidget::ResetWidgetSize(float NewWidth, float NewHeight)
{
	RootSizeBox->SetWidthOverride(NewWidth);
	if (NewHeight < 0)return;
	RootSizeBox->SetWidthOverride(NewHeight);
}

void STSCMenuWidget::InitializedAnimation()
{
	//动画播放延迟
	const float StartDelay = 0.3f;
	//动画时长
	const float AnimDuration = 0.6f;

	MenuAnimation = FCurveSequence();
	MenuAnimationCurve = MenuAnimation.AddCurve(StartDelay, AnimDuration, ECurveEaseFunction::QuadInOut);
	//设置菜单的初始大小
	ResetWidgetSize(600.f, 510.f);
	//设置默认显示的菜单
	ShowWidget(EMenuType::MainMenu);
	//允许点击按钮
	bIsLockButton = false;
	//设置初始动画状态
	AnimState=EMenuAnim::Stop;
	//设置动画播放器跳至结尾
	MenuAnimation.JumpToEnd();
}

void STSCMenuWidget::PlayAnim(EMenuType::Type NewMenu)
{
	//设置新的界面
	CurrentMenu = NewMenu;
	//设置新高度
	CurrentHeight = (*MenuMap.Find(NewMenu))->MenuHeight;
	//设置动画状态为stop
	AnimState = EMenuAnim::Close;
	//播放反向动画
	MenuAnimation.PlayReverse(this->AsShared());
}

