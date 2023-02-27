// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorVisualizerComponent.h"


// Sets default values for this component's properties
UDoorVisualizerComponent::UDoorVisualizerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDoorVisualizerComponent::SetSwitches(TArray<AActor*> NewSwitches)
{
	Switches = NewSwitches;
}

TArray<AActor*> UDoorVisualizerComponent::GetSwitches()
{
	return Switches;
}
