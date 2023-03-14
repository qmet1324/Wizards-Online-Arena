// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "AIController.h"
#include "WEnemyChild.h"

//Class constructor
UBTTask_Shoot::UBTTask_Shoot()
{
    NodeName = "Shoot"; //Creates the node name that will appear at the Behavior Tree
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) //Node functionality
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    //Safety step to verify if AI has a Controller
    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    //TODO: Add the attack component
    //Safety step to see if the class was corrected assigned
    AWEnemyChild* Character = Cast<AWEnemyChild>(OwnerComp.GetAIOwner()->GetPawn());
    if (Character == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    Character->OnFire();

    return EBTNodeResult::Succeeded;
}
