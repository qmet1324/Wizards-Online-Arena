// Fill out your copyright notice in the Description page of Project Settings.


#include "WMainGameMode.h"
#include "../MyPickup.h"
#include "Math/UnrealMathUtility.h"

AWMainGameMode::AWMainGameMode()
{

}

void AWMainGameMode::PawnKilled(APawn* PawnKilled, int numZone)
{
	/*The next lines is for the item spawn. It gets the location of the PawnKilled, sets a default rotation*/
	FVector Location = PawnKilled->GetActorLocation();
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters MySpawn;	//This struct is created to hold default values for the spawned object
	
	//Subtracts one from the specific zone that the enemy belonged
	Zones[numZone] -= 1;
	UE_LOG(LogTemp, Warning, TEXT("Zones[%d] = %d"), numZone, Zones[numZone]);

	int randomLoot = FMath::RandRange(0,4);


	//If we cleared the Zone
	if (Zones[numZone] == 0)
	{
		/*It will check which zone the enemy belongs, then it will drop the loot that it is assigned inside UE5. Loot number needs to match in UE5*/
		switch (numZone)
		{
		case 0:
			/*This is where the magic happens to spawn the item.
			We are passing the Item blueprint as the first parameter (it needs to be set in the engine!)*/
			GetWorld()->SpawnActor<AMyPickup>(SpawnItem[Loot::HEALTH], Location, Rotation, MySpawn);
			ZonesCleared += 1;
			break;
		case 1:
			GetWorld()->SpawnActor<AMyPickup>(SpawnItem[Loot::SMG], Location, Rotation, MySpawn);
			ZonesCleared += 1;	
			break;
		case 2:
			GetWorld()->SpawnActor<AMyPickup>(SpawnItem[Loot::RIFLE], Location, Rotation, MySpawn);
			ZonesCleared += 1;		
			break;
		case 3:
			GetWorld()->SpawnActor<AMyPickup>(SpawnItem[Loot::BOLT], Location, Rotation, MySpawn);
			ZonesCleared += 1;
			break;
		default:
			break;
		}
	}
	else if (randomLoot == 0)
	{
		GetWorld()->SpawnActor<AMyPickup>(SpawnItem[Loot::HEALTH], Location, Rotation, MySpawn);
	}
	//Since the Enemy died, we can destroy it
	GetWorld()->DestroyActor(PawnKilled);
}

void AWMainGameMode::PawnKilled(APawn* PawnKilled)
{
	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController != nullptr)
	{
		PlayerController->GameHasEnded(nullptr, false);
	}
}

