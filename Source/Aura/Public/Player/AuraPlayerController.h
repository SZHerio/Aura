// The Aura Game. All Rights Reserved!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

struct FInputActionValue;
class UInputMappingContext;
class UInputAction;
class UInputMappingContext;
class IEnemyInterface;

UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AAuraPlayerController();

public:
	virtual void PlayerTick(float DeltaSeconds) override;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveInputAction = nullptr;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY()
	TObjectPtr<IEnemyInterface> LastHighlightedEnemy = nullptr;

	UPROPERTY()
	TObjectPtr<IEnemyInterface> NewHighlightedEnemy = nullptr;
	
private:
	UFUNCTION()
	void Move(const FInputActionValue& Value);
	
	void AddMappingContext() const;
	void SetMouseCursor();
	void SetInputModeGameAndUI();
	void TraceCursor();
};
