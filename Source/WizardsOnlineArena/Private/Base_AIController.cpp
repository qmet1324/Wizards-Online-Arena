// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_AIController.h"
#include "WEnemyChild.h"
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
		
		//Safety check - this was causing the program to crash when spawning new enemies
		if (GetPawn() != nullptr)
			GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());

		//Setting BlackBoard key values- Uses GetBlackboardComponent to get hold of the key
		//SetValueAsVector - first parameter is KeyName
		//GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	}
}

void ABase_AIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	////Get hold of the pawn player
	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	//if (LineOfSightTo(PlayerPawn))
	//{
	//	//Sets player location
	//	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	//	//Sets last known location
	//	GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
	//}
	//else
	//{
	//	//Clear value inside player location when out of sight
	//	GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
	//}

}

bool ABase_AIController::isDead() const
{
	AWEnemyChild* ControlledCharacter = Cast<AWEnemyChild>(GetPawn());
	if (ControlledCharacter != nullptr)
	{
		return ControlledCharacter->IsDead(); 
	}

	return true;
}
