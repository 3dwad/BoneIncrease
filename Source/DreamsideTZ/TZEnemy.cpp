// Fill out your copyright notice in the Description page of Project Settings.


#include "TZEnemy.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ATZEnemy::ATZEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATZEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATZEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATZEnemy::UpdateBonesToScale(FName InBomeName)
{
	/* Find Bone index from name*/
	int32 BoneIndex = GetMesh()->GetBoneIndex(InBomeName);

//	UE_LOG(LogTemp, Warning, TEXT("Bone name is: %s"), *InBomeName.ToString());

	/* Create new bone reference*/
	FBoneReference NewBoneRef;
	NewBoneRef.BoneName = InBomeName;
	NewBoneRef.BoneIndex = BoneIndex;
	FCompactPoseBoneIndex NewPoseIndex = FCompactPoseBoneIndex(BoneIndex);
	NewBoneRef.CachedCompactPoseIndex = NewPoseIndex;

	
	/* Find bone in temporary array. If founded increase multiplier*/
	for (int32 CurrentElemnt = 0;CurrentElemnt<TemporaryBonesToScaleArray.Num();CurrentElemnt++)
	{

		if (TemporaryBonesToScaleArray[CurrentElemnt].Bone == NewBoneRef)
		{			
			TemporaryBonesToScaleArray[CurrentElemnt].Multiplier += 0.1f;

//			UE_LOG(LogTemp, Warning, TEXT("Multiplier bone was increased"));
//			UE_LOG(LogTemp, Warning, TEXT("Multiplier now is: %s"), *FString::SanitizeFloat(TemporaryBonesToScaleArray[CurrentElemnt].Multiplier));

			UpdateBonesToScaleContainer();
			return;
		}
	}

	/* If not found, add new bone in array*/
	FBoneWithMultiplier NewBoneWithMultiplier;
	NewBoneWithMultiplier.Bone = NewBoneRef;

	TemporaryBonesToScaleArray.Add(NewBoneWithMultiplier);

//	UE_LOG(LogTemp, Warning, TEXT("New bone was add"));
//	UE_LOG(LogTemp, Warning, TEXT("Multiplier now is: %s"), *FString::SanitizeFloat(NewBoneWithMultiplier.Multiplier));

	UpdateBonesToScaleContainer();	
}

void ATZEnemy::UpdateBonesToScaleContainer_Implementation()
{
	BonesToScaleContainer.BonesToScaleArray = TemporaryBonesToScaleArray;

//	UE_LOG(LogTemp, Warning, TEXT("Bone container was updated"));
}

