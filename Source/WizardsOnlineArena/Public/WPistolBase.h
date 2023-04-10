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
	
	UFUNCTION(BlueprintCallable /*NetMulticast, reliable, WithValidation*/)
	void Firing();
	void Firing(bool isEnemy);

	//bool Firing_Validate();

	//void Firing_Implementation();

	UFUNCTION(BlueprintCallable)
	void Reloading();

	void FireTimer();
	void ReloadTimer();

	UFUNCTION(BlueprintCallable)
	void CallOverFiring() { 
		Firing(true); 
		ammo--;
	}
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, Category = GunProperty)
		int ammo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GunProperty)
		int maxAmmo;

	UPROPERTY(EditAnywhere, Category = GunProperty)
		float damageValue;

	UPROPERTY(EditAnywhere, Category = GunProperty)
		float reloadTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GunProperty)
		float fireRate;

	UPROPERTY(BlueprintReadOnly)
		FTimerHandle timerFire;

	UPROPERTY(BlueprintReadOnly)
		FTimerHandle timerReload;

	UPROPERTY(EditAnywhere, Category = GunProperty)
		bool isAuto;

	UPROPERTY(BlueprintReadOnly)
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffect)
		class USoundBase* feedbackSound;

	class UAnimInstance* AnimInstance;

	// Render object in world
	class UWorld* World;

	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);

	AController* GetOwnerController() const;
};
