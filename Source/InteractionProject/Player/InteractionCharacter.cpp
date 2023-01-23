// Copyright shenkns Interaction System Developed With Unreal Engine. All Rights Reserved 2023.

#include "Player/InteractionCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/PlayerInteractionComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

AInteractionCharacter::AInteractionCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(FName("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(FName("Camera"));
	Camera->SetupAttachment(CameraBoom);

	PlayerInteractionComponent = CreateDefaultSubobject<UPlayerInteractionComponent>(FName("InteractionComponent"));
}

void AInteractionCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AInteractionCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &AInteractionCharacter::MoveRight);

	PlayerInputComponent->BindAxis(FName("Turn"), this, &AInteractionCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &AInteractionCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction(FName("Interact"), IE_Pressed, this, &AInteractionCharacter::TryInteract);
}

void AInteractionCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AInteractionCharacter::MoveForward(float Axis)
{
	AddMovementInput(UKismetMathLibrary::GetForwardVector(GetControlRotation()), Axis);
}

void AInteractionCharacter::MoveRight(float Axis)
{
	AddMovementInput(UKismetMathLibrary::GetRightVector(GetControlRotation()), Axis);
}

void AInteractionCharacter::TryInteract()
{
	PlayerInteractionComponent->TryInteract();
}
