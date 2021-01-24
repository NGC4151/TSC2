// shut up


#include "UI/Widget/STSCGameOptionWidget.h"
#include "SlateOptMacros.h"
#include <UI/Style/TSCStyle.h>
#include <UI/Style/TSCMenuWidgetStyle.h>
#include "Widgets/SBoxPanel.h"
#include <Widgets/Layout/SBox.h>
#include "Widgets/Images/SImage.h"
#include <Widgets/SOverlay.h>
#include "Data/TSCDataHandle.h"



BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STSCGameOptionWidget::Construct(const FArguments& InArgs)
{
	//��ȡ�༭�����MenuStyle
	MenuStyle = &FTSCStyle::Get().GetWidgetStyle<FTSCMenuStyle>("BP_MenuStyle");

	//��ȡί��
	ChangeLanguage = InArgs._ChangeLanguage;
	ChangeVolume = InArgs._ChangeVolume;
	
	ChildSlot
	[
		//��һ��
		SNew(SBox)
		.WidthOverride(500.f)
		.HeightOverride(300.f)
		[
			SNew(SOverlay)
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.Image(&MenuStyle->GameOptionImage)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
        .Padding(FMargin(50.f))
		[
			SNew(SVerticalBox)
			//��һ��
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SHorizontalBox)
	+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)
		.FillWidth(1.f)
		[
			SAssignNew(ZhCheckBox, SCheckBox)
			.OnCheckStateChanged(this, &STSCGameOptionWidget::ZhCheckBoxStateChanged)
		[
			SNew(STextBlock)
			.Font(MenuStyle->Font_15)
		.ColorAndOpacity(MenuStyle->Color_Black)
		.Text(NSLOCTEXT("TSCMenu", "Chinese", "Chinese"))
		]
		]
	+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)
		.FillWidth(1.f)
		[
			SAssignNew(EnCheckBox, SCheckBox)
			.OnCheckStateChanged(this, &STSCGameOptionWidget::EnCheckBoxStateChanged)
		[
			SNew(STextBlock)
			.Font(MenuStyle->Font_15)
		.ColorAndOpacity(MenuStyle->Color_Black)
		.Text(NSLOCTEXT("TSCMenu", "English", "English"))
		]
		]
		]

	//�ڶ���
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SOverlay)
	+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(MenuStyle->Font_15)
		.ColorAndOpacity(MenuStyle->Color_Black)
		.Text(NSLOCTEXT("TSCMenu", "Music", "Music"))
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SBox)
			.WidthOverride(240.f)
		[
			SNew(SOverlay)
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		.Padding(FMargin(30.f, 0.f))
		[
			SNew(SImage)
			.Image(&MenuStyle->SliderImage)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		[
			SAssignNew(MusicSlider, SSlider)
			.Style(&MenuStyle->SliderStyle)
		.OnValueChanged(this, &STSCGameOptionWidget::MusicSliderValueChange)
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		[
			SAssignNew(MusicTextBlock, STextBlock)
			.Font(MenuStyle->Font_15)
		.ColorAndOpacity(MenuStyle->Color_Black)
		]
		]
		]
		]

	//������
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(MenuStyle->Font_15)
		.ColorAndOpacity(MenuStyle->Color_Black)
		.Text(NSLOCTEXT("TSCMenu", "Sound", "Sound"))
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SBox)
			.WidthOverride(240.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		.Padding(FMargin(30.f, 0.f))
		[
			SNew(SImage)
			.Image(&MenuStyle->SliderImage)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		[
			SAssignNew(SoundSlider, SSlider)
			.Style(&MenuStyle->SliderStyle)
		.OnValueChanged(this, &STSCGameOptionWidget::SoundSliderValueChange)
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		[
			SAssignNew(SoundTextBlock, STextBlock)
			.Font(MenuStyle->Font_15)
		.ColorAndOpacity(MenuStyle->Color_Black)
		]
		]
		]
		]

		]

		]
	];

	//��ʼ����ʽ
	SetStyle();
	
}

void STSCGameOptionWidget::SetStyle()
{
	//
	ZhCheckBox->SetUncheckedImage(&MenuStyle->CheckBoxNoSelect);
	ZhCheckBox->SetUncheckedHoveredImage(&MenuStyle->CheckBoxNoSelect);
	ZhCheckBox->SetUncheckedPressedImage(&MenuStyle->CheckBoxNoSelect);
	ZhCheckBox->SetCheckedImage(&MenuStyle->CheckBoxSelect);
	ZhCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckBoxSelect);
	ZhCheckBox->SetCheckedPressedImage(&MenuStyle->CheckBoxSelect);

	//
	EnCheckBox->SetUncheckedImage(&MenuStyle->CheckBoxNoSelect);
	EnCheckBox->SetUncheckedHoveredImage(&MenuStyle->CheckBoxNoSelect);
	EnCheckBox->SetUncheckedPressedImage(&MenuStyle->CheckBoxNoSelect);
	EnCheckBox->SetCheckedImage(&MenuStyle->CheckBoxSelect);
	EnCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckBoxSelect);
	EnCheckBox->SetCheckedPressedImage(&MenuStyle->CheckBoxSelect);

	//
	switch (TSCDataHandle::Get()->CurrentCultrue)
	{
	case ECultrueTeam::EN:
		EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
		ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
		TSCDataHandle::Get()->ChangeLanguage(ECultrueTeam::EN);
		break;
	case ECultrueTeam::ZH:
		EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
		ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);
		TSCDataHandle::Get()->ChangeLanguage(ECultrueTeam::ZH);
		break;
	}

	//
	SoundSlider->SetValue(TSCDataHandle::Get()->SoundVolume);
	//
	MusicSlider->SetValue(TSCDataHandle::Get()->MusicVolume);

	//
	MusicTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(TSCDataHandle::Get()->MusicVolume * 100)) + FString("%")));
	//
	SoundTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(TSCDataHandle::Get()->SoundVolume * 100)) + FString("%")));
	
}

void STSCGameOptionWidget::MusicSliderValueChange(float Value)
{
	//
	MusicTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value * 100)) + FString("%")));
	//
	//TSCDataHandle::Get()->SetVolume(Value, -1.f);
	ChangeVolume.ExecuteIfBound(Value, -1.f);
}

void STSCGameOptionWidget::SoundSliderValueChange(float Value)
{
	//
	SoundTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value * 100)) + FString("%")));
	//
	//TSCDataHandle::Get()->SetVolume(-1.f, -Value);
	ChangeVolume.ExecuteIfBound(-1.f, -Value);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void STSCGameOptionWidget::ZhCheckBoxStateChanged(ECheckBoxState NewState)
{
	//
	EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);
	//
	//TSCDataHandle::Get()->ChangeLanguage(ECultrueTeam::ZH);
	ChangeLanguage.ExecuteIfBound(ECultrueTeam::ZH);
}

void STSCGameOptionWidget::EnCheckBoxStateChanged(ECheckBoxState NewState)
{
	//
	EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	//
	//TSCDataHandle::Get()->ChangeLanguage(ECultrueTeam::EN);
	ChangeLanguage.ExecuteIfBound(ECultrueTeam::EN);
}

