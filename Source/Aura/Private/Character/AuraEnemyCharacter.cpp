// The Aura Game. All Rights Reserved!

#include "AuraEnemyCharacter.h"
#include "DrawDebugHelpers.h"

AAuraEnemyCharacter::AAuraEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AAuraEnemyCharacter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->CustomDepthStencilValue = CustomDepthStencilValue;
}

void AAuraEnemyCharacter::UnhighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	GetMesh()->CustomDepthStencilValue = 0.0f;
}
