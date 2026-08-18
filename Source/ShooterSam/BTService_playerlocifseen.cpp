// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_playerlocifseen.h"
#include "shooterai.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_playerlocifseen::UBTService_playerlocifseen()
{
	NodeName = TEXT("update player loc if seen");
}

void UBTService_playerlocifseen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	Ashooterai* shooteraiclass = Cast<Ashooterai>(OwnerComp.GetAIOwner());
	AShooterSamCharacter* player = shooteraiclass->playercharacter;
	UBlackboardComponent* blackboard = OwnerComp.GetBlackboardComponent();
	if (shooteraiclass && player && blackboard) {
		if (shooteraiclass->LineOfSightTo(player)) {
			blackboard->SetValueAsVector(GetSelectedBlackboardKey(), player->GetActorLocation());
			shooteraiclass->SetFocus(player);
		}
		else {
			blackboard->ClearValue(GetSelectedBlackboardKey());
			shooteraiclass->ClearFocus(EAIFocusPriority::Gameplay);
		}
	}
	
}
