// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_clearblackboardvalue.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_clearblackboardvalue::UBTTask_clearblackboardvalue()
{
	NodeName = TEXT("clear blackboard value");
}

EBTNodeResult::Type UBTTask_clearblackboardvalue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	UBlackboardComponent* blackboard=OwnerComp.GetBlackboardComponent();
	if (blackboard) {
		blackboard->ClearValue(GetSelectedBlackboardKey());

	}
	return EBTNodeResult::Succeeded;
}
