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
    //
    void SetVolume(float MusicVol, float SoundVol);

public:
    //当前语言
    ECultrueTeam CurrentCultrue;
    //
    float MusicVolume;
    //
    float SoundVolume;

private:
    static TSharedRef<TSCDataHandle>Create();

private:

    static TSharedPtr<TSCDataHandle>DataInstance;
};
