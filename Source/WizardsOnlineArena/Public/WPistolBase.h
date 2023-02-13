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
	
	// Placeholders for now, maybe immplement the shooting code in the gun class instead of the player class
	void Shoot();
	void Reload();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//TODO GUNS CLASSES////////////////
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* Gun;

	UPROPERTY(EditAnywhere)
		int ammo;

	UPROPERTY(EditAnywhere)
		float damageValue;

	UPROPERTY(EditAnywhere)
		float reloadTime;

	UPROPERTY(EditAnywhere)
		float fireRate;

	UPROPERTY(EditAnywhere)
		FTimerHandle TimerFire;

	UPROPERTY(EditAnywhere)
		FTimerHandle TimerReload;

	UPROPERTY(EditAnywhere)
		bool isAuto;

	UPROPERTY(EditAnywhere)
		float maxRange;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ABullet> Bullet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* ReloadSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* ReloadAnimation;
	//////////////////////////////////
};
