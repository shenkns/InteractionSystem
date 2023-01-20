// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class InteractionSystem : ModuleRules
{
	public InteractionSystem(ReadOnlyTargetRules Target) : base(Target)
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

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PrivateIncludePaths.AddRange(
			new string[]
			{
				"InteractionSystem/"
			}
		);
		
		PublicIncludePaths.AddRange(
			new string[]
			{
				"InteractionSystem/"
			}
		);
	}
}
