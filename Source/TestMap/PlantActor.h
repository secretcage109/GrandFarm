// PlantActor.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantStruct.h"
#include "PlantActor.generated.h"


UCLASS()
class TESTMAP_API APlantActor : public AActor
{
    GENERATED_BODY()

public:
    APlantActor();

    // -----------------------
    // 성장 관련
    // -----------------------
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Growth")
    FPlantGrowthData PlantData;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Growth")
    UStaticMeshComponent* MeshComponent;

    // 스테이지별 메시 (블루프린트에서 설정)
    UPROPERTY(EditAnywhere, Category = "Growth")
    UStaticMesh* SeedMesh;

    UPROPERTY(EditAnywhere, Category = "Growth")
    UStaticMesh* SproutMesh;

    UPROPERTY(EditAnywhere, Category = "Growth")
    UStaticMesh* GrowthMesh;

    UPROPERTY(EditAnywhere, Category = "Growth")
    UStaticMesh* MatureMesh;

    // -----------------------
    // 성장 시간 관련
    // -----------------------
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Growth")
    float GrowthRate = 1.f; // 하루 기준 성장 속도

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Growth")
    float ElapsedTime = 0.f; // Tick으로 누적되는 시간

    UFUNCTION(BlueprintCallable, Category = "Growth")
    void UpdateGrowthByTime(float DeltaTime);

    UFUNCTION(BlueprintCallable, Category = "Growth")
    void UpdateMesh();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;


    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Growth")
    int32 CurrentStage;
    
    // PlantActor.h

   // BP_Soda 클래스를 에디터에서 지정할 수 있게 하기
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Growth")
    TSubclassOf<AActor> SodaActorClass;


};
