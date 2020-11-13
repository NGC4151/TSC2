// shut up

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"

/**
 * debug��
 */

namespace TSSCHelper {
    FORCEINLINE void Debug(FString Message, FColor TextColor,float DisplayTime = 3.0f) {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, DisplayTime, TextColor, Message);
        }

    }
}
