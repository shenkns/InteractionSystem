// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Lever.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/InteractionComponent.h"

ALever::ALever()
{
	PrimaryActorTick.bCanEverTick = false;

	LeverMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("LeverMesh"));
	SetRootComponent(LeverMesh);

	LeverInteractionTrigger = CreateDefaultSubobject<UBoxComponent>(FName("LeverInteractionTrigger"));
	LeverInteractionTrigger->SetupAttachment(LeverMesh);

	InteractionComponent = CreateDefaultSubobject<UInteractionComponent>(FName("InteractionComponent"));
}

bool ALever::Interact_Implementation()
{
	bool bSuccess = true;
	
	for(AActor* Actor : ConnectedActors)
	{
		if(InteractionComponent->CanInteract(Actor))
		{
			bSuccess &= IInteractionInterface::Execute_Interact(Actor);
		}

		bSuccess = false;
	}

	return bSuccess;
}
