// Fill out your copyright notice in the Description page of Project Settings.


#include "SwitchVisualizer.h"

#include "CustomVisualizerEditor_BFL.h"
#include "CustomVisualizer/Actors/Door.h"
#include "CustomVisualizer/Actors/Switch.h"
#include "CustomVisualizer/Components/SwitchVisualizerComponent.h"

void FSwitchVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	const USwitchVisualizerComponent* ComponentViz = Cast<const USwitchVisualizerComponent>(Component);
	if (ComponentViz == nullptr)
	{
		return;
	}

	ASwitch* Switch = Cast<ASwitch>(ComponentViz->GetOwner());
	if (Switch != nullptr)
	{
		FVector ActorOrigin;
		FVector BoxExtent;
		
		UCustomVisualizerEditor_BFL::GetActorBoundsAndExtend(Switch, ActorOrigin, BoxExtent);
		UCustomVisualizerEditor_BFL::DrawSwitchBox(PDI, ActorOrigin, BoxExtent);
	
		for (AActor* DoorActor : ComponentViz->Doors)
		{
			ADoor* DoorTmp = Cast<ADoor>(DoorActor);
			if (DoorTmp != nullptr)
			{				
				FVector DoorOrigin;
				FVector DoorBoxExtent;

				UCustomVisualizerEditor_BFL::GetActorBoundsAndExtend(DoorTmp, DoorOrigin, DoorBoxExtent);
				UCustomVisualizerEditor_BFL::DrawDoorBox(PDI, DoorOrigin, DoorBoxExtent);
				UCustomVisualizerEditor_BFL::DrawCustomLine(PDI, ActorOrigin, DoorOrigin);
			}
		}
	}
}
