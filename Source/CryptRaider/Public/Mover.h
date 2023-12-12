// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMover();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Mover")
	bool IsMove = false;

	UPROPERTY(EditAnywhere, Category = "Mover")
	float MoveTime = 4.0f;

	UPROPERTY(EditAnywhere, Category = "Mover")
	FVector MoveOffset = FVector::Zero();

private:
	FVector OriginLocation;

	float MoveSpeed;
};
