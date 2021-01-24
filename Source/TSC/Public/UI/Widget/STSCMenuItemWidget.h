// shut up

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include <Data/TSCTypes.h>

//��ť����ʱ��ί��
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
	FOnItemClicked OnClicked;
	//���水ť����
	EMenuItem::Type ItemType;
	//��ť�Ƿ���
	bool bISButtonPressed;

};
