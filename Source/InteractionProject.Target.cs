// Copyright shenkns Interaction System Developed With Unreal Engine. All Rights Reserved 2023.

using UnrealBuildTool;
using System.Collections.Generic;

public class InteractionProjectTarget : TargetRules
{
	public InteractionProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "InteractionProject" } );
	}
}
