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

	void OnFire();
	void OnReload();
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

	// Gun Class (Not Implemented Yet)
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Weapon)
		TSubclassOf<class AWPistolBase>Pistol;

	UPROPERTY(VisibleDefaultsOnly)
		class UChildActorComponent* Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Ammo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Health;

	UPROPERTY(EditAnywhere, Category = Weapon)
		float damageValue;

	UPROPERTY(EditAnywhere, Category = Weapon)
		float reloadTime;

	UPROPERTY(EditAnywhere, Category = Weapon)
		float fireRate;

	UPROPERTY(EditAnywhere, Category = Weapon)
		FTimerHandle timerFire;

	UPROPERTY(EditAnywhere, Category = Weapon)
		FTimerHandle timerReload;

	UPROPERTY(EditAnywhere, Category = Weapon)
		bool isAuto;

	UPROPERTY(EditAnywhere, Category = Weapon)
		bool isReloading;

	UPROPERTY(EditAnywhere, Category = Weapon)
		float maxRange;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ABullet> Bullet;

	// Sounds and Animations
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

	// Projectile Spawn Variables
	FRotator SpawnRotation;
	FVector SpawnLocation;

};
