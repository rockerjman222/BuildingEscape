

#include "BuildingEscape.h"
#include "ModelRotator.h"


UModelRotator::UModelRotator()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UModelRotator::BeginPlay()
{
	Super::BeginPlay();
}

void UModelRotator::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	GetOwner()->AddActorLocalRotation(FRotator(PitchSpeed * DeltaTime, YawSpeed * DeltaTime, RollSpeed * DeltaTime), false);
}

