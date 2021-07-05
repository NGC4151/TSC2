// shut up

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include <Data/TSCTypes.h>

//��ť����ʱ��ί��
DECLARE_DELEGATE_OneParam(FOnMainItemClicked, const EMainMenuItem::Type)

/**
 * 
 */
class TSC_API SMainMenuItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenuItemWidget)
	{}
	    SLATE_ATTRIBUTE(FText, ItemText)
		SLATE_EVENT(FOnMainItemClicked, OnClicked)
		SLATE_ATTRIBUTE(EMainMenuItem::Type, ItemType)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//��д��������ʱ���¼�
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)override;
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent)override;

private:
	FSlateColor GetTintColor()const;
private:
	//��ȡMenuStyle
	const struct FTSCMenuStyle* MenuStyle;
	//��������ʱ��ί��
	FOnMainItemClicked OnClicked;
	//���水ť����
	EMainMenuItem::Type ItemType;
	//��ť�Ƿ���
	bool bISButtonPressed;
};
