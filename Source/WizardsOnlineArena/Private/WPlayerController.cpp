// Fill out your copyright notice in the Description page of Project Settings.


#include "WPlayerController.h"
#include "Blueprint/UserWidget.h"

void AWPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	//Creates a Widget to be added to the player
	UUserWidget* GameEndScreen = CreateWidget(this, GameEndScreenClass);
	if (GameEndScreen != nullptr)
	{
		//Calling this function, will add our GameEndScreenClass to the screen
		GameEndScreen->AddToViewport();
	}
}
