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

//�޸����Ե�ί��
DECLARE_DELEGATE_OneParam(FChangeLanguage, const ECultrueTeam)
//�޸�����������
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
	//��ȡMenuStyle
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
	//ί�б���
	FChangeLanguage ChangeLanguage;
	FChangeVolume ChangeVolume;

};
