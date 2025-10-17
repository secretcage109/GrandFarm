// PlantActor.cpp
#include "PlantActor.h"
#include "Components/StaticMeshComponent.h"

APlantActor::APlantActor()
{
    PrimaryActorTick.bCanEverTick = true;

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;
}

void APlantActor::BeginPlay()
{
    Super::BeginPlay();

    // 초기 메시 세팅
    UpdateMesh();

    CurrentStage = 0;

  

 
}

void APlantActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Tick 기준 성장
    UpdateGrowthByTime(DeltaTime);
}

void APlantActor::UpdateGrowthByTime(float DeltaTime)
{
        if (PlantData.GrowthStage >= 3)
        {
            // 이미 다 자랐으면 BP_Soda로 교체 시도
            if (SodaActorClass)
            {
                UWorld* World = GetWorld();
                if (World)
                {
                    FVector Location = GetActorLocation();
                    FRotator Rotation = GetActorRotation();
                    FActorSpawnParameters SpawnParams;
                    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

                    World->SpawnActor<AActor>(SodaActorClass, Location, Rotation, SpawnParams);
                    Destroy();  // 현재 식물 액터 파괴
                }
            }

            return; // 더 이상 성장 진행하지 않음
        }

        // 기존 성장 시간 누적 로직 유지
        ElapsedTime += DeltaTime * GrowthRate;

    // 하루 = 86400초 기준 → 10초 기준 예시
        float DaysPassed = ElapsedTime / 122.f;

        if (DaysPassed >= 3.f)
        {
            PlantData.GrowthStage = 3;
            PlantData.bReadyToHarvest = true;
        }
        else if (DaysPassed >= 2.f)
        {
            PlantData.GrowthStage = 2;
        }
        else if (DaysPassed >= 1.f)
        {
            PlantData.GrowthStage = 1;
        }

        UpdateMesh();
    

}

void APlantActor::UpdateMesh()
{
    if (!MeshComponent) return;

    switch (PlantData.GrowthStage)
    {
    case 0: MeshComponent->SetStaticMesh(SeedMesh); break;
    case 1: MeshComponent->SetStaticMesh(SproutMesh); break;
    case 2: MeshComponent->SetStaticMesh(GrowthMesh); break;
    case 3: MeshComponent->SetStaticMesh(MatureMesh); break;
    default: break;
    }

}
