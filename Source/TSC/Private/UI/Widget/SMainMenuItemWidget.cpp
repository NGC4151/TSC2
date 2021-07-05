// shut up


#include "UI/Widget/SMainMenuItemWidget.h"
#include "SlateOptMacros.h"
#include "UI/Style/TSCMenuWidgetStyle.h"
#include "Widgets/Images/SImage.h"
#include <UI/Style/TSCStyle.h>

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenuItemWidget::Construct(const FArguments& InArgs)
{
	//获取编辑器里的MenuStyle
	MenuStyle = &FTSCStyle::Get().GetWidgetStyle<FTSCMenuStyle>("BP_MenuStyle");

	OnClicked = InArgs._OnClicked;
	ItemType = InArgs._ItemType.Get();
	bISButtonPressed = false;
	
	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(150.f)
		.HeightOverride(60.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
		[
			SNew(SImage)
			.Image(&MenuStyle->MenuItemImage)
		.ColorAndOpacity(this, &SMainMenuItemWidget::GetTintColor)
		]
	+ SOverlay::Slot()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)
		[
			SNew(STextBlock)
			.Text(InArgs._ItemText)
            .TextStyle(&MenuStyle->MyTextStyle)		
		]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SMainMenuItemWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bISButtonPressed = true;
	return FReply::Handled();
}

FReply SMainMenuItemWidget::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (bISButtonPressed)
	{
		bISButtonPressed = false;
		OnClicked.ExecuteIfBound(ItemType);
	}
	return FReply::Handled();
}

void SMainMenuItemWidget::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	bISButtonPressed = false;
}

FSlateColor SMainMenuItemWidget::GetTintColor() const
{
	if (bISButtonPressed)
		return FLinearColor(0.1f, 0.1f, 1.f, 0.5f);
	return FLinearColor(1.f, 1.f, 1.f, 1.f);
}
