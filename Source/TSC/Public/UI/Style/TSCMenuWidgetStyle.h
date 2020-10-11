// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"
#include "Styling/SlateBrush.h"

#include "TSCMenuWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct TSC_API FTSCMenuStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FTSCMenuStyle();
	virtual ~FTSCMenuStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FTSCMenuStyle& GetDefault();

	UPROPERTY(EditAnywhere,Category=MenuHUD)
	      FSlateBrush MenuBackgroundBrush;
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class UTSCMenuWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FTSCMenuStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
