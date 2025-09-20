// Copyright Melon Studios.

#include "MarkerWidget.h"
#include "GGRadarDeveloperSettings.h"
#include "Components/TextBlock.h"

void UMarkerWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	const UGGRadarDeveloperSettings* RadarSettings = GetDefault<UGGRadarDeveloperSettings>();

	const FSlateFontInfo FontInfo = RadarSettings->CommonFontInfo;
	DistanceText->SetFont(FontInfo);
}

void UMarkerWidget::UpdateMarkerDistance(int Distance)
{
	FText DistanceValue = FText();
	if (Distance > 999)
	{
		DistanceValue = FText::FromString("999+");
	}
	else
	{
		Distance = FMath::Clamp(Distance, 0, 999);
		DistanceValue = FText::FromString("%sm" + Distance);
	}

	DistanceText->SetText(DistanceValue);
}
