// shut up


#include "UI/Widget/STSCNewGameWidget.h"
#include "SlateOptMacros.h"
#include <UI/Style/TSCStyle.h>
#include <UI/Style/TSCMenuWidgetStyle.h>
#include "Data/TSCDataHandle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STSCNewGameWidget::Construct(const FArguments& InArgs)
{
	//获取编辑器里的MenuStyle
	MenuStyle = &FTSCStyle::Get().GetWidgetStyle<FTSCMenuStyle>("BP_MenuStyle");

	ChildSlot
	[
		SNew(SBox)
		.HeightOverride(100.f)
		.WidthOverride(500.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.Image(&MenuStyle->MenuItemImage)
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(FMargin(20.f, 0.f, 0.f, 0.f))
		[
			SNew(STextBlock)
			.Font(MenuStyle->Font_15)
		    .Text(NSLOCTEXT("TSCMenu", "NewGame", "NewGame"))
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		.Padding(FMargin(0.f, 0.f, 20.f, 0.f))
		[
			SNew(SBox)
			.HeightOverride(60.f)
		    .WidthOverride(300.f)
		[
			SAssignNew(EditTextBox,SEditableTextBox)
			.HintText(NSLOCTEXT("TSCMenu", "Input SaveData Name.", "Input SaveData Name."))
            .Font(MenuStyle->Font_15)
		]
		]

		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

bool STSCNewGameWidget::bCanEnterGame()
{
	FText InputText = EditTextBox->GetText();

	if (InputText.ToString().IsEmpty()) return false;
	
	for (TArray<FString>::TIterator It(TSCDataHandle::Get()->SaveDataList);It;++It)
	{
		if ((*It).Equals(InputText.ToString()))
		{
			EditTextBox->SetText(FText::FromString(""));

			EditTextBox->SetHintText(NSLOCTEXT("TSCMenu", "Name Repeated!", "Name Repeated!"));

			return false;
		}
	}

	TSCDataHandle::Get()->SaveDataName = InputText.ToString();

	return true;
}
