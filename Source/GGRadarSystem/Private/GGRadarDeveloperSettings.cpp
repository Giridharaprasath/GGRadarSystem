// Copyright Melon Studios.

#include "GGRadarDeveloperSettings.h"
#include "EMarkerTypes.h"
#include "EWorldDirection.h"
#include "FWorldDirectionsInfo.h"
#include "FMarkerInfo.h"

UGGRadarDeveloperSettings::UGGRadarDeveloperSettings()
{
	const UObject* Font = LoadObject<UObject>(nullptr,TEXT("/Engine/EngineFonts/RobotoTiny.RobotoTiny"));
	CommonFontInfo = FSlateFontInfo(Font, 15.f);

	RadarWidget = TSoftClassPtr<URadarWidget>(FSoftObjectPath(TEXT("/GGRadarSystem/WBP_RadarWidget.WBP_RadarWidget_C")));

	WorldDirectionWidget = TSoftClassPtr<UWorldDirectionWidget>(FSoftObjectPath(TEXT("/GGRadarSystem/WBP_RadarDirection.WBP_RadarDirection_C")));
	bUse8Directions = false;
	CreateWidgetDirections();
	DirectionHorizontalAlignment = HAlign_Center;
	DirectionVerticalAlignment = VAlign_Bottom;
	MaxWidgetTranslation = 320.f;

	MarkerWidget = TSoftClassPtr<UMarkerWidget>(FSoftObjectPath(TEXT("/GGRadarSystem/WBP_RadarDirection.WBP_RadarMarker_C")));
	MarkerHorizontalAlignment = HAlign_Center;
	MarkerVerticalAlignment = VAlign_Center;
}

FName UGGRadarDeveloperSettings::GetCategoryName() const
{
	return TEXT("Plugins");
}

FText UGGRadarDeveloperSettings::GetSectionText() const
{
	return FText::FromString("GG Radar System");
}

FString UGGRadarDeveloperSettings::GetDirectionString(const EWorldDirection WorldDirection)
{
	switch (WorldDirection)
	{
	case EWorldDirection::N:
		return "N";
	case EWorldDirection::NE:
		return "NE";
	case EWorldDirection::E:
		return "E";
	case EWorldDirection::SE:
		return "SE";
	case EWorldDirection::S:
		return "S";
	case EWorldDirection::SW:
		return "SW";
	case EWorldDirection::W:
		return "W";
	case EWorldDirection::NW:
		return "NW";
	default:
		return "A";
	}
}

void UGGRadarDeveloperSettings::CreateWidgetDirections()
{
	WorldDirectionsInfos.Empty();
	WorldDirectionsInfos.Emplace(EWorldDirection::N, 0, true);
	WorldDirectionsInfos.Emplace(EWorldDirection::NE, 45, false);
	WorldDirectionsInfos.Emplace(EWorldDirection::E, 90, true);
	WorldDirectionsInfos.Emplace(EWorldDirection::SE, 135, false);
	WorldDirectionsInfos.Emplace(EWorldDirection::S, 180, true);
	WorldDirectionsInfos.Emplace(EWorldDirection::SW, 225, false);
	WorldDirectionsInfos.Emplace(EWorldDirection::W, 270, true);
	WorldDirectionsInfos.Emplace(EWorldDirection::NW, 315, false);
}

void UGGRadarDeveloperSettings::CreateMarkerInfos()
{
	MarkersInfo.Empty();
	MarkersInfo.Emplace(EMarkerTypes::MainQuest, FVector::ZeroVector);
	MarkersInfo.Emplace(EMarkerTypes::SideQuest, FVector::ZeroVector);
}
