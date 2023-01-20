// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "PlayerNameWidget.generated.h"

class UPlayerNameComponent;

UCLASS()
class INTERACTIONSYSTEM_API UPlayerNameWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Name")
	UPlayerNameComponent* PlayerNameComponent;

public:

	void Init(UPlayerNameComponent* NameComponent);

protected:

	UFUNCTION(BlueprintCallable, Category = "Name")
	void SetName(FName Name);
};
