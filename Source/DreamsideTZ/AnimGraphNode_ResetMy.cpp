// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "AnimGraphNode_ResetMy.h"
#include "Components/SkeletalMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

/////////////////////////////////////////////////////
// UAnimGraphNode_ResetMy

#define LOCTEXT_NAMESPACE "A3Nodes"

UAnimGraphNode_ResetMy::UAnimGraphNode_ResetMy(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FText UAnimGraphNode_ResetMy::GetControllerDescription() const
{
	return LOCTEXT("ResetMy", "My custom node");
 }

FText UAnimGraphNode_ResetMy::GetTooltipText() const
{
	return LOCTEXT("UAnimGraphNode_ResetMy_Tooltip", "This is my fucking custom node!");
}

FText UAnimGraphNode_ResetMy::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return GetControllerDescription();
}

void UAnimGraphNode_ResetMy::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
}


  #undef LOCTEXT_NAMESPACE

