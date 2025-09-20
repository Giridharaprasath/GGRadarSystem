// Copyright Melon Studios.

#pragma once

#include "CoreMinimal.h"

/**
 *	Marker Types Enum Class.
 */
UENUM(BlueprintType, Category = "Radar")
enum class EMarkerTypes : uint8
{
	None UMETA(DisplayName = "None"),
	MainQuest UMETA(DisplayName = "Main Quest"),
	SideQuest UMETA(DisplayName = "Side Quest"),
};
