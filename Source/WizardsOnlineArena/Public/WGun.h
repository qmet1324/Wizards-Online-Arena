// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WGun.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WIZARDSONLINEARENA_API UWGun : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWGun();

	void Firing();
	void Reloading();
	void FireTimer();
	void ReloadTimer();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent* Gun;

	UPROPERTY(EditAnywhere)
		USceneComponent* gunRoot;

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
