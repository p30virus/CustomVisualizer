// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "CustomVisualizer/Components/DoorVisualizerComponent.h"


// Sets default values
ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = false;

#if WITH_EDITORONLY_DATA

	VisualizerComponent = CreateDefaultSubobject<UDoorVisualizerComponent>(TEXT("VisualizerComponent"));

#endif
}

#if WITH_EDITOR

void ADoor::AddSwitch(AActor* NewSwitch)
{
	Switches.AddUnique(NewSwitch);


	if (VisualizerComponent != nullptr)
	{
		VisualizerComponent->SetSwitches(Switches);
	}

}

void ADoor::RemoveSwitch(AActor* OldSwitch)
{
	Switches.RemoveSingle(OldSwitch);
	
	if (VisualizerComponent != nullptr)
	{
		VisualizerComponent->SetSwitches(Switches);
	}
}

#endif



