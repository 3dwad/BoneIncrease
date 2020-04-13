// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DreamsideTZ : ModuleRules
{
	public DreamsideTZ(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "AnimGraph", "AnimGraphRunTime", "BlueprintGraph" });
		PrivateDependencyModuleNames.AddRange(new string[] { "AnimGraph", "AnimGraphRunTime", "BlueprintGraph" });
	}
}
