// shut up

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include <Data/TSCTypes.h>

//按钮按下时的委托
DECLARE_DELEGATE_OneParam(FOnItemClicked,const EMenuItem::Type)

/**
 * 
 */
class TSC_API STSCMenuItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STSCMenuItemWidget)
	{}
	SLATE_ATTRIBUTE(FText,ItemText)
	SLATE_EVENT(FOnItemClicked, OnClicked)
	SLATE_ATTRIBUTE(EMenuItem::Type,ItemType)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//重写按键按下时的事件
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)override;
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent)override;
private:
	FSlateColor GetTintColor()const;
private:
	//获取MenuStyle
	const struct FTSCMenuStyle* MenuStyle;
	//按键按下时的委托
	FOnItemClicked OnClicked;
	//保存按钮类型
	EMenuItem::Type ItemType;
	//按钮是否按下
	bool bISButtonPressed;

};
