// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"


// NOT USED, CREATED FOR EDUCATION PURPOSES
USTRUCT(BlueprintType)
struct FSpawnInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Info")
	int32 MinSpawn = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Info")
	int32 MaxSpawn = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Info")
	float MinScale = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Info")
	float MaxScale = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Info")
	float Radius = 500;
};


class UActorPool;

UCLASS()
class FPSGAME_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable, Category = "Setup")
	void PlaceActors(TSubclassOf<AActor> ToSpawn, int32 MinSpawn, int32 MaxSpawn, float MinScale, float MaxScale, float Radius);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void PlaceAIPawns(TSubclassOf<APawn> ToSpawn, int32 MinSpawn, int32 MaxSpawn, float Radius);

	UFUNCTION(BlueprintCallable, Category = "Pool")
	void SetPool(UActorPool* Pool);

	void PositionNavMeshBoundsVolume(UActorPool * Pool);

	UFUNCTION(BlueprintCallable, Category = "Pool")
	UActorPool* GetPool();

	UPROPERTY(EditDefaultsOnly, Category = "Pool")
	FVector MinBounds = FVector(0, -2000, 100);

	UPROPERTY(EditDefaultsOnly, Category = "Pool")
	FVector MaxBounds = FVector(4000, 2000, 100);

	UPROPERTY(EditDefaultsOnly, Category = "Pool")
	FVector NavBoundsOffset = FVector(2000, 0, 0);

private:
	bool CanSpawnAtLocation(FVector Location, float Radius);

	AActor* NavMeshBoundsVolume;
	UActorPool* NavMeshBoundsVolumePool;
	
};
