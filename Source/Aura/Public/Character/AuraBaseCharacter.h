// The Aura Game. All Rights Reserved!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraBaseCharacter.generated.h"

UCLASS(Abstract)
class AURA_API AAuraBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraBaseCharacter();

protected:
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> WeaponSkeletalMesh;
	
protected:
	virtual void BeginPlay() override;
};
