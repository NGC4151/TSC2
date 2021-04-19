// shut up

#pragma once

#include "CoreMinimal.h"    
#include "TSCTypes.h"

/**
 * 
 */
class TSC_API TSCDataHandle
{
public:
	TSCDataHandle();

    static void Initialize();

    static TSharedPtr<TSCDataHandle>Get();
    //修改游戏语言
    void ChangeLanguage(ECultrueTeam Cultrue);
    //设置音量
    void SetVolume(float MusicVol, float SoundVol);

public:
    //当前语言
    ECultrueTeam CurrentCultrue;
    //
    float MusicVolume;
    //
    float SoundVolume;
    //存档数据
    TArray<FString>SaveDataList;
    //存档名
    FString SaveDataName;

private:
    //创建单例
    static TSharedRef<TSCDataHandle>Create();
    //根据枚举值获取字符串
    template<typename TEnum>
    FString GetEnumValueAsString(const FString& Name, TEnum Value);
    //根据字符串获取枚举值
	template<typename TEnum>
	TEnum GetEnumValueFromString(const FString& Name, FString Value);
    //初始化存档数据
    void InitSavaData();


private:

    static TSharedPtr<TSCDataHandle>DataInstance;
};


