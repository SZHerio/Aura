// The Aura Game. All Rights Reserved!

#include "AuraGameModeBase.h"
#include "AuraPlayerController.h" 
#include "AuraPlayerCharacter.h"

AAuraGameModeBase::AAuraGameModeBase()
{
	PlayerControllerClass = AAuraPlayerController::StaticClass();
	DefaultPawnClass = AAuraPlayerCharacter::StaticClass();
}
