// The Aura Game. All Rights Reserved!

#include "AuraBaseCharacter.h"

AAuraBaseCharacter::AAuraBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	WeaponSkeletalMesh->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	WeaponSkeletalMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}

void AAuraBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}
