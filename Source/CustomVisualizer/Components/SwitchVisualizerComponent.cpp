// Fill out your copyright notice in the Description page of Project Settings.


#include "SwitchVisualizerComponent.h"


// Sets default values for this component's properties
USwitchVisualizerComponent::USwitchVisualizerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void USwitchVisualizerComponent::SetTargets(TArray<AActor*> NewDoors)
{
	Doors = NewDoors;
}

TArray<AActor*> USwitchVisualizerComponent::GetTargets()
{
	return Doors;
}

