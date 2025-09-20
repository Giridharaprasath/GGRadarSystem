// Copyright Melon Studios.

#pragma once

#include "CoreMinimal.h"
#include "EWorldDirection.h"

#include "FWorldDirectionsInfo.generated.h"

/*
 *	Radar System World Directions Info Structure Class.
 */
USTRUCT(BlueprintType, Category = "Radar")
struct FWorldDirectionsInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	EWorldDirection Direction = EWorldDirection::None;
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	int WorldRotation = 0;
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	bool bIsMainDirection = true;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bUseImage = false;

	FWorldDirectionsInfo()
	{
	}

	FWorldDirectionsInfo(const EWorldDirection Direction, const int WorldRotation, const bool bIsMainDirection)
	{
		this->Direction = Direction;
		this->WorldRotation = WorldRotation;
		this->bIsMainDirection = bIsMainDirection;
	}
};
