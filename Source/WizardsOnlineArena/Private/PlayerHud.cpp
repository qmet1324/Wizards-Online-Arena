// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHud.h"
#include "Components/ProgressBar.h"

void UPlayerHud::SetHealth(float CurrentHealth, float MaxHealth)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(CurrentHealth / MaxHealth);
	}
}
