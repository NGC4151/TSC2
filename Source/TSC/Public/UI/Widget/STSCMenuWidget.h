// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include <Data/TSCTypes.h>


class SBox;
class STextBlock;
class SVerticalBox;
struct MenuGroup;
class STSCGameOptionWidget;
class STSCNewGameWidget;
class STSCChooseSaveDataWidget;

/**
 * 
 */
class TSC_API STSCMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STSCMenuWidget)
	{}

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime);

private:
	//�󶨵�����MenuItem�ķ���
	void OnMenuItemClicked(EMenuItem::Type ItemType);
	//�޸�����
	void ChangeLanguage(ECultrueTeam Culture);
	//�޸�����
	void ChangeVolume(const float MusicVol, const float SoundVol);
	//��ʼ�����пؼ�
	void InitializedMenuList();
	//ѡ��Ҫ��ʾ�Ŀؼ�
	void ShowWidget(EMenuType::Type WidgetType);
	//�޸ĸ��ؼ���С
	void ResetWidgetSize(float NewWidth, float NewHeight);
	//��ʼ���������
	void InitializedAnimation();
	//���Ŷ���
	void PlayAnim(EMenuType::Type NewMenu);

private:
	//��ȡMenuStyle
	const struct FTSCMenuStyle* MenuStyle;
	//������ڵ�
	TSharedPtr<SBox>RootSizeBox;
	//�˵������ı�ָ��
	TSharedPtr<STextBlock>TitileText;
	//�˵���ֱ��
	TSharedPtr<SVerticalBox>ContentBox;
	//����˵���
	TMap<EMenuType::Type, TSharedPtr<MenuGroup>> MenuMap;
	//��Ϸ���ÿؼ�ָ��
	TSharedPtr<STSCGameOptionWidget>GameOptionWidget;
	//��Ϸ���ÿؼ�ָ��
	TSharedPtr<STSCNewGameWidget>NewGameWidget;
	//��Ϸ���ÿؼ�ָ��
	TSharedPtr<STSCChooseSaveDataWidget>ChooseSaveDataWidget;

	//����������
	FCurveSequence MenuAnimation;
	//�������߾��
	FCurveHandle MenuAnimationCurve;
	//�µĲ˵��߶�
	float CurrentHeight;
	//�Ƿ��Ѿ���ʾMenu���
	bool bIsMenuShow;
	//�Ƿ���ס��ť
	bool bIsLockButton;
	//��ǰ������״̬
	EMenuAnim::Type AnimState;
	//��ǰ�Ĳ˵�
	EMenuType::Type CurrentMenu;
	
};
