// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHud.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDSONLINEARENA_API UPlayerHud : public UUserWidget
{
	GENERATED_BODY()

public:

	// Update HUD wth current health
	void SetHealth(float CurrentHealth, float MaxHealth);

		// Widget to use to display current health
	UPROPERTY(EditAnywhere, meta = (BindWidget));
	class UProgressBar* HealthBar;
	
};
