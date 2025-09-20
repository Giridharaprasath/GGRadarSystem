// Copyright Melon Studios.

#include "WorldDirectionWidget.h"
#include "FWorldDirectionsInfo.h"
#include "GGRadarDeveloperSettings.h"
#include "Components/TextBlock.h"

void UWorldDirectionWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	const UGGRadarDeveloperSettings* RadarSettings = GetDefault<UGGRadarDeveloperSettings>();

	const FText WorldDirection = FText::FromString(RadarSettings->GetDirectionString(WorldDirectionsInfo.Direction));
	DirectionText->SetText(WorldDirection);

	const FSlateFontInfo FontInfo = RadarSettings->CommonFontInfo;
	DirectionText->SetFont(FontInfo);
}
