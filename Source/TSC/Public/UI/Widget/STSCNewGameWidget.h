// shut up

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */

class SEditableTextBox;

class TSC_API STSCNewGameWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STSCNewGameWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	bool bCanEnterGame();

private:
	//��ȡMenuStyle
	const struct FTSCMenuStyle* MenuStyle;
	//�༭��ָ��
	TSharedPtr<SEditableTextBox>EditTextBox;
};
