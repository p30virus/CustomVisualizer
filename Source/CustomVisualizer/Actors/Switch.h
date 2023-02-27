// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Switch.generated.h"

class USwitchVisualizerComponent;

UCLASS()
class CUSTOMVISUALIZER_API ASwitch : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASwitch();

protected:

	/*
	 *Almacena la referencia a la puerta en el nivel
	 *-
	 *Holds the reference to the door in the world
	 */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Doors", meta=(AllowPrivateAccess=true, AllowedClasses="Door"))
	TArray<AActor*> Doors;

#if WITH_EDITORONLY_DATA

	/*
	 *(Editor)
	 *Almacena el array Door antes de ser modificado
	 *-
	 *Temporal array to store the Door array before modify
	 */
	UPROPERTY()
	TArray<AActor*> OriginalDoors;

	/*
	 *(Editor)
	 *Componente usado para identificar que se deben realizar los dibujos
	 *-
	 *Actor component which tell the engine to draw the visualizars
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Editor", meta=(AllowPrivateAccess=true))
	TObjectPtr<USwitchVisualizerComponent> VisualizerComponent;

#endif
	
public:

#if WITH_EDITOR

	/*
	 *(Editor)
	 *Usadas para identificar los campos de las propiedades en el editor
	 *-
	 *Used to identify the changes for the properties in the editor
	 */
	
	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

#endif	
};
