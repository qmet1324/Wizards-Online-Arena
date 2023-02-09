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
	void Reload();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
		
public:

	// Mesh Properties
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* HandsMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* Gun;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* MuzzleLocation;

	// Camera Properties
	UPROPERTY(VisibleDefaultsOnly, Category = Camera)
		class UCameraComponent* FirstPersonCamera;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera)
		float TurnRate;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera)
		float LookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	UPROPERTY(EditAnywhere)
		int bullets;

};
