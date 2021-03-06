// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TSC : ModuleRules
{
	public TSC(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"Slate",
			"SlateCore",
			"Json",
			"JsonUtilities",
			"UMG"
		});


		// Uncomment if you are using Slate UI
		 PrivateDependencyModuleNames.AddRange(new string[] {
             "Slate",
             "SlateCore",
             "GameplayAbilities",
             "GameplayTags",
             "GameplayTasks",

         });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
