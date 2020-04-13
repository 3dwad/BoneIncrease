// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "BoneContainer.h"
#include "BonePose.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "TZEnemy.h"
#include "AnimNode_ResetMy.generated.h"


USTRUCT(BlueprintInternalUseOnly)
struct DREAMSIDETZ_API FAnimNode_ResetMy : public FAnimNode_SkeletalControlBase
{
	GENERATED_USTRUCT_BODY();

	FAnimNode_ResetMy();

	// FAnimNode_SkeletalControlBase interface
		virtual void EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms) override;
		virtual bool IsValidToEvaluate(const USkeleton* Skeleton, const FBoneContainer& RequiredBones) override;
	// End of FAnimNode_SkeletalControlBase interface

private:
	// FAnimNode_SkeletalControlBase interface
		virtual void InitializeBoneReferences(const FBoneContainer& RequiredBones) override;
	// End of FAnimNode_SkeletalControlBase interface

		void BoneIncrease(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms, FBoneReference InBone, float InMultiplier);

		UPROPERTY(EditAnywhere, Category = SkeletalControl, meta = (AlwaysAsPin))
		FArrayContainer BonesForScale;

};
