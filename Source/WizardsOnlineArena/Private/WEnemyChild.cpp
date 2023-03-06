// Fill out your copyright notice in the Description page of Project Settings.


#include "WEnemyChild.h"


AWEnemyChild::AWEnemyChild()
{

}

void AWEnemyChild::Tick(float DeltaTime)
{

}

void AWEnemyChild::Dies()
{
	//AWEnemyChild::EnemiesLeft[1] -= 1;
}

bool AWEnemyChild::DropLoot()
{
	/*for (int i = 0; i < Zones; i++)
	{
		if (EnemiesLeft[i] <= 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("YOU HAVE WON"));
			return true;
		}
	}*/

	return false;
}
