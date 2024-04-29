// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CPP_InventorySystem : ModuleRules
{
	public CPP_InventorySystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
    }
}
