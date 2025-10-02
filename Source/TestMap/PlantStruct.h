#pragma once

#include "CoreMinimal.h"
#include "PlantStruct.generated.h"

USTRUCT(BlueprintType)
struct FPlantGrowthData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;               // ½Ä¹° ÀÌ¸§

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 GrowthStage = 0;      // 0: ¾¾¾Ñ, 1: »õ½Ï, 2: ¼ºÀå, 3: ¼º¼÷

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 PlantedDay = 0;       // ½ÉÀº ³¯

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bReadyToHarvest = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bWatered = false;
};