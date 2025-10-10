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
    // ���� ����
    // -----------------------
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Growth")
    FPlantGrowthData PlantData;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Growth")
    UStaticMeshComponent* MeshComponent;

    // ���������� �޽� (�������Ʈ���� ����)
    UPROPERTY(EditAnywhere, Category = "Growth")
    UStaticMesh* SeedMesh;

    UPROPERTY(EditAnywhere, Category = "Growth")
    UStaticMesh* SproutMesh;

    UPROPERTY(EditAnywhere, Category = "Growth")
    UStaticMesh* GrowthMesh;

    UPROPERTY(EditAnywhere, Category = "Growth")
    UStaticMesh* MatureMesh;

    // -----------------------
    // ���� �ð� ����
    // -----------------------
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Growth")
    float GrowthRate = 1.f; // �Ϸ� ���� ���� �ӵ�

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Growth")
    float ElapsedTime = 0.f; // Tick���� �����Ǵ� �ð�

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

   // BP_Soda Ŭ������ �����Ϳ��� ������ �� �ְ� �ϱ�
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Growth")
    TSubclassOf<AActor> SodaActorClass;


};
