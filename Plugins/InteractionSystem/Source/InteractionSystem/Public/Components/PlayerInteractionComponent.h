// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/InteractionComponent.h"

#include "PlayerInteractionComponent.generated.h"

UCLASS()
class INTERACTIONSYSTEM_API UPlayerInteractionComponent : public UInteractionComponent
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Interaction")
	float InteractionTraceDistance = 600.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Interaction")
	TEnumAsByte<ECollisionChannel> TraceChannel;

public:

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	bool TryInteract(); 
};
