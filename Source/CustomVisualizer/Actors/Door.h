// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

class UDoorVisualizerComponent;

UCLASS()
class CUSTOMVISUALIZER_API ADoor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoor();

#if WITH_EDITORONLY_DATA
	
protected:

	/*
	 *(Editor)
	 *Almacena los interruptores que activan la puerta
	 *-
	 *Hold the information of the switched that activate the door
	 */
	
	UPROPERTY( meta=(AllowPrivateAccess=true))
	TArray<AActor*> Switches;

	/*
	 *(Editor)
	 *Componente usado para identificar que se deben realizar los dibujos
	 *-
	 *Actor component which tell the engine to draw the visualizars
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Editor", meta=(AllowPrivateAccess=true))
	TObjectPtr<UDoorVisualizerComponent> VisualizerComponent;

#endif


public:

#if WITH_EDITOR

	/*
	 *(Editor)
	 *Usadas para agregar/retirar los interruptores a el actor
	 *-
	 *USed to add/remove the switched to the actor
	 */

	
	void AddSwitch(AActor* NewSwitch);

	void RemoveSwitch(AActor* OldSwitch);

#endif
	
};
