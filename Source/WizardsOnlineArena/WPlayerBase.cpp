// Fill out your copyright notice in the Description page of Project Settings.


#include "WPlayerBase.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AWPlayerBase::AWPlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(40.f, 95.0f);

	TurnRate = 45.0f;
	LookUpRate = 45.0f;

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->AddRelativeLocation(FVector(-39.65f, 1.75f, 64.0f));
	FirstPersonCamera->bUsePawnControlRotation = true;

	HandsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Character Mesh"));
	HandsMesh->SetOnlyOwnerSee(true);
	HandsMesh->SetupAttachment(FirstPersonCamera);
	HandsMesh->bCastDynamicShadow = false;
	HandsMesh->CastShadow = false;
	HandsMesh->AddRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	HandsMesh->AddRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	Gun->SetOnlyOwnerSee(true);
	Gun->bCastDynamicShadow = false;
	Gun->CastShadow = false;

	MuzzleLocation = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Muzzle Location"));
	MuzzleLocation->SetupAttachment(Gun);
	MuzzleLocation->SetRelativeLocation(FVector(-0.2f, 48.4f, -10.6f));

	GunOffset = FVector(100.0f, 0.0f, 10.0f);
}

// Called when the game starts or when spawned
void AWPlayerBase::BeginPlay()
{
	Super::BeginPlay();

	Gun->AttachToComponent(HandsMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
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
void AWPlayerBase::TurnAtRate(float xRate)
{
}
void AWPlayerBase::LookAtRate(float yRate)
{
}

// Crouching Calls
void AWPlayerBase::StartCrouch()
{
	Crouch();
}

void AWPlayerBase::StopCrouch()
{
	UnCrouch();
}
void AWPlayerBase::OnFire()
{
}
