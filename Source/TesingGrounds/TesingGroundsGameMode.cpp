// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "TesingGrounds.h"
#include "TesingGroundsGameMode.h"
#include "TesingGroundsHUD.h"
#include "TesingGroundsCharacter.h"

ATesingGroundsGameMode::ATesingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATesingGroundsHUD::StaticClass();
}
