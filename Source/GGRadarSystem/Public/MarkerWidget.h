// Copyright Melon Studios.

#pragma once

#include "CoreMinimal.h"
#include "FMarkerInfo.h"
#include "Blueprint/UserWidget.h"

#include "MarkerWidget.generated.h"

class UImage;
class UTextBlock;

/**
 * Marker Radar System Widget Class.
 */
UCLASS()
class GGRADARSYSTEM_API UMarkerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;
	UFUNCTION()
	void UpdateMarkerDistance(int Distance);

	FMarkerInfo MarkerInfo;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category = "Radar|UI", meta = ( BindWidget ))
	TObjectPtr<UTextBlock> DistanceText;
	UPROPERTY(BlueprintReadOnly, Transient, Category = "Radar|UI", meta = ( BindWidget ))
	TObjectPtr<UImage> MarkerIcon;
};
