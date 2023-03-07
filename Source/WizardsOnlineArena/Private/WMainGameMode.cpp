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
	/*The next lines is for the item spawn. It gets the location of the PawnKilled, sets a default rotation*/
	FVector Location = PawnKilled->GetActorLocation();
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters MySpawn;	//This struct is created to hold default values for the spawned object

	/*This is where the magic happens to spawn the item.
	We are passing the Item blueprint as the first parameter (it needs to be set in the engine!)*/
	GetWorld()->SpawnActor<AMyPickup>(SpawnItem, Location, Rotation, MySpawn);
	//Since the Enemy died, we can destroy it
	GetWorld()->DestroyActor(PawnKilled);
}

