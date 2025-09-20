// Copyright Melon Studios.

#include "RadarWidget.h"
#include "GGRadarDeveloperSettings.h"
#include "MarkerWidget.h"
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
		SetWorldDirectWidgetClass();
	}

	checkf(WorldDirectionWidgetClass, TEXT("World Direction Widget Class Not Set In "), __FUNCTION__);
	UWorldDirectionWidget* DirectionWidget = CreateWidget<UWorldDirectionWidget>(GetWorld(), WorldDirectionWidgetClass);

	DirectionWidget->WorldDirectionsInfo = WorldDirectionsInfo;
	WorldDirectionWidgets.Add(DirectionWidget);

	if (UOverlaySlot* WidgetOverlaySlot = RadarOverlay->AddChildToOverlay(DirectionWidget))
	{
		WidgetOverlaySlot->SetHorizontalAlignment(DirectionHorizontalAlignment);
		WidgetOverlaySlot->SetVerticalAlignment(DirectionVerticalAlignment);
	}
}

void URadarWidget::AddMarkerInfo(const EMarkerTypes MarkerType)
{
	if (!MarkerWidgetClass)
	{
		SetMarkerWidgetClass();
	}

	checkf(MarkerWidgetClass, TEXT("Marker Widget Class Not Set In "), __FUNCTION__);
	UMarkerWidget* MarkerWidget = CreateWidget<UMarkerWidget>(GetWorld(), MarkerWidgetClass);

	MarkerWidget->MarkerInfo.MarkerType = MarkerType;
	MarkerWidgets.Add(MarkerWidget);

	if (UOverlaySlot* WidgetOverlaySlot = RadarOverlay->AddChildToOverlay(MarkerWidget))
	{
		WidgetOverlaySlot->SetHorizontalAlignment(MarkerHorizontalAlignment);
		WidgetOverlaySlot->SetVerticalAlignment(MarkerVerticalAlignment);
	}
}

void URadarWidget::SetWorldDirectWidgetClass()
{
	const UGGRadarDeveloperSettings* RadarSettings = GetDefault<UGGRadarDeveloperSettings>();
	WorldDirectionWidgetClass = RadarSettings->WorldDirectionWidget.LoadSynchronous();
	DirectionHorizontalAlignment = RadarSettings->DirectionHorizontalAlignment;
	DirectionVerticalAlignment = RadarSettings->DirectionVerticalAlignment;
}

void URadarWidget::SetMarkerWidgetClass()
{
	const UGGRadarDeveloperSettings* RadarSettings = GetDefault<UGGRadarDeveloperSettings>();
	MarkerWidgetClass = RadarSettings->MarkerWidget.LoadSynchronous();
	MarkerHorizontalAlignment = RadarSettings->MarkerHorizontalAlignment;
	MarkerVerticalAlignment = RadarSettings->MarkerVerticalAlignment;
}
