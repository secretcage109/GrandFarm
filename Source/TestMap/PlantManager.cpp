// PlantManager.cpp
#include "PlantManager.h"
#include "Engine/World.h"

APlantManager::APlantManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void APlantManager::PlantSeed(FVector Location)
{
    if (!PlantClass) return;

    // Spawn parameters
    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;

    // PlantActor »ý¼º
    APlantActor* NewPlant = GetWorld()->SpawnActor<APlantActor>(PlantClass, Location, FRotator::ZeroRotator, SpawnParams);

    if (NewPlant)
    {
        PlantedPlants.Add(NewPlant);
    }
}
