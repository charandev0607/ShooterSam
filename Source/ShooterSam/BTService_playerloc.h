// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "shooterai.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_playerloc.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERSAM_API UBTService_playerloc : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTService_playerloc();
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;	

};
