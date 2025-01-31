// The Aura Game. All Rights Reserved!

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraBaseCharacter.h"
#include "AuraPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class AURA_API AAuraPlayerCharacter : public AAuraBaseCharacter
{
	GENERATED_BODY()
	
public:
	AAuraPlayerCharacter();
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<UCameraComponent> CameraComponent;
};
