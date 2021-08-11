// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestCaseGameMode.h"
#include "TestCaseCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestCaseGameMode::ATestCaseGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
