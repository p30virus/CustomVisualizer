using UnrealBuildTool;

public class CustomVisualizerEditor : ModuleRules
{
    public CustomVisualizerEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]   {   "Core", "UnrealEd", }   );

        PrivateDependencyModuleNames.AddRange(  new string[]    {   "CoreUObject",  "Engine",   "Slate",    "SlateCore" }   );
        
        /*
		 * Se agregan los módulos a usar
		 * -
		 * Adding used modules
		 */
		
        PublicDependencyModuleNames.AddRange(new string[] {  "CustomVisualizer" });
        
        // Needed for our editor logic
        PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd" });
        
    }
}