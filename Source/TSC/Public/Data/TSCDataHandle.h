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
    //�޸���Ϸ����
    void ChangeLanguage(ECultrueTeam Cultrue);
    //
    void SetVolume(float MusicVol, float SoundVol);

public:
    //��ǰ����
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
