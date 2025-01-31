// The Aura Game. All Rights Reserved!

#include "AuraPlayerController.h"
#include "EnemyInterface.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaSeconds)
{
	Super::PlayerTick(DeltaSeconds);

	TraceCursor();
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(InputMappingContext);
	check(MoveInputAction);

	AddMappingContext();
	SetInputModeGameAndUI();
	SetMouseCursor();
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	const auto EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D InputAxisValue = Value.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	const auto ControlledPawn = GetPawn<APawn>();
	if(!ControlledPawn) return;

	ControlledPawn->AddMovementInput(ForwardDirection, InputAxisValue.Y);
	ControlledPawn->AddMovementInput(RightDirection, InputAxisValue.X);
}

void AAuraPlayerController::AddMappingContext() const
{
	auto Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);

	Subsystem->AddMappingContext(InputMappingContext, 0);
}

void AAuraPlayerController::SetMouseCursor()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void AAuraPlayerController::SetInputModeGameAndUI()
{
	FInputModeGameAndUI InputModeGameAndUI;
	InputModeGameAndUI.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeGameAndUI.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeGameAndUI);
}

void AAuraPlayerController::TraceCursor()
{
	 FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

	if(!HitResult.bBlockingHit) return;

	const auto HitActor = Cast<IEnemyInterface>(HitResult.GetActor());

	LastHighlightedEnemy = NewHighlightedEnemy;
	NewHighlightedEnemy = HitActor;
	
	if(!LastHighlightedEnemy)
	{
		if(NewHighlightedEnemy)
		{
			NewHighlightedEnemy->HighlightActor();
		}
	}
	else
	{
		if(NewHighlightedEnemy)
		{
			if(NewHighlightedEnemy != LastHighlightedEnemy)
			{
				LastHighlightedEnemy->UnhighlightActor();
				NewHighlightedEnemy->HighlightActor();
			}
		}
		else
		{
			LastHighlightedEnemy->UnhighlightActor();
		}
	}
}
