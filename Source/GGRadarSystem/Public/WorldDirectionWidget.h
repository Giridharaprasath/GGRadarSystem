// Copyright Melon Studios.

#pragma once

#include "CoreMinimal.h"
#include "FWorldDirectionsInfo.h"
#include "Blueprint/UserWidget.h"

#include "WorldDirectionWidget.generated.h"

class UTextBlock;

/*
 *	World Direction Radar System Widget Class.
 */
UCLASS()
class GGRADARSYSTEM_API UWorldDirectionWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;
	
	FWorldDirectionsInfo WorldDirectionsInfo;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category = "Radar|UI", meta = ( BindWidget ))
	TObjectPtr<UTextBlock> DirectionText;
};
