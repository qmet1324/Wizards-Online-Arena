// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WPlayerBase.generated.h"


UCLASS()
class WIZARDSONLINEARENA_API AWPlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWPlayerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float yValue);
	void MoveSideways(float xValue);
	void TurnAtRate(float xRate);
	void LookAtRate(float yRate);

	void StartCrouch();
	void StopCrouch();

	UFUNCTION(BlueprintCallable, category = Fire)
		void OnFire();
	void Reload();
	void ResetFireTimer();
	void ResetReloadTimer();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
		
public:

	// Mesh Properties
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* HandsMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Mesh)
		class USkeletalMeshComponent* Gun;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Mesh)
		class USceneComponent* MuzzleLocation;

	// Camera Properties
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* FirstPersonCamera;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera)
		float TurnRate;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera)
		float LookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	// Gun Properties
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
		FTimerHandle TimerFire;

	UPROPERTY(EditAnywhere)
		FTimerHandle TimerReload;

	UPROPERTY(EditAnywhere)
		bool isAuto;

	UPROPERTY(EditAnywhere)
		bool isReloading;

	UPROPERTY(EditAnywhere)
		float maxRange;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ABullet> Bullet;

	// Sounds and Animations
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* EmptySound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* ReloadSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* ReloadAnimation;

	class UAnimInstance* AnimInstance;

	// Render object in world
	class UWorld* World;

	// Standar Gun Class (Not implemented yet)
	class AWPistolBase* Pistol;

	// Projectile Spawn Variables
	FRotator SpawnRotation;
	FVector SpawnLocation;

};
