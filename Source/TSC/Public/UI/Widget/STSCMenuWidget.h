// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SBox;
class STextBlock;

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
	//��ȡMenuStyle
	const struct FTSCMenuStyle* MenuStyle;
	//������ڵ�
	TSharedPtr<SBox>RootSizeBox;
	//�˵������ı�ָ��
	TSharedPtr<STextBlock>TitileText;
};
