// Fill out your copyright notice in the Description page of Project Settings.


#include "WEnemyChild.h"
#include "WMainGameMode.h"

AWEnemyChild::AWEnemyChild()
{

}

void AWEnemyChild::Tick(float DeltaTime)
{

}

void AWEnemyChild::OnDeath()
{
	if (!isDead)
	{
		//Creates a GameMode pointer to our AWMainGameMode
		//It needs to use the function GetWorld()->GetAuthGameMode. So we pass our class as the template
		AWMainGameMode* GameMode = GetWorld()->GetAuthGameMode<AWMainGameMode>();
		if (GameMode != nullptr)	//safety check
		{
			GameMode->PawnKilled(this);	//Calls the PawnKilled function and passes this Pawn as a parameter
		}

		//Tells the GameMode that this enemy that belonged to the specific zone is dead
		//BUG WHEN THE OTHER Client kills it
		GameMode->Zones[BelongsToZone] -= 1;

		isDead = true;
	}
}
