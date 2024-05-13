// Copyright Epic Games, Inc. All Rights Reserved.

#include "LMSGameMode.h"
#include "LMSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALMSGameMode::ALMSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/LMS_Game / Characters / Character_Logic / BP_LMS_BaseCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
 