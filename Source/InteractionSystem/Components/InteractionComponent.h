// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"

#include "InteractionComponent.generated.h"

UCLASS(ClassGroup = (Interaction), meta = (BlueprintSpawnableComponent))
class INTERACTIONSYSTEM_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UInteractionComponent();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Interaction")
	TArray<TSubclassOf<AActor>> InteractableClasses;

public:

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	bool Interact(AActor* Target);

	UFUNCTION(BlueprintPure, Category = "Interaction")
	bool CanInteract(AActor* Target) const;

	UFUNCTION(Server, Reliable)
	void ServerInteract(AActor* Target);

protected:
	
	virtual void BeginPlay() override;
	
};
