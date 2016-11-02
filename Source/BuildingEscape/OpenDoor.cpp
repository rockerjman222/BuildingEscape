#include "BuildingEscape.h"
#include "OpenDoor.h"

FRotator BeginningRotation;

UOpenDoor::UOpenDoor()
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Actor = GetWorld()->GetFirstPlayerController()->GetPawn();
	BeginningRotation = GetOwner()->GetActorRotation();
}

void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (PressurePlate->IsOverlappingActor(Actor))
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay)
	{
		CloseDoor();
	}

}

void UOpenDoor::OpenDoor()
{
	GetOwner()->SetActorRotation(FRotator(0.0f, BeginningRotation.Yaw - OpenAngle, 0.0f));
}

void UOpenDoor::CloseDoor()
{
	GetOwner()->SetActorRotation(BeginningRotation);
}



