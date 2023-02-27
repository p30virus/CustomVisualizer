// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CustomVisualizerEditorTarget : TargetRules
{
	public CustomVisualizerEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		
		/*
		 * Se agregan los módulos a usar
		 * -
		 * Adding used modules
		 */
		ExtraModuleNames.Add("CustomVisualizer");
		ExtraModuleNames.AddRange(new string[] { "CustomVisualizerEditor" });
	}

}
