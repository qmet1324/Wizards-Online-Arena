// Fill out your copyright notice in the Description page of Project Settings.


#include "WEnemyChild.h"
#include "WMainGameMode.h"
#include "Kismet/GameplayStatics.h"

AWEnemyChild::AWEnemyChild()
{
	GameMode = Cast<AWMainGameMode>(UGameplayStatics::GetGameMode(this));
}

void AWEnemyChild::Tick(float DeltaTime)
{

}

void AWEnemyChild::OnDeath()
{
	if (!isDead)
	{
		isDead = true;
		//Creates a GameMode pointer to our AWMainGameMode
		//It needs to use the function GetWorld()->GetAuthGameMode. So we pass our class as the template
		GameMode = GameMode == nullptr ? GetWorld()->GetAuthGameMode<AWMainGameMode>() : GameMode;	//Check if our GameMode was correctly assigned in the class constructor
		if (GameMode != nullptr)	//safety check
		{
			//Tells the GameMode that this enemy that belonged to the specific zone is dead
			GameMode->PawnKilled(this, BelongsToZone);
		}
	}
}
