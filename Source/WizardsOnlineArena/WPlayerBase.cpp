// Fill out your copyright notice in the Description page of Project Settings.

#include "WPlayerBase.h"
#include "PlayerHud.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AWPlayerBase::AWPlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	health = 50.0f;

	//HUD
	PlayerHUDClass = nullptr;
	PlayerHUD = nullptr;
}

// Called when the game starts or when spawned
void AWPlayerBase::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocallyControlled() && PlayerHUDClass)
	{
		APlayerController* FPC = GetController<APlayerController>();
		PlayerHUD = CreateWidget<UPlayerHud>(FPC, PlayerHUDClass);
		check(PlayerHUD);
		PlayerHUD->AddToPlayerScreen();
	}
}

void AWPlayerBase::EndPlay(const EEndPlayReason::Type EnPlayReason)
{
	if (PlayerHUD)
	{
		PlayerHUD->RemoveFromParent();
		PlayerHUD = nullptr;
	}

	Super::EndPlay(EnPlayReason);
}

// Called every frame
void AWPlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWPlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Player Inputs for Movement Functions. (Axis and Actions selected in the project preferences).
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AWPlayerBase::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveSideways"), this, &AWPlayerBase::MoveSideways);
	PlayerInputComponent->BindAxis(TEXT("LookX"), this, &AWPlayerBase::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookY"), this, &AWPlayerBase::AddControllerPitchInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AWPlayerBase::Jump);
	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Pressed, this, &AWPlayerBase::StartCrouch);
	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Released, this, &AWPlayerBase::StopCrouch);

}

// Movement Calls
void AWPlayerBase::MoveForward(float yMove)
{
	AddMovementInput(GetActorForwardVector() * yMove);
}

void AWPlayerBase::MoveSideways(float xMove)
{
	AddMovementInput(GetActorRightVector() * xMove);
}
/////////////////

// Crouching Calls
void AWPlayerBase::StartCrouch()
{
	Crouch();
}

void AWPlayerBase::StopCrouch()
{
	UnCrouch();
}
/////////////////