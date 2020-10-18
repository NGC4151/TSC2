// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include <Data/TSCTypes.h>

class SBox;
class STextBlock;
class SVerticalBox;

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

private:

	void OnMenuItemClicked(EMenuItem::Type ItemType);

private:
	//获取MenuStyle
	const struct FTSCMenuStyle* MenuStyle;
	//保存根节点
	TSharedPtr<SBox>RootSizeBox;
	//菜单标题文本指针
	TSharedPtr<STextBlock>TitileText;
	//菜单垂直框
	TSharedPtr<SVerticalBox>ContentBox;
};
