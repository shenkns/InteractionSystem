// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Interface.h"

#include "InteractionInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class INTERACTIONSYSTEM_API IInteractionInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category = "Interaction")
	bool Interact();
};
