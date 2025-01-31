// The Aura Game. All Rights Reserved!

#pragma once

#include "CoreMinimal.h"
#include "EnemyInterface.h"
#include "Character/AuraBaseCharacter.h"
#include "AuraEnemyCharacter.generated.h"

UCLASS()
class AURA_API AAuraEnemyCharacter : public AAuraBaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemyCharacter();
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool ShouldHighlight = false;
	
protected:
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;

private:
	float CustomDepthStencilValue = 255.0f;
	
};
