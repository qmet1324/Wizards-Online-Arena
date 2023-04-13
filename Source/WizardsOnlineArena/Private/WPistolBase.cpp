// Fill out your copyright notice in the Description page of Project Settings.


#include "WPistolBase.h"
#include "Base_AIController.h"

#include "Components/StaticMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../WPlayerBase.h"

// Sets default values
AWPistolBase::AWPistolBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	maxAmmo = 30;
	damageValue = 30.0f;
	reloadTime = 3.0f;
	fireRate = 0.05f;
	maxRange = 10000.0f;
}

// Called when the game starts or when spawned
void AWPistolBase::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();

	ammo = maxAmmo;
}

// Called every frame
void AWPistolBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWPistolBase::Firing()
{
	if (World != NULL)
	{
		if (ammo > 0)
		{
			if (!GetWorldTimerManager().IsTimerActive(timerFire) && !isReloading)
			{

				// Posible Hitscan code? Needs more testing.
				FVector cameraLocation;
				FRotator cameraRotation;
				GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(cameraLocation, cameraRotation);

				// Calculate the hit trace
				FVector raycastTrace = cameraLocation + (cameraRotation.Vector() * maxRange);
				
				//Set up the trace parameters
				FCollisionQueryParams traceParams;
				traceParams.AddIgnoredActor(this);
				traceParams.bTraceComplex = true;
				traceParams.bReturnPhysicalMaterial = true;

				FHitResult hitResults;
				if (GetWorld()->LineTraceSingleByChannel(hitResults, cameraLocation + (cameraRotation.Vector() * 100), raycastTrace, ECC_WorldDynamic, traceParams))
				{
					AWPlayerBase* enemyPlayer = Cast<AWPlayerBase>(hitResults.GetActor());

					if (enemyPlayer)
					{
						enemyPlayer->DamageTaken(damageValue);
						if (feedbackSound != NULL)
						{
							UGameplayStatics::PlaySoundAtLocation(this, feedbackSound, GetActorLocation());
						}
					}
				}

				if (GetWorld() != NULL)
				{
					//DrawDebugLine(GetWorld(), cameraLocation + (cameraRotation.Vector() * 100), raycastTrace, FColor::Blue, false, 10.0f, 0, 5.0f);
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

				GetWorldTimerManager().SetTimer(timerFire, this, &AWPistolBase::FireTimer, fireRate, false);
			}
		}

		else
		{
			if (emptySound != NULL && !isReloading)
			{
				UGameplayStatics::PlaySoundAtLocation(this, emptySound, GetActorLocation());
			}
		}
	}
}

//Overloaded Function
void AWPistolBase::Firing(bool isEnemy)
{
	//UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
	//UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));
	UE_LOG(LogTemp, Warning, TEXT("AI is firing"));
	FHitResult Hit;
	FVector ShotDirection;
	bool bSuccess = GunTrace(Hit, ShotDirection);
	if (bSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI HIT"));
		//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());
		//UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, Hit.Location);

		AActor* HitActor = Hit.GetActor();
		if (HitActor != nullptr)
		{
			FPointDamageEvent DamageEvent(damageValue, Hit, ShotDirection, nullptr);
			AController* OwnerController = GetOwnerController();
			HitActor->TakeDamage(damageValue, DamageEvent, OwnerController, this);
		}
	}
}


void AWPistolBase::Reloading()
{
	if (ammo != maxAmmo)
	{
		if (!GetWorldTimerManager().IsTimerActive(timerReload))
		{
			isReloading = true;

			if (reloadSound != NULL)
			{
				UGameplayStatics::PlaySoundAtLocation(this, reloadSound, GetActorLocation());
			}

			if (reloadAnimation != NULL && AnimInstance != NULL)
			{
				AnimInstance->Montage_Play(reloadAnimation, 1.0f);
			}

			GetWorldTimerManager().SetTimer(timerReload, this, &AWPistolBase::ReloadTimer, reloadTime, false);
		}
	}
}

bool AWPistolBase::GunTrace(FHitResult& Hit, FVector& ShotDirection)
{
	AController* OwnerController = GetOwnerController();
	
	if (OwnerController == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("GUNTRACE -> OwnerController == nullptr"));
		return false;
	}

	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	ShotDirection = -Rotation.Vector();

	FVector End = Location + Rotation.Vector() * maxRange;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	UE_LOG(LogTemp, Warning, TEXT("AI TRIED"));
	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

AController* AWPistolBase::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("OwnerPawn == nullptr"));
		return nullptr;
	}
	return OwnerPawn->GetController();
}



void AWPistolBase::FireTimer()
{
	GetWorldTimerManager().ClearTimer(timerFire);
}

void AWPistolBase::ReloadTimer()
{
	ammo = maxAmmo;
	isReloading = false;
	GetWorldTimerManager().ClearTimer(timerReload);
}

