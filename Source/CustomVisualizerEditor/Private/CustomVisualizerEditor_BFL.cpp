// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomVisualizerEditor_BFL.h"


void UCustomVisualizerEditor_BFL::GetActorBoundsAndExtend(AActor* Actor, FVector& ActorOrigin, FVector& BoxExtent)
{
	Actor->GetActorBounds(true, ActorOrigin, BoxExtent, false);
}

void UCustomVisualizerEditor_BFL::DrawSwitchBox(FPrimitiveDrawInterface* PDI, FVector SwitchOrigin, FVector SwitchExtent)
{
	FBox DrawBox = FBox::BuildAABB(SwitchOrigin, SwitchExtent + BoxExtend);

	DrawWireBox(
		PDI,
		DrawBox,
		FLinearColor::Green,
		SDPG_World,
		2.f
	);
}

void UCustomVisualizerEditor_BFL::DrawDoorBox(FPrimitiveDrawInterface* PDI, FVector DoorOrigin, FVector DoorExtent)
{
	FBox ActivableDrawBox = FBox::BuildAABB(DoorOrigin, DoorExtent  + FVector(BoxExtend));
	DrawWireBox(
		PDI,
		ActivableDrawBox,
		FLinearColor::Red,
		SDPG_World,
		2.f
	);
}

void UCustomVisualizerEditor_BFL::DrawCustomLine(FPrimitiveDrawInterface* PDI, FVector SwitchOrigin, FVector DoorOrigin)
{
	PDI->DrawLine(
				SwitchOrigin,
				DoorOrigin,
				FLinearColor::Blue,
				SDPG_World,
				1.0f
			);
}
