// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "WMainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDSONLINEARENA_API AWMainGameMode : public AGameMode
{
	GENERATED_BODY()

private:
	//static AWMainGameMode* instancePtr;
public:
	AWMainGameMode();
	//AWMainGameMode(const AWMainGameMode& obj) = delete;

	/*This function will be called by the enemy when it was killed so the GameMode knows about it*/
	void PawnKilled(APawn* PawnKilled);

	/*It creates a way to populate the class with the items to be spawned (inside unreal)*/
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AMyPickup> SpawnItem;

	/*Variable to control the number of enemies per zone*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int> Zones = { 4,4,4,4 };
};
