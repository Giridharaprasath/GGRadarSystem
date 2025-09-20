// Copyright Melon Studios.

#pragma once

#include "CoreMinimal.h"

/*
 *	World Direction Enum Class.
 */
UENUM(BlueprintType, Category = "Radar")
enum class EWorldDirection : uint8
{
	None UMETA(DisplayName = "None"),
	N UMETA(DisplayName = "North"),
	NE UMETA(DisplayName = "North East"),
	E UMETA(DisplayName = "Earth"),
	SE UMETA(DisplayName = "South East"),
	S UMETA(DisplayName = "South"),
	SW UMETA(DisplayName = "South West"),
	W UMETA(DisplayName = "West"),
	NW UMETA(DisplayName = "North West"),
};
