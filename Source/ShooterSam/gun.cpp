// Fill out your copyright notice in the Description page of Project Settings.

#include "gun.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
Agun::Agun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sceneroot= CreateDefaultSubobject<USceneComponent>(TEXT("scene root"));
	SetRootComponent(sceneroot);
	gunmesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("gun mesh"));
	gunmesh->SetupAttachment(sceneroot);
	muzzleflashparticlesystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("muzzle flash"));
	muzzleflashparticlesystem->SetupAttachment(gunmesh);

}

// Called when the game starts or when spawned
void Agun::BeginPlay()
{
	Super::BeginPlay();
	muzzleflashparticlesystem->Deactivate();
	
	
}

// Called every frame
void Agun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Agun::pulltrigger()
{
	if (ownercontroller) {
		muzzleflashparticlesystem->Activate(true);
		UGameplayStatics::PlaySoundAtLocation(GetWorld(),riflesound,GetActorLocation());
		FVector viewpointlocation;
		FRotator viewpointrotation;
		ownercontroller->GetPlayerViewPoint(viewpointlocation, viewpointrotation);
		FVector endlocation = viewpointlocation + viewpointrotation.Vector() * maxrange;
		FCollisionQueryParams params;
		params.AddIgnoredActor(this);
		params.AddIgnoredActor(GetOwner());

		FHitResult hitresult;
		bool ishit=GetWorld()->LineTraceSingleByChannel(hitresult,viewpointlocation,endlocation,ECC_GameTraceChannel2,params);
		if (ishit) {
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),hitparticles, hitresult.Location, hitresult.ImpactPoint.Rotation());
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), impactsound, hitresult.Location);
			AActor* hitactor = hitresult.GetActor();
			if (hitactor) {
				UGameplayStatics::ApplyDamage(hitactor,damage,ownercontroller,this,UDamageType::StaticClass());
			}
		}
	}
}

