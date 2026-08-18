// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_shoot.h"
#include "shooterai.h"

UBTTaskNode_shoot::UBTTaskNode_shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTaskNode_shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type result = EBTNodeResult::Failed;
	Ashooterai* shooteraiclass = Cast<Ashooterai>(OwnerComp.GetAIOwner());
	if (shooteraiclass) {
		AShooterSamCharacter* aicharacter = shooteraiclass->aicharacter;
		AShooterSamCharacter* playercharacter = shooteraiclass->playercharacter;
		if (aicharacter&&playercharacter&&playercharacter->isalive) {
			aicharacter->shoot();
			result = EBTNodeResult::Succeeded;
		}
	}
	return result;
}
