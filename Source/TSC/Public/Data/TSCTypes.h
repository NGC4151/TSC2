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
        LoadSaveData,
        GameOptionGoBack,
        ChooseGoBack,
        NewGameGoBack,
        EnterGame,
        EnterSaveData,
        ReturnGame
    };
}

namespace EMainMenuItem
{
	enum Type
	{
		None,
        Battle,
        Cooperation,
        Against,
        Custom,
        Collection,
        Replay
	};
}

//菜单界面类型
namespace EMenuType
{
    enum Type
    {
        None,
        MainMenu,
        StartGame,
        GameOption,
        NewGame,
        ChooseSavaData
    };
}

namespace EMenuAnim
{
    enum Type
    {
        Stop,//停止动画
        Open,//打开菜单
        Close//关闭菜单
    };
}