// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WPlayerBase.h"
#include <Components/ShapeComponent.h>
#include "MyPickup.generated.h"

UCLASS()
class WIZARDSONLINEARENA_API AMyPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere)
	USceneComponent* PickupRoot;

	UPROPERTY(EditAnywhere)
	UShapeComponent* PickupBox;

	UFUNCTION()
	void OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool fFromSweep, const FHitResult& SweepResult);
};
