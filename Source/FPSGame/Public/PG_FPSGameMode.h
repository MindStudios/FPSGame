// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSGameGameMode.h"
#include "PG_FPSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API APG_FPSGameMode : public AFPSGameGameMode
{
	GENERATED_BODY()
	
public:
	APG_FPSGameMode();

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	class UActorPool* NavMeshBoundsVolumePool;

private:
	void AddToPool(class ANavMeshBoundsVolume* VolumeToAdd);
	
};
