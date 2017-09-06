// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"


// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATile::PlaceActors(TSubclassOf<AActor> ToSpawn, int32 MinSpawn, int32 MaxSpawn, float MinScale, float MaxScale, float Radius)
{
	FVector MinBounds = FVector(0, -2000, 100);
	FVector MaxBounds = FVector(4000, 2000, 100);

	FBox BoxBounds = FBox(MinBounds, MaxBounds);
	FVector SpawnPoint = FMath::RandPointInBox(BoxBounds);

	int32 TotalObjects = FMath::RandRange(MinSpawn, MaxSpawn);
	int32 TotalCasts = 0;
	int32 TotalAttempts = 0;

	// Attempt to spawn without hitting other actors
	while (TotalCasts < TotalObjects)
	{
		FVector SpawnPoint = FMath::RandPointInBox(BoxBounds);
		if (CanSpawnAtLocation(SpawnPoint, Radius)) {
			AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
			Spawned->SetActorRelativeLocation(SpawnPoint);
			Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));

			Spawned->SetActorRotation(FRotator(0, FMath::RandRange(-180, 180), 0));
			Spawned->SetActorScale3D(Spawned->GetActorScale() * FMath::RandRange(MinScale, MaxScale));

			TotalCasts++;
			TotalAttempts = 0;
		}
		else {
			TotalAttempts++;
		}
		if (TotalAttempts > 50) break;
	}
}

bool ATile::CanSpawnAtLocation(FVector Location, float Radius)
{
	FHitResult HitResult;

	// Convert Local to Global
	FVector GLocation = ActorToWorld().TransformPosition(Location);
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		GLocation,
		GLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(Radius)
	);

	//FColor ResultColor = HasHit ? FColor::Red : FColor::Green;
	//DrawDebugSphere(GetWorld(), Location, Radius, 100, ResultColor, true, 100);
	//DrawDebugCapsule(GetWorld(), Location, 0, Radius, FQuat::Identity, ResultColor, true, 100);

	return !HasHit;
}
