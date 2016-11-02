

#pragma once

#include "Components/ActorComponent.h"
#include "ModelRotator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UModelRotator : public UActorComponent
{
	GENERATED_BODY()

public:	
	UModelRotator();

	virtual void BeginPlay() override;
	
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:

	UPROPERTY(EditAnywhere)
	float PitchSpeed = 0.0f;

	UPROPERTY(EditAnywhere)
	float YawSpeed = 100.0f;

	UPROPERTY(EditAnywhere)
	float RollSpeed = 0.0f;
	
};
