// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TZEnemy.generated.h"

class USkeletalMeshComponent;

USTRUCT()
struct DREAMSIDETZ_API FBoneWithMultiplier
{
	GENERATED_USTRUCT_BODY();

	FBoneReference Bone;
	float Multiplier = 0.1f;

};


USTRUCT(BlueprintType)
struct DREAMSIDETZ_API FArrayContainer
{
	GENERATED_USTRUCT_BODY();

	TArray<FBoneWithMultiplier> BonesToScaleArray;
};


UCLASS()
class DREAMSIDETZ_API ATZEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATZEnemy();

	UPROPERTY(BlueprintReadOnly)
	FArrayContainer BonesToScaleContainer;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void UpdateBonesToScale(FName InBomeName);

	UFUNCTION(BlueprintNativeEvent)
	void UpdateBonesToScaleContainer();

private:

	TArray<FBoneWithMultiplier> TemporaryBonesToScaleArray;

};
