// shut up

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TSC_API TSCLocalization
{
public:
    static void Register(FText Value) {
        return;
    }
};

#define LOCTEXT_NAMESPACE "TSCMenu"

TSCLocalization::Register(LOCTEXT("Menu", "Menu"));
TSCLocalization::Register(LOCTEXT("Option", "Option"));
TSCLocalization::Register(LOCTEXT("Help", "Help"));
TSCLocalization::Register(LOCTEXT("Exit", "Exit"));
TSCLocalization::Register(LOCTEXT("ReturnGame", "ReturnGame"));
TSCLocalization::Register(LOCTEXT("StartGame", "StartGame"));
TSCLocalization::Register(LOCTEXT("StartGame", "StartGame"));
TSCLocalization::Register(LOCTEXT("Chinese", "Chinese"));
TSCLocalization::Register(LOCTEXT("English", "English"));
TSCLocalization::Register(LOCTEXT("Sound", "Sound"));
TSCLocalization::Register(LOCTEXT("Music", "Music"));

#undef LOCTEXT_NAMESPACE
