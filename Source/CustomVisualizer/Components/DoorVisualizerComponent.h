// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorVisualizerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CUSTOMVISUALIZER_API UDoorVisualizerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDoorVisualizerComponent();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Switches")
	TArray<AActor*> Switches;
	
	UFUNCTION(BlueprintCallable)
	void SetSwitches(TArray<AActor*> NewSwitches);

	UFUNCTION(BlueprintCallable)
	TArray<AActor*> GetSwitches();

};
