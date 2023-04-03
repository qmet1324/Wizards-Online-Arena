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

	void OnReload();

	UFUNCTION()
	virtual void OnDeath();
	void Respawn();


public:	
	virtual void OnFire();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
		
public:

	// Mesh Properties
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Mesh)
		class USkeletalMeshComponent* HandsMesh;

	// Camera Properties
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* FirstPersonCamera;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera)
		float TurnRate;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera)
		float LookUpRate;

	//UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Mesh)
	//	class USkeletalMeshComponent* Gun;
	
	//UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Mesh)
	//	class USceneComponent* MuzzleLocation;
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	//	FVector GunOffset;

	//UPROPERTY(EditDefaultsOnly, Category = Projectile)
	//	TSubclassOf<class ABullet> Bullet;

	// Gun Objects
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Weapon)
		TSubclassOf<class AWPistolBase>Pistol;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		class UChildActorComponent* Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Ammo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MaxAmmo;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStat)
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffect)
		class USoundBase* damageTakenSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SoundEffect)
		class USoundBase* deathSound;

	bool isDead;

	float respawnDelay;

	class UAnimInstance* AnimInstance;

	// Render object in world
	class UWorld* World;

	// Projectile Spawn Variables
	//FRotator SpawnRotation;
	//FVector SpawnLocation;

	void DamageTaken(float damageAmount);
	//float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
	UPROPERTY()
		class AWMainGameMode* GameMode;
};
