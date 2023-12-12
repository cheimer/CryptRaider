// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Grabber.generated.h"

class UPhysicsHandleComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	UGrabber();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void Grab();

	UFUNCTION(BlueprintCallable)
	void Release();

protected:
	virtual void BeginPlay() override;

	UPhysicsHandleComponent* PhysicsHandleComp;

private:
	bool GetGrabbableInReach(FHitResult& OutHit);

	UPROPERTY(EditAnywhere, Category = "Grab")
	float GrabDistance = 400.0f;

	UPROPERTY(EditAnywhere, Category = "Grab")
	float GrabRadius = 5.0f;

	UPROPERTY(EditAnywhere, Category = "Grab")
	float HoldDistance = 200.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Grab")
	TEnumAsByte<ECollisionChannel> GrabChannel;

};
