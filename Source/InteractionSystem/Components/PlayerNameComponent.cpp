// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/PlayerNameComponent.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"
#include "Widgets/PlayerNameWidget.h"

UPlayerNameComponent::UPlayerNameComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
	SetIsReplicatedByDefault(true);

	PlayerNameWidgetClass = UPlayerNameWidget::StaticClass();
}

void UPlayerNameComponent::BeginPlay()
{
	Super::BeginPlay();

	if(GetOwner()->GetInstigatorController() && !GetOwner()->HasAuthority())
	{
		UPlayerNameWidget* NameWidget = CreateWidget<UPlayerNameWidget>(GetWorld(), PlayerNameWidgetClass);
		NameWidget->Init(this);
		NameWidget->AddToViewport();
	}
}

void UPlayerNameComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(const APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0))
	{
		const FRotator Rotation = UKismetMathLibrary::FindLookAtRotation(GetComponentLocation(), CameraManager->GetCameraLocation());
		SetWorldRotation(Rotation);
	}

	SetText(FText::FromName(PlayerName));
}

void UPlayerNameComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME(UPlayerNameComponent, PlayerName);
}

void UPlayerNameComponent::SetName(FName Name)
{
	ServerSetName(Name);
}

void UPlayerNameComponent::ServerSetName_Implementation(FName Name)
{
	PlayerName = Name;
}
