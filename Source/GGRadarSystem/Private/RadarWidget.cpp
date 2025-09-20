// Copyright Melon Studios.

#include "RadarWidget.h"
#include "GGRadarDeveloperSettings.h"
#include "WorldDirectionWidget.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"

void URadarWidget::PlayRadarBlendAnim_Implementation(const bool bShowRadar)
{
	const EUMGSequencePlayMode::Type PlayAnimType = bShowRadar ? EUMGSequencePlayMode::Reverse : EUMGSequencePlayMode::Forward;
	PlayAnimation(RadarBlendAnim, 0, 1, PlayAnimType, 1.f, false);
}

void URadarWidget::AddWorldDirectionInfo(const FWorldDirectionsInfo& WorldDirectionsInfo)
{
	if (!WorldDirectionWidgetClass)
	{
		SetWidgetClass();
	}

	checkf(WorldDirectionWidgetClass, TEXT("World Direction Widget Class Not Set In "), __FUNCTION__);
	UWorldDirectionWidget* DirectionWidget = CreateWidget<UWorldDirectionWidget>(GetWorld(), WorldDirectionWidgetClass);

	DirectionWidget->WorldDirectionsInfo = WorldDirectionsInfo;
	WorldDirectionWidgets.Add(DirectionWidget);

	if (UOverlaySlot* WidgetOverlaySlot = RadarOverlay->AddChildToOverlay(DirectionWidget))
	{
		WidgetOverlaySlot->SetHorizontalAlignment(HorizontalAlignment);
		WidgetOverlaySlot->SetVerticalAlignment(VerticalAlignment);
	}
}

void URadarWidget::SetWidgetClass()
{
	const UGGRadarDeveloperSettings* RadarSettings = GetDefault<UGGRadarDeveloperSettings>();
	WorldDirectionWidgetClass = RadarSettings->WorldDirectionWidget.LoadSynchronous();
	HorizontalAlignment = RadarSettings->DirectionHorizontalAlignment;
	VerticalAlignment = RadarSettings->DirectionVerticalAlignment;
}
