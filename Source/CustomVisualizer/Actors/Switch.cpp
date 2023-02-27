// Fill out your copyright notice in the Description page of Project Settings.


#include "Switch.h"

#include "Door.h"
#include "CustomVisualizer/Components/SwitchVisualizerComponent.h"


// Sets default values
ASwitch::ASwitch()
{
	PrimaryActorTick.bCanEverTick = false;

#if WITH_EDITORONLY_DATA

	VisualizerComponent = CreateDefaultSubobject<USwitchVisualizerComponent>(TEXT("VisualizerComponent"));
	
#endif
}

void ASwitch::PreEditChange(FProperty* PropertyAboutToChange)
{
	Super::PreEditChange(PropertyAboutToChange);

	const FString PropertyName = PropertyAboutToChange->GetName();
	if ( PropertyName == GET_MEMBER_NAME_CHECKED(ASwitch, Doors).ToString() )
	{
		OriginalDoors.Empty();
		OriginalDoors = Doors;
	}
}

void ASwitch::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	if (PropertyName == GET_MEMBER_NAME_CHECKED(ASwitch, Doors))
	{

		if (VisualizerComponent != nullptr)
		{
			VisualizerComponent->SetTargets(Doors);
		}
		
		/*
		 * Validar los eventos de cambio
		 * -
		 * Validate the Change Events
		 */
		
		if ( PropertyChangedEvent.ChangeType == EPropertyChangeType::ArrayClear )
		{
			for (AActor* ActorToRemove : OriginalDoors)
			{
				ADoor* DoorTmp = Cast<ADoor>(ActorToRemove);
				if (DoorTmp != nullptr)
				{
					DoorTmp->RemoveSwitch(this);
				}
			}
		}
		else if ( PropertyChangedEvent.ChangeType == EPropertyChangeType::ArrayRemove )
		{
			TArray<AActor*> DoorsToRemove = OriginalDoors;
			for (AActor* StillExist : Doors)
			{
				if (StillExist != nullptr)
				{
					DoorsToRemove.Remove(StillExist);
				}
			}

			for (AActor* ToRemove : DoorsToRemove)
			{
				ADoor* ActivableTmp = Cast<ADoor>(ToRemove);
				if (ActivableTmp != nullptr)
				{
					ActivableTmp->RemoveSwitch(this);
				}
			}
		}
		else if ( PropertyChangedEvent.ChangeType == EPropertyChangeType::ArrayAdd )
		{
			TArray<AActor*> DoorsToAdd = Doors;
			for (AActor* StillExist : DoorsToAdd)
			{
				if (StillExist != nullptr)
				{
					DoorsToAdd.Remove(StillExist);
				}
			}

			for (AActor* ToAdd : DoorsToAdd)
			{
				ADoor* DoorTmp = Cast<ADoor>(ToAdd);
				if (DoorTmp != nullptr)
				{
					DoorTmp->AddSwitch(this);
				}
			}
		}
		else if ( PropertyChangedEvent.ChangeType == EPropertyChangeType::ValueSet )
		{
			TArray<AActor*> DoorsToAdd = Doors;
			TArray<AActor*> DoorsToRemove;
			
			for (AActor* OldValue : OriginalDoors)
			{
				if (OldValue != nullptr)
				{
					int32 numOfRemoved = DoorsToAdd.Remove(OldValue);
					if (numOfRemoved > 0 )
					{
						DoorsToRemove.Add(OldValue);
					}
				}
			}

			for (AActor* OldValue : DoorsToRemove)
			{
				if (OldValue != nullptr)
				{
					OriginalDoors.Remove(OldValue);
				}
			}

			for (AActor* ToAdd : DoorsToAdd)
			{
				ADoor* DoorTmp = Cast<ADoor>(ToAdd);
				if (DoorTmp != nullptr)
				{
					DoorTmp->AddSwitch(this);
				}
			}

			for (AActor* ToRemove : OriginalDoors)
			{
				ADoor* DoorTmp = Cast<ADoor>(ToRemove);
				if (DoorTmp != nullptr)
				{
					DoorTmp->RemoveSwitch(this);
				}
			}
		}
	}
}

