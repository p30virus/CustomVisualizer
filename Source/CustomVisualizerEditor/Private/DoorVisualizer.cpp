// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorVisualizer.h"

#include "CustomVisualizerEditor_BFL.h"
#include "CustomVisualizer/Actors/Door.h"
#include "CustomVisualizer/Actors/Switch.h"
#include "CustomVisualizer/Components/DoorVisualizerComponent.h"

void FDoorVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	const UDoorVisualizerComponent* ComponentViz = Cast<const UDoorVisualizerComponent>(Component);
	if (ComponentViz == nullptr)
	{
		return;
	}

	ADoor* Door = Cast<ADoor>(ComponentViz->GetOwner());
	if (Door != nullptr)
	{
		FVector ActorOrigin;
		FVector BoxExtent;
		
		UCustomVisualizerEditor_BFL::GetActorBoundsAndExtend(Door, ActorOrigin, BoxExtent);
		
		UCustomVisualizerEditor_BFL::DrawDoorBox(PDI, ActorOrigin, BoxExtent);
		
		for (AActor* SwitchActor : ComponentViz->Switches)
		{
			ASwitch* SwitchTmp = Cast<ASwitch>(SwitchActor);
			if (SwitchTmp != nullptr)
			{
				FVector SwitchOrigin;
				FVector SwitchBoxExtent;
				

				UCustomVisualizerEditor_BFL::GetActorBoundsAndExtend(SwitchTmp, SwitchOrigin, SwitchBoxExtent);
	
				UCustomVisualizerEditor_BFL::DrawSwitchBox(PDI, SwitchOrigin, SwitchBoxExtent);

				UCustomVisualizerEditor_BFL::DrawCustomLine(PDI, ActorOrigin, SwitchOrigin);

			}
		}

		
	}
}
