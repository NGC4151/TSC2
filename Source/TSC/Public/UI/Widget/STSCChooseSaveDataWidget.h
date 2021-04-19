// shut up

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */

class STextComboBox;

class TSC_API STSCChooseSaveDataWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STSCChooseSaveDataWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//���´浵��
	void UpdateSaveName();

private:
	//��ȡMenuStyle
	const struct FTSCMenuStyle* MenuStyle;
	//������ָ��
	TSharedPtr<STextComboBox> SaveDataComboBox;
	//�ַ�ָ��
	TArray<TSharedPtr<FString>>OptionSource;
};
