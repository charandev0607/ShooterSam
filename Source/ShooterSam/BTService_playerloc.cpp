// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_playerloc.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_playerloc::UBTService_playerloc()
{
	NodeName = TEXT("last player loc");
}

void UBTService_playerloc::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	APawn* playerpawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);		//can access player's location etc
	UBlackboardComponent* blackboard = OwnerComp.GetBlackboardComponent();
	if (playerpawn&& blackboard) {
		blackboard->SetValueAsVector(GetSelectedBlackboardKey(), playerpawn->GetActorLocation());
	}
}
 