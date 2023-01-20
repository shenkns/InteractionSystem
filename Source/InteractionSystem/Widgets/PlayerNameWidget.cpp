// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/PlayerNameWidget.h"

#include "Components/PlayerNameComponent.h"

void UPlayerNameWidget::Init(UPlayerNameComponent* NameComponent)
{
	PlayerNameComponent = NameComponent;
}

void UPlayerNameWidget::SetName(FName Name)
{
	PlayerNameComponent->SetName(Name);
}
