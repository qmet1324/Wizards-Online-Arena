// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGun.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AAIGun::AAIGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//This will add a component when generating a BluePrint
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AAIGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

