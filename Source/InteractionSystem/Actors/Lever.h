// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Interfaces/InteractionInterface.h"

#include "Lever.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class UInteractionComponent;

UCLASS()
class INTERACTIONSYSTEM_API ALever : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:
	
	ALever();
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* LeverMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UBoxComponent* LeverInteractionTrigger;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UInteractionComponent* InteractionComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Interaction")
	TArray<AActor*> ConnectedActors;

public:

	virtual bool Interact_Implementation() override;
};
