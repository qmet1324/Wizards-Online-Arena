// Fill out your copyright notice in the Description page of Project Settings.


#include "WPlayerBase.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "WPistolBase.h"

#include "Bullet.h"
#include "Animation/AnimInstance.h"
#include "Kismet/GameplayStatics.h"

#include "WMainGameMode.h"


// Sets default values
AWPlayerBase::AWPlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(40.f, 95.0f);

	TurnRate = 45.0f;
	LookUpRate = 45.0f;

	// Ammo
	MaxAmmo = 15;
	Ammo = MaxAmmo;

	// Player health
	Health = 100.0f;

	// Setting Up Camera
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->AddRelativeLocation(FVector(-39.65f, 1.75f, 64.0f));
	FirstPersonCamera->bUsePawnControlRotation = true;

	// Setting Up the hands mesh
	HandsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Character Mesh"));
	HandsMesh->SetOnlyOwnerSee(true);
	HandsMesh->SetupAttachment(FirstPersonCamera);
	HandsMesh->bCastDynamicShadow = false;
	HandsMesh->CastShadow = false;
	HandsMesh->AddRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	HandsMesh->AddRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	// Setting up the gun 
	Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	Gun->SetOnlyOwnerSee(true);
	Gun->bCastDynamicShadow = false;
	Gun->CastShadow = false;

	// Muzzle code, its currently used for a projectile based gun, but we can use it in the future
	// for displaying effects coming directly from the muzzle of the gun.
	MuzzleLocation = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Muzzle Location"));
	MuzzleLocation->SetupAttachment(Gun);
	MuzzleLocation->SetRelativeLocation(FVector(-0.2f, 48.4f, -10.6f));

	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	//Pistol = CreateDefaultSubobject<AWPistolBase>(TEXT("Current Pistol"));
}

// Called when the game starts or when spawned
void AWPlayerBase::BeginPlay()
{
	Super::BeginPlay();

	Gun->AttachToComponent(HandsMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));

	World = GetWorld();

	AnimInstance = HandsMesh->GetAnimInstance();

	maxAmmo = 15;
	ammo = maxAmmo;
	damageValue = 20.0f;
	reloadTime = 2.0f;
	fireRate = 0.2f;
	maxRange = 1000.0f;
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
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &AWPlayerBase::StopJumping);

	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Pressed, this, &AWPlayerBase::StartCrouch);
	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Released, this, &AWPlayerBase::StopCrouch);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &AWPlayerBase::OnFire);
	PlayerInputComponent->BindAction(TEXT("Reload"), IE_Pressed, this, &AWPlayerBase::OnReload);
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

// Camera Calls (Smoother camera)
void AWPlayerBase::TurnAtRate(float xRate)
{
	//TODO
}
void AWPlayerBase::LookAtRate(float yRate)
{
	//TODO
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
	if (World != NULL)
	{
		if (Ammo > 0)
		{
			if (!GetWorldTimerManager().IsTimerActive(timerFire) && !isReloading)
			{
				// Code to spawn Porjectlie Object (currently spawning object but not it's mesh)
				
				//SpawnRotation = GetControlRotation();
				//
				//if (MuzzleLocation != nullptr)
				//{
				//	SpawnLocation = MuzzleLocation->GetComponentLocation();
				//}
				//else
				//{
				//	SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(GunOffset);
				//}
				//
				//
				//
				//FActorSpawnParameters ActorSpawnParams;
				//ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
				//
				//World->SpawnActor<ABullet>(Bullet, SpawnLocation, SpawnRotation, ActorSpawnParams);
				
				//------------------------------------------------------------------------------//

				// Posible Hitscan code? Needs more testing.
				FVector cameraLocation;
				FRotator cameraRotation;
				GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(cameraLocation, cameraRotation);

				// Calculate the hit trace
				FVector raycastTrace = cameraLocation + (cameraRotation.Vector() * maxRange);

				//Set up the trace parameters
				FCollisionQueryParams traceParams;
				traceParams.AddIgnoredActor(this);

				FHitResult hitResults;
				if (GetWorld()->LineTraceSingleByChannel(hitResults, cameraLocation, raycastTrace, ECC_Visibility, traceParams))
				{
					//TODO (Damage to enemies or bullet marks in walls?)
				}

				if (GetWorld() != NULL)
				{
					DrawDebugLine(GetWorld(), cameraLocation, raycastTrace, FColor::Blue, false, 10.0f, 0, 5.0f);
				}
				
				// Fire Sound Effect
				if (fireSound != NULL)
				{
					UGameplayStatics::PlaySoundAtLocation(this, fireSound, GetActorLocation());
				}

				// Fire Animation (Not working properly, will be replaced with other animations eventually)
				if (fireAnimation != NULL && AnimInstance != NULL)
				{
					AnimInstance->Montage_Play(fireAnimation, 10.0f);
				}

				ammo--;
				Ammo--;

				GetWorldTimerManager().SetTimer(timerFire, this, &AWPlayerBase::ResetFireTimer, fireRate, false);
			}
		}

		else
		{
			if (emptySound != NULL && !isReloading)
			{
				UGameplayStatics::PlaySoundAtLocation(this, emptySound, GetActorLocation());
			}

			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			World->SpawnActor<ABullet>(Bullet, SpawnLocation, SpawnRotation, ActorSpawnParams);

			if (FireSound != NULL)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			if (FireAnimation != NULL && AnimInstance != NULL)
			{
				AnimInstance->Montage_Play(FireAnimation, 1.0f);
			}
		}
	}

	//Pistol->Firing();
}

void AWPlayerBase::OnReload()
{

	if (ammo != maxAmmo)
	{
		if (!GetWorldTimerManager().IsTimerActive(timerReload))
		{
			isReloading = true;

			if (fireSound != NULL)
			{
				UGameplayStatics::PlaySoundAtLocation(this, reloadSound, GetActorLocation());
			}

			if (reloadAnimation != NULL && AnimInstance != NULL)
			{
				AnimInstance->Montage_Play(reloadAnimation, 1.0f);
			}

			GetWorldTimerManager().SetTimer(timerReload, this, &AWPlayerBase::ResetReloadTimer, reloadTime, false);
		}
	}

	//Pistol->Reloading();
}

void AWPlayerBase::ResetFireTimer()
{
	GetWorldTimerManager().ClearTimer(timerFire);
}

void AWPlayerBase::ResetReloadTimer()
{
	ammo = maxAmmo;
	Ammo = MaxAmmo;
	isReloading = false;
	GetWorldTimerManager().ClearTimer(timerReload);
}
	
}
