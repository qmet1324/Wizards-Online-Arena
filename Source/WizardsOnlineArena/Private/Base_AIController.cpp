// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_AIController.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void ABase_AIController::BeginPlay()
{
	Super::BeginPlay();

	//Starts the AI Behavior tree
	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);
		//Get hold of the pawn player
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());

		//Setting BlackBoard key values- Uses GetBlackboardComponent to get hold of the key
		//SetValueAsVector - first parameter is KeyName
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	}
}

void ABase_AIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	////Get hold of the pawn player
	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//
	//if (LineOfSightTo(PlayerPawn))
	//{
	//	SetFocus(PlayerPawn);	//Focus on the player
	//	MoveToActor(PlayerPawn, 200);	//Move to the player with 2 meters of distance
	//}
	//else
	//{
	//	ClearFocus(EAIFocusPriority::Gameplay);
	//	StopMovement();
	//}
}