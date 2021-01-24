// shut up


#include "UI/Widget/STSCMenuItemWidget.h"
#include "SlateOptMacros.h"
#include <UI/Style/TSCStyle.h>
#include <UI/Style/TSCMenuWidgetStyle.h>

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STSCMenuItemWidget::Construct(const FArguments& InArgs)
{
	//获取编辑器里的MenuStyle
	MenuStyle = &FTSCStyle::Get().GetWidgetStyle<FTSCMenuStyle>("BP_MenuStyle");
	OnClicked = InArgs._OnClicked;
	ItemType = InArgs._ItemType.Get();
	bISButtonPressed = false;

	ChildSlot
	[
		SNew(SBox)
.WidthOverride(490.f)
.HeightOverride(100.f)
[
	SNew(SOverlay)
	+SOverlay::Slot()
.VAlign(VAlign_Fill)
.HAlign(HAlign_Fill)
[
	SNew(SImage)
.Image(&MenuStyle->MenuItemImage)
.ColorAndOpacity(this,&STSCMenuItemWidget::GetTintColor)
]
	+SOverlay::Slot()
.VAlign(VAlign_Center)
.HAlign(HAlign_Center)
[
	SNew(STextBlock)
.Text(InArgs._ItemText)
.Font(MenuStyle->Font_30)
]
]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply STSCMenuItemWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bISButtonPressed = true;
	return FReply::Handled();
}

FReply STSCMenuItemWidget::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (bISButtonPressed)
	{
		bISButtonPressed = false;
		OnClicked.ExecuteIfBound(ItemType);
	}
	return FReply::Handled();
}

void STSCMenuItemWidget::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	bISButtonPressed = false;
}

FSlateColor STSCMenuItemWidget::GetTintColor() const
{
	if (bISButtonPressed)
		return FLinearColor(0.1f, 0.1f, 1.f, 0.5f);
	return FLinearColor(1.f, 1.f, 1.f, 1.f);
}

void fun1()
{
	
}

