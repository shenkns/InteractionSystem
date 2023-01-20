// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/TextRenderComponent.h"
#include "Widgets/PlayerNameWidget.h"
#include "PlayerNameComponent.generated.h"

class UPlayerNameWidget;

UCLASS()
class INTERACTIONSYSTEM_API UPlayerNameComponent : public UTextRenderComponent
{
	GENERATED_BODY()

public:

	UPlayerNameComponent();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widget")
	TSubclassOf<UPlayerNameWidget> PlayerNameWidgetClass;

	UPROPERTY(BlueprintReadOnly, Replicated, Category = "Name")
	FName PlayerName;

public:

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable, Category = "Name")
	void SetName(FName Name);

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = "Name")
	void ServerSetName(FName Name);
};
