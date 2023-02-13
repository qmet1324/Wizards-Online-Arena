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
	void Firing();
	void Reloading();
	void FireTimer();
	void ReloadTimer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent* Gun;

	UPROPERTY(EditAnywhere)
		int ammo;

	UPROPERTY(EditAnywhere)
		int maxAmmo;

	UPROPERTY(EditAnywhere)
		float damageValue;

	UPROPERTY(EditAnywhere)
		float reloadTime;

	UPROPERTY(EditAnywhere)
		float fireRate;

	UPROPERTY(EditAnywhere)
		FTimerHandle timerFire;

	UPROPERTY(EditAnywhere)
		FTimerHandle timerReload;

	UPROPERTY(EditAnywhere)
		bool isAuto;

	UPROPERTY(EditAnywhere)
		bool isReloading;

	UPROPERTY(EditAnywhere)
		float maxRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		class USoundBase* fireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		class UAnimMontage* fireAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		class USoundBase* emptySound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		class USoundBase* reloadSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		class UAnimMontage* reloadAnimation;

	class UAnimInstance* AnimInstance;

	// Render object in world
	class UWorld* World;
};
