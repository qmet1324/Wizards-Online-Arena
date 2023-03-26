// Fill out your copyright notice in the Description page of Project Settings.


#include "WPistolBase.h"

#include "Components/StaticMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../WPlayerBase.h"
#include "ObjectTemplates/DatasmithActorTemplate.h"

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
void AWPistolBase::Firing_Implementation()
{
	if (World != NULL)
	{
		if (ammo > 0)
		{
			if (!GetWorldTimerManager().IsTimerActive(timerFire) && !isReloading)
			{
				AActor* Shooter = GetOwner();
				if (!Shooter) { return; }
				// Posible Hitscan code? Needs more testing.
				FVector cameraLocation;
				FRotator cameraRotation;
				//GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(cameraLocation, cameraRotation);
				//user.GetPlayerViewPoint(cameraLocation, cameraRotation);
				cameraRotation = Shooter->GetActorRotation();
				cameraLocation = Shooter->GetActorLocation();
				// Calculate the hit trace
				FVector raycastTrace = cameraLocation + (cameraRotation.Vector() * maxRange);
				
				//Set up the trace parameters
				FCollisionQueryParams traceParams;
				traceParams.AddIgnoredActor(this);
				traceParams.bTraceComplex = true;
				traceParams.bReturnPhysicalMaterial = true;

				FHitResult hitResults;
				if (GetWorld()->LineTraceSingleByChannel(hitResults, cameraLocation, raycastTrace, ECC_WorldDynamic, traceParams))
				{
					AWPlayerBase* enemyPlayer = Cast<AWPlayerBase>(hitResults.GetActor());

					if (enemyPlayer)
					{
						enemyPlayer->DamageTaken(damageValue);
					}
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

void AWPistolBase::Reloading()
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

			GetWorldTimerManager().SetTimer(timerReload, this, &AWPistolBase::ReloadTimer, reloadTime, false);
		}
	}
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

