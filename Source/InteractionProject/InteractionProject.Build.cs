// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class InteractionProject : ModuleRules
{
	public InteractionProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core", 
				"CoreUObject", 
				"Engine", 
				"InputCore",
				"UMG"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"InteractionSystem"
			}
		);

		PrivateIncludePaths.AddRange(
			new string[]
			{
				"InteractionProject/"
			}
		);
		
		PublicIncludePaths.AddRange(
			new string[]
			{
				"InteractionProject/"
			}
		);
	}
}
