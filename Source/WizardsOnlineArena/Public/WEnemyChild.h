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
	AWEnemyChild();
	
	void Shoot();

	bool IsDead() const;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	/*Override function that tells the GameMode that our enemy has died*/
	//UFUNCTION(BlueprintCallable)
	virtual void OnDeath() override;

	/*This is a property to be set at the engine to tell which zone this enemy belongs*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int BelongsToZone;

	/*UPROPERTY()
		class AWMainGameMode* GameMode;*/

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY()
		AWPistolBase* Gun;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AWPistolBase> GunClass;


};
