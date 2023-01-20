// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/InteractionComponent.h"

#include "Interfaces/InteractionInterface.h"

UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	SetIsReplicatedByDefault(true);
}

bool UInteractionComponent::Interact(AActor* Target)
{
	if(!CanInteract(Target)) return false;
	
	/*if(GetOwner()->HasAuthority())
	{
		return IInteractionInterface::Execute_Interact(Target);
	}

	ServerInteract_Implementation(Target);
	return true;*/

	return IInteractionInterface::Execute_Interact(Target);
}

bool UInteractionComponent::CanInteract(AActor* Target) const
{
	if(!Target->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass())) return false;

	for(TSubclassOf<AActor> InteractableClass : InteractableClasses)
	{
		if(Target->GetClass() == InteractableClass || Target->GetClass()->IsChildOf(InteractableClass)) return true;
	}

	return false;
}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInteractionComponent::ServerInteract_Implementation(AActor* Target)
{
	Interact(Target);
}
