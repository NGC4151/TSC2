// shut up

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"

/**
 * debug类
 */

namespace TSSCHelper {
    FORCEINLINE void Debug(FString Message, FColor TextColor,float DisplayTime = 20.0f) {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, DisplayTime, TextColor, Message);
        }

    }
}
