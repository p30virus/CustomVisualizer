// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SwitchVisualizerComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CUSTOMVISUALIZER_API USwitchVisualizerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USwitchVisualizerComponent();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Doors")
	TArray<AActor*> Doors;
	
	UFUNCTION(BlueprintCallable)
	void SetTargets(TArray<AActor*> NewDoors);

	UFUNCTION(BlueprintCallable)
	TArray<AActor*> GetTargets();
};
