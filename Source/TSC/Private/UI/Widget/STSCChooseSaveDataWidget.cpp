// shut up


#include "UI/Widget/STSCChooseSaveDataWidget.h"
#include "SlateOptMacros.h"
#include <UI/Style/TSCStyle.h>
#include <UI/Style/TSCMenuWidgetStyle.h>
#include "Data/TSCDataHandle.h"
#include <Widgets/Input/STextComboBox.h>

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STSCChooseSaveDataWidget::Construct(const FArguments& InArgs)
{
	//获取编辑器里的MenuStyle
	MenuStyle = &FTSCStyle::Get().GetWidgetStyle<FTSCMenuStyle>("BP_MenuStyle");

	//初始化下拉菜单数据
	for (TArray<FString>::TIterator It(TSCDataHandle::Get()->SaveDataList);It;++It)
	{
		OptionSource.Add(MakeShareable(new FString(*It)));
	}

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
			SAssignNew(SaveDataComboBox,STextComboBox)
            .Font(MenuStyle->Font_15)
            .OptionsSource(&OptionSource)
		]
		]

		]
	];

	//设置下拉菜单的默认选项
	SaveDataComboBox->SetSelectedItem(OptionSource[0]);
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void STSCChooseSaveDataWidget::UpdateSaveName()
{
	//修改存档名
	TSCDataHandle::Get()->SaveDataName = *SaveDataComboBox->GetSelectedItem().Get();
}

