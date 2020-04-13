// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "AnimNode_ResetMy.h"
#include "Animation/AnimInstanceProxy.h"
#include "AnimationRuntime.h"

/////////////////////////////////////////////////////
// FAnimNode_ResetMy

FAnimNode_ResetMy::FAnimNode_ResetMy()
{
}


void FAnimNode_ResetMy::EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms)
{

	/* Extract bones array from container struct. Apply BoneIncrease for each bone in array */
	for (int32 Index = 0; Index < BonesForScale.BonesToScaleArray.Num(); Index++)
	{
		FBoneReference CurrentBone = BonesForScale.BonesToScaleArray[Index].Bone;
		float CurrentMultiplier = BonesForScale.BonesToScaleArray[Index].Multiplier;

		BoneIncrease(Output, OutBoneTransforms, CurrentBone, CurrentMultiplier);
	}
}


bool FAnimNode_ResetMy::IsValidToEvaluate(const USkeleton* Skeleton, const FBoneContainer& RequiredBones)
{
	return true;
}

void FAnimNode_ResetMy::InitializeBoneReferences(const FBoneContainer& RequiredBones)
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(InitializeBoneReferences)

	UE_LOG(LogTemp, Warning, TEXT("Maybe here?"));

}

void FAnimNode_ResetMy::BoneIncrease(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms, FBoneReference InBone, float InMultiplier)
{

	/* Apply new scale for bone */
	if (InBone.BoneName != "None" && InBone.IsValidToEvaluate())
	{
		const FBoneContainer& BoneContainer = Output.Pose.GetPose().GetBoneContainer();
		FCompactPoseBoneIndex CompactPoseBoneToModify = InBone.GetCompactPoseIndex(BoneContainer);
		
		FTransform NewBoneTM = Output.Pose.GetComponentSpaceTransform(CompactPoseBoneToModify);

		NewBoneTM.SetScale3D(NewBoneTM.GetScale3D() + FVector(InMultiplier));

		TArray<FBoneTransform> NewBoneTrasnform;
		NewBoneTrasnform.Add(FBoneTransform(InBone.CachedCompactPoseIndex, NewBoneTM));
		Output.Pose.LocalBlendCSBoneTransforms(NewBoneTrasnform, 1);

	}
}

