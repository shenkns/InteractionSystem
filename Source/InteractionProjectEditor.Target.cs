// Copyright shenkns Interaction System Developed With Unreal Engine. All Rights Reserved 2023.

using UnrealBuildTool;
using System.Collections.Generic;

public class InteractionProjectEditorTarget : TargetRules
{
	public InteractionProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "InteractionProject" } );
	}
}
