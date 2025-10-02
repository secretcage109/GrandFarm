// PlantManager.h
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantActor.h"
#include "PlantManager.generated.h"

UCLASS()
class TESTMAP_API APlantManager : public AActor
{
    GENERATED_BODY()

public:
    APlantManager();

    // Spawn할 PlantActor Class
    UPROPERTY(EditAnywhere, Category = "Plant")
    TSubclassOf<APlantActor> PlantClass;

    // 심어진 모든 PlantActor 관리
    UPROPERTY()
    TArray<APlantActor*> PlantedPlants;

    // 플레이어가 클릭한 위치에 식물 심기
    UFUNCTION(BlueprintCallable, Category = "Plant")
    void PlantSeed(FVector Location);
};
