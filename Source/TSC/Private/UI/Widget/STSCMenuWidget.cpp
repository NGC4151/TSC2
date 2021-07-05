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

//�˵��ṹ��
struct MenuGroup 
{
	//�˵�����
	FText MenuName;
	//�˵��߶�
	float MenuHeight;
	//�������
	TArray<TSharedPtr<SCompoundWidget>>ChidWidget;
	//���캯��
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
	//��ȡ�༭�����MenuStyle
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
		//������ڲ���
		if (MenuAnimation.IsPlaying())
		{
			//ʵʱ�޸Ĳ˵���С
			ResetWidgetSize(MenuAnimationCurve.GetLerp() * 600.f, -1.f);
			//�����߲��ŵ�40��ʱ�������
			if (MenuAnimationCurve.GetLerp() < 0.6f && bIsMenuShow)ShowWidget(EMenuType::None);
		}
		else {
			//�رն�����ɣ����ö���״̬Ϊ��
			AnimState = EMenuAnim::Open;
			//��ʼ���Ŵ򿪶���
			MenuAnimation.Play(this->AsShared());
		}
		break;
	case EMenuAnim::Open:
		//������ڲ���
		if (MenuAnimation.IsPlaying())
		{
			//ʵʱ�޸Ĳ˵���С
			ResetWidgetSize(MenuAnimationCurve.GetLerp() * 600.f, CurrentHeight);
			//�����߲��ŵ�60��ʱ��ʾ���
			if (MenuAnimationCurve.GetLerp() > 0.6f && !bIsMenuShow)ShowWidget(CurrentMenu);
		}
		//����������
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

	//ʵ����������
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
	//ʵ������������������ť������ӽ�MenuMap��
	MenuMap.Add(EMenuType::MainMenu, MakeShareable(new MenuGroup(NSLOCTEXT("TSCMenu", "Menu", "Menu"), 510.0f, &MainMenuList)));

	//ʵ������ʼ��Ϸ����
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
	//ʵ������������������ť������ӽ�MenuMap��
	MenuMap.Add(EMenuType::StartGame, MakeShareable(new MenuGroup(NSLOCTEXT("TSCMenu", "StartGame", "StartGame"), 510.0f, &StartGamelist)));

	//ʵ������Ϸ���ý���
	TArray<TSharedPtr<SCompoundWidget>>GameOptionList;
	//ʵ������Ϸ���ÿؼ�
	SAssignNew(GameOptionWidget, STSCGameOptionWidget)
		.ChangeLanguage(this, &STSCMenuWidget::ChangeLanguage)
		.ChangeVolume(this, &STSCMenuWidget::ChangeVolume);
	//��ӿؼ�������
	GameOptionList.Add(GameOptionWidget);
	GameOptionList.Add(SNew(STSCMenuItemWidget)
		.ItemText(NSLOCTEXT("TSCMenu", "ReturnGame", "ReturnGame"))
		.ItemType(EMenuItem::GameOptionGoBack)
		.OnClicked(this, &STSCMenuWidget::OnMenuItemClicked));

	MenuMap.Add(EMenuType::GameOption, MakeShareable(new MenuGroup(NSLOCTEXT("TSCMenu", "Option", "Option"), 610.0f, &GameOptionList)));

	//ʵ������ʼ����Ϸ����
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

	//ʵ����ѡ��浵����
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
	//���Ƴ���������Ŀؼ�
	ContentBox->ClearChildren();
	//���EMenuType��None����
	if (WidgetType == EMenuType::None)return;
	//ѭ��������
	for (TArray<TSharedPtr<SCompoundWidget>>::TIterator It((*MenuMap.Find(WidgetType))->ChidWidget);It;++It)
	{
		ContentBox->AddSlot().AutoHeight()[(*It)->AsShared()];
	}
	//���ı���
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
	//���������ӳ�
	const float StartDelay = 0.3f;
	//����ʱ��
	const float AnimDuration = 0.6f;

	MenuAnimation = FCurveSequence();
	MenuAnimationCurve = MenuAnimation.AddCurve(StartDelay, AnimDuration, ECurveEaseFunction::QuadInOut);
	//���ò˵��ĳ�ʼ��С
	ResetWidgetSize(600.f, 510.f);
	//����Ĭ����ʾ�Ĳ˵�
	ShowWidget(EMenuType::MainMenu);
	//��������ť
	bIsLockButton = false;
	//���ó�ʼ����״̬
	AnimState=EMenuAnim::Stop;
	//���ö���������������β
	MenuAnimation.JumpToEnd();
}

void STSCMenuWidget::PlayAnim(EMenuType::Type NewMenu)
{
	//�����µĽ���
	CurrentMenu = NewMenu;
	//�����¸߶�
	CurrentHeight = (*MenuMap.Find(NewMenu))->MenuHeight;
	//���ö���״̬Ϊstop
	AnimState = EMenuAnim::Close;
	//���ŷ��򶯻�
	MenuAnimation.PlayReverse(this->AsShared());
}

