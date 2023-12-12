// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMath.h"

UMover::UMover()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UMover::BeginPlay()
{
	Super::BeginPlay();

	OriginLocation = GetOwner()->GetActorLocation();
	MoveSpeed = FVector::Distance(GetOwner()->GetActorLocation(), OriginLocation + MoveOffset) / MoveTime;

}

void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsMove)
	{

		GetOwner()->SetActorLocation(FMath::VInterpConstantTo(GetOwner()->GetActorLocation(), OriginLocation + MoveOffset, DeltaTime, MoveSpeed));
	}

}

