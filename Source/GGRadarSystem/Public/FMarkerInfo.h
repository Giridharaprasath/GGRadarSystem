// Copyright Melon Studios.

#pragma once

#include "CoreMinimal.h"
#include "EMarkerTypes.h"

#include "FMarkerInfo.generated.h"

/**
 *	Radar System Marker Info Structure Class.
 */
USTRUCT(BlueprintType, Category = "Radar")
struct FMarkerInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	EMarkerTypes MarkerType = EMarkerTypes::None;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector MarkerLocation = FVector::ZeroVector;
};
