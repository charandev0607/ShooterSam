// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_clearblackboardvalue.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERSAM_API UBTTask_clearblackboardvalue : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTTask_clearblackboardvalue();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
