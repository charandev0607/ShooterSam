// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterSamGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "ShooterSamCharacter.h"
#include "shooterai.h"

void AShooterSamGameMode::BeginPlay()
{
	AShooterSamCharacter* player = Cast<AShooterSamCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	TArray<AActor*> enemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Ashooterai::StaticClass(),enemies);

	for (AActor* enemy : enemies) {
		Ashooterai* shooterai = Cast<Ashooterai>(enemy);
		if (shooterai) {
			shooterai->runbt(player);
		}
	}
}

AShooterSamGameMode::AShooterSamGameMode()
{
	// stub
}
