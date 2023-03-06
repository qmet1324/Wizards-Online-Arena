// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WMainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDSONLINEARENA_API AWMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

private:
	//static AWMainGameMode* instancePtr;
public:
	AWMainGameMode();
	//AWMainGameMode(const AWMainGameMode& obj) = delete;
	void PawnKilled(APawn* PawnKilled);

	UPROPERTY(EditAnywhere)
		TSubclassOf<class AMyPickup> SpawnItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int> Zones = { 4,4,4,4 };
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int ZoneOne = 4;
};
