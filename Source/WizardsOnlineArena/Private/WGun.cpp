// Fill out your copyright notice in the Description page of Project Settings.


#include "WGun.h"

#include "Animation/AnimInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UWGun::UWGun()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Gun = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gun"));
	Gun->SetOnlyOwnerSee(true);
	Gun->bCastDynamicShadow = false;
	Gun->CastShadow = false;

	maxAmmo = 15;
	ammo = maxAmmo;
	damageValue = 20.0f;
	reloadTime = 2.0f;
	fireRate = 0.2f;
	maxRange = 1000.0f;
}

void UWGun::Firing()
{
}

void UWGun::Reloading()
{
}

void UWGun::FireTimer()
{
}

void UWGun::ReloadTimer()
{
}


// Called when the game starts
void UWGun::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
	
}


// Called every frame
void UWGun::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

