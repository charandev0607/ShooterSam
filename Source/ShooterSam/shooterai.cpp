// Fill out your copyright notice in the Description page of Project Settings.


#include "shooterai.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void Ashooterai::BeginPlay()
{
	Super::BeginPlay();
	
}

void Ashooterai::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	APawn* playerpawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (playerpawn) {
		if (LineOfSightTo(playerpawn)) {
			SetFocus(playerpawn);
			MoveToActor(playerpawn,200.0f);
		}
		else {
			ClearFocus(EAIFocusPriority::Gameplay);
			StopMovement();
		}
	}
	*/

}

void Ashooterai::runbt(AShooterSamCharacter* player)
{
	if (enemyaibt) {
		aicharacter = Cast< AShooterSamCharacter>(GetPawn());
		if (player) {
			playercharacter = player;
		}
		RunBehaviorTree(enemyaibt);
		UBlackboardComponent* blackboard = GetBlackboardComponent();
		if (blackboard &&playercharacter&&aicharacter) {
			blackboard->SetValueAsVector("aistartloc", aicharacter->GetActorLocation());
		}
}

}
