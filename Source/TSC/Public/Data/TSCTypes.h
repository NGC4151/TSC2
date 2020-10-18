// shut up

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM()
enum class ECultrueTeam : uint8 {
    EN=0,
    ZH

};

namespace EMenuItem
{
    enum Type
    {
        None,
        StartGame,
        GameOption,
        QuitGame,
        NewGame,
        ReturnGame
    };
}