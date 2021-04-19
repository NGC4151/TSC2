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

	//更新存档名
	void UpdateSaveName();

private:
	//获取MenuStyle
	const struct FTSCMenuStyle* MenuStyle;
	//下拉框指针
	TSharedPtr<STextComboBox> SaveDataComboBox;
	//字符指针
	TArray<TSharedPtr<FString>>OptionSource;
};
