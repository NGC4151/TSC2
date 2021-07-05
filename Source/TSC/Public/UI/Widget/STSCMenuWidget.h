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
	//绑定到各个MenuItem的方法
	void OnMenuItemClicked(EMenuItem::Type ItemType);
	//修改语言
	void ChangeLanguage(ECultrueTeam Culture);
	//修改音量
	void ChangeVolume(const float MusicVol, const float SoundVol);
	//初始化所有控件
	void InitializedMenuList();
	//选择要显示的控件
	void ShowWidget(EMenuType::Type WidgetType);
	//修改根控件大小
	void ResetWidgetSize(float NewWidth, float NewHeight);
	//初始化动画组件
	void InitializedAnimation();
	//播放动画
	void PlayAnim(EMenuType::Type NewMenu);

private:
	//获取MenuStyle
	const struct FTSCMenuStyle* MenuStyle;
	//保存根节点
	TSharedPtr<SBox>RootSizeBox;
	//菜单标题文本指针
	TSharedPtr<STextBlock>TitileText;
	//菜单垂直框
	TSharedPtr<SVerticalBox>ContentBox;
	//保存菜单组
	TMap<EMenuType::Type, TSharedPtr<MenuGroup>> MenuMap;
	//游戏设置控件指针
	TSharedPtr<STSCGameOptionWidget>GameOptionWidget;
	//游戏设置控件指针
	TSharedPtr<STSCNewGameWidget>NewGameWidget;
	//游戏设置控件指针
	TSharedPtr<STSCChooseSaveDataWidget>ChooseSaveDataWidget;

	//动画播放器
	FCurveSequence MenuAnimation;
	//动画曲线句柄
	FCurveHandle MenuAnimationCurve;
	//新的菜单高度
	float CurrentHeight;
	//是否已经显示Menu组件
	bool bIsMenuShow;
	//是否锁住按钮
	bool bIsLockButton;
	//当前动画的状态
	EMenuAnim::Type AnimState;
	//当前的菜单
	EMenuType::Type CurrentMenu;
	
};
