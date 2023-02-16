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
	
	UFUNCTION(BlueprintCallable)
	void Firing();

	UFUNCTION(BlueprintCallable)
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
		class UStaticMeshComponent* GunMesh;

	UPROPERTY(EditAnywhere, Category = GunProperty)
		int ammo;

	UPROPERTY(EditAnywhere, Category = GunProperty)
		int maxAmmo;

	UPROPERTY(EditAnywhere, Category = GunProperty)
		float damageValue;

	UPROPERTY(EditAnywhere, Category = GunProperty)
		float reloadTime;

	UPROPERTY(EditAnywhere, Category = GunProperty)
		float fireRate;

	UPROPERTY(EditAnywhere)
		FTimerHandle timerFire;

	UPROPERTY(EditAnywhere)
		FTimerHandle timerReload;

	UPROPERTY(EditAnywhere, Category = GunProperty)
		bool isAuto;

	UPROPERTY(EditAnywhere)
		bool isReloading;

	UPROPERTY(EditAnywhere, Category = GunProperty)
		float maxRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffect)
		class USoundBase* fireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimEffect)
		class UAnimMontage* fireAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffect)
		class USoundBase* emptySound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffect)
		class USoundBase* reloadSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimEffect)
		class UAnimMontage* reloadAnimation;

	class UAnimInstance* AnimInstance;

	// Render object in world
	class UWorld* World;
};
