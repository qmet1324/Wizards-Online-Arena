// Fill out your copyright notice in the Description page of Project Settings.


#include "WMainGameMode.h"
#include "../MyPickup.h"

AWMainGameMode::AWMainGameMode()
{
	//Zones.Add(2);
	//Zones.Add(2);
}

void AWMainGameMode::PawnKilled(APawn* PawnKilled)
{
	UE_LOG(LogTemp, Warning, TEXT("A pawn was killed!"));
	FVector Location = PawnKilled->GetActorLocation();
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters MySpawn;
	GetWorld()->SpawnActor<AMyPickup>(SpawnItem, Location, Rotation, MySpawn);
}

