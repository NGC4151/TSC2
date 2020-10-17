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

    void ChangeLanguage(ECultrueTeam Cultrue);

public:
    ECultrueTeam CurrentCultrue;

private:
    static TSharedRef<TSCDataHandle>Create();

private:

    static TSharedPtr<TSCDataHandle>DataInstance;
};
