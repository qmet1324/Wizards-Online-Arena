// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WPistolBase.generated.h"

UCLASS()
class WIZARDSONLINEARENA_API AWPistolBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWPistolBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//TODO GUNS CLASSES////////////////

	UPROPERTY(EditAnywhere)
		int ammo;

	/*UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ABullet> Bullet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation;

	class UAnimInstance* AnimInstance;

	class UWorld* World;

	FRotator SpawnRotation;
	FVector SpawnLocation;*/

	//////////////////////////////////
};
