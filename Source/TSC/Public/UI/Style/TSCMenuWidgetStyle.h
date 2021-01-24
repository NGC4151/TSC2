// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"
#include "Styling/SlateBrush.h"
#include <Fonts/SlateFontInfo.h>

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

	//����ͼƬ
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush MenuBackgroundBrush;
	//����ͼƬ
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush headeIcon;
	//����ͼƬ
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush SpacerImage;
	//����ͼƬ
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush TitleBackgroundBrush;
	//����ͼƬ
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush StarCraftLogo;
	//�˵�ͼƬ
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush MenuImage;
	//��ť����ͼƬ
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush MenuItemImage;
	//30������
	UPROPERTY(EditAnywhere, Category = MenuHUD)
	    FSlateFontInfo Font_30;
	//15������
	UPROPERTY(EditAnywhere, Category = MenuHUD)
	    FSlateFontInfo Font_15;
	//��������ʽ
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSliderStyle SliderStyle;
	//�ı�style
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FTextBlockStyle MyTextStyle;
	//��������style
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FButtonStyle TopButtonStyle;

	//��Ϸ���ÿؼ�����ͼƬ
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush GameOptionImage;
	//��ɫ
	UPROPERTY(EditAnywhere, Category = GameOption)
		FLinearColor Color_Black;
	//CheckBox��ѡͼƬ
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush CheckBoxSelect;
	//CheckBoxδ��ѡͼƬ
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush CheckBoxNoSelect;
	//�����ı���ͼƬ
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush SliderImage;
	
	
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
