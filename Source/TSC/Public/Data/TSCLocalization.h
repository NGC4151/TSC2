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

TSCLocalization::Register(LOCTEXT("NewGame", "NewGame"));
TSCLocalization::Register(LOCTEXT("EnterGame", "EnterGame"));
TSCLocalization::Register(LOCTEXT("Menu", "Menu"));
TSCLocalization::Register(LOCTEXT("Option", "Option"));
TSCLocalization::Register(LOCTEXT("Help", "Help"));
TSCLocalization::Register(LOCTEXT("Exit", "Exit"));
TSCLocalization::Register(LOCTEXT("LoadSave", "LoadSave"));
TSCLocalization::Register(LOCTEXT("EnterSaveData", "EnterSaveData"));
TSCLocalization::Register(LOCTEXT("ReturnGame", "ReturnGame"));
TSCLocalization::Register(LOCTEXT("StartGame", "StartGame"));
TSCLocalization::Register(LOCTEXT("Chinese", "Chinese"));
TSCLocalization::Register(LOCTEXT("English", "English"));
TSCLocalization::Register(LOCTEXT("Sound", "Sound"));
TSCLocalization::Register(LOCTEXT("Music", "Music"));
TSCLocalization::Register(LOCTEXT("Battle", "Battle"));
TSCLocalization::Register(LOCTEXT("Cooperation", "Cooperation"));
TSCLocalization::Register(LOCTEXT("Against", "Against"));
TSCLocalization::Register(LOCTEXT("Custom", "Custom"));
TSCLocalization::Register(LOCTEXT("Collection", "Collection"));
TSCLocalization::Register(LOCTEXT("Replay", "Replay"));
TSCLocalization::Register(LOCTEXT("Input SaveData Name.", "Input SaveData Name."));
TSCLocalization::Register(LOCTEXT("Name Repeated!", "Name Repeated!"));

#undef LOCTEXT_NAMESPACE
