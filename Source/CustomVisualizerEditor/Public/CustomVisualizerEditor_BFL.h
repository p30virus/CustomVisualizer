// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CustomVisualizerEditor_BFL.generated.h"

/**
 * Librerias con algunas funciones para realizar los dibujos
 *	-
 * Blueprint Function Library with some Draw functions
 */
UCLASS()
class CUSTOMVISUALIZEREDITOR_API UCustomVisualizerEditor_BFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	inline static float BoxExtend{30.f};

public:
		
	static void GetActorBoundsAndExtend(AActor* Actor, FVector& ActorOrigin, FVector& BoxExtent);

	static void DrawSwitchBox(FPrimitiveDrawInterface* PDI, FVector SwitchOrigin, FVector SwitchExtent );

	static void DrawDoorBox(FPrimitiveDrawInterface* PDI, FVector DoorOrigin, FVector DoorExtent );

	static void DrawCustomLine(FPrimitiveDrawInterface* PDI, FVector SwitchOrigin, FVector DoorOrigin );
	
};
