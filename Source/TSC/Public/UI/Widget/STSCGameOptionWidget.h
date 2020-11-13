// shut up

#pragma once

#include "CoreMinimal.h"
#include "Data/TSCTypes.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class SCheckBox;
class SSlider;
class STextBlock;

//修改语言的委托
DECLARE_DELEGATE_OneParam(FChangeLanguage, const ECultrueTeam)
//修改音量的稳妥
DECLARE_DELEGATE_TwoParams(FChangeVolume, const float, const float)

class TSC_API STSCGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STSCGameOptionWidget)
	{}

	SLATE_EVENT(FChangeLanguage, ChangeLanguage)
		SLATE_EVENT(FChangeVolume, ChangeVolume)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
private:
	//
	void SetStyle();
	//
	void MusicSliderValueChange(float Value);
	//
	void SoundSliderValueChange(float Value);
	//
	void ZhCheckBoxStateChanged(ECheckBoxState NewState);
	//
	void EnCheckBoxStateChanged(ECheckBoxState NewState);

private:
	//获取MenuStyle
	const struct FTSCMenuStyle* MenuStyle;

	//
	TSharedPtr<SCheckBox>EnCheckBox;
	TSharedPtr<SCheckBox>ZhCheckBox;
	//
	TSharedPtr<SSlider>MusicSlider;
	TSharedPtr<SSlider>SoundSlider;
    //
	TSharedPtr<STextBlock>MusicTextBlock;
	TSharedPtr<STextBlock>SoundTextBlock;
	//委托变量
	FChangeLanguage ChangeLanguage;
	FChangeVolume ChangeVolume;

};
