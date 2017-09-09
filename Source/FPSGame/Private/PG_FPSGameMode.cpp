// Fill out your copyright notice in the Description page of Project Settings.

#include "PG_FPSGameMode.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"


APG_FPSGameMode::APG_FPSGameMode()
{
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("Nav Mesh Bounds Volume Pool"));
}

void APG_FPSGameMode::AddToPool(ANavMeshBoundsVolume * VolumeToAdd)
{
	//UE_LOG(LogTemp, Warning, TEXT("Found Actor: %s"), *ANavMeshBoundsVolume->GetName());
	NavMeshBoundsVolumePool->Add(VolumeToAdd);
}

void APG_FPSGameMode::PopulateBoundsVolumePool()
{
	TActorIterator<ANavMeshBoundsVolume> NavMeshVolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (NavMeshVolumeIterator)
	{
		AddToPool(*NavMeshVolumeIterator);
		++NavMeshVolumeIterator;
	}
}

