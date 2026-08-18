// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "gun.generated.h"

UCLASS()
class SHOOTERSAM_API Agun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Agun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* gunmesh;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* sceneroot;
	UPROPERTY(EditAnywhere)
	float maxrange = 10000;
	UPROPERTY(VisibleAnywhere)
	UNiagaraComponent* muzzleflashparticlesystem;
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* hitparticles;
	UPROPERTY(EditAnywhere)
	float damage = 10.0f;
	UPROPERTY(EditAnywhere,Category="sound")
	USoundBase* riflesound;
	UPROPERTY(EditAnywhere, Category = "sound")
	USoundBase* impactsound;
	AController* ownercontroller;
	void pulltrigger();

};
