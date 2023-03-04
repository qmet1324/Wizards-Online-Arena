// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "..//WPlayerBase.h"
#include "WEnemyChild.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDSONLINEARENA_API AWEnemyChild : public AWPlayerBase
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Dies();

public:

	AWEnemyChild();

	//static const int Zones = 8;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//int EnemiesPerZone = 5;
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int BelongsToZone;
	//
	//static int EnemiesLeft[Zones];
	////static int* EnemiesLeft[Zones];//= { EnemiesPerZone };
	//int EnemiesLeft = { 5 };
	////static int Arraye[5];

	/*UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<int> EnemiesLeft;*/

private:



};
