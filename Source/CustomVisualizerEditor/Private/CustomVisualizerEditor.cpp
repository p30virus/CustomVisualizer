#include "CustomVisualizerEditor.h"

#include "DoorVisualizer.h"
#include "SwitchVisualizer.h"
#include "UnrealEd.h"
#include "CustomVisualizer/Components/DoorVisualizerComponent.h"
#include "CustomVisualizer/Components/SwitchVisualizerComponent.h"

#define LOCTEXT_NAMESPACE "FCustomVisualizerEditorModule"

void FCustomVisualizerEditorModule::StartupModule()
{
	/*
	 * Agregamos y registramos las clases para los objetos de editor
	 * -
	 * Add and register the editor visualizer classes 
	 */
	
	TSharedPtr<FComponentVisualizer> Switch_Visualizer = MakeShareable(new FSwitchVisualizer());
	TSharedPtr<FComponentVisualizer> Activable_Visualizer = MakeShareable(new FDoorVisualizer());
	
	GUnrealEd->RegisterComponentVisualizer(USwitchVisualizerComponent::StaticClass()->GetFName(), Switch_Visualizer);
	GUnrealEd->RegisterComponentVisualizer(UDoorVisualizerComponent::StaticClass()->GetFName(), Activable_Visualizer);
	Switch_Visualizer->OnRegister();
	Activable_Visualizer->OnRegister();
}

void FCustomVisualizerEditorModule::ShutdownModule()
{
	/*
	 * Retiramos el registro de las clases para los objetos de editor
	 * -
	 * Unregister the editor visualizer classes 
	 */
	GUnrealEd->UnregisterComponentVisualizer(USwitchVisualizerComponent::StaticClass()->GetFName());
	GUnrealEd->UnregisterComponentVisualizer(UDoorVisualizerComponent::StaticClass()->GetFName());
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FCustomVisualizerEditorModule, CustomVisualizerEditor)