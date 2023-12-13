// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	PhysicsHandleComp = GetOwner()->GetComponentByClass<UPhysicsHandleComponent>();
	if (!PhysicsHandleComp)
	{
		//
	}
}

void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PhysicsHandleComp->GetGrabbedComponent())
	{
		FVector TargetLocation = GetComponentLocation() + GetForwardVector() * HoldDistance;
		PhysicsHandleComp->SetTargetLocationAndRotation(TargetLocation, GetComponentRotation());
	}

}

void UGrabber::Grab()
{
	FHitResult Hit;
	bool IsHit = GetGrabbableInReach(Hit);

	if (IsHit)
	{
		auto HitComponent = Hit.GetComponent();
		HitComponent->WakeAllRigidBodies();

		Hit.GetActor()->Tags.Add("Grabbed");

		PhysicsHandleComp->GrabComponentAtLocationWithRotation(
			HitComponent, NAME_None, Hit.ImpactPoint, GetComponentRotation());
	}

}

bool UGrabber::GetGrabbableInReach(FHitResult& OutHit)
{
	FVector StartVec = GetComponentLocation();
	FVector EndVec = StartVec + GetForwardVector() * GrabDistance;

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);

	return GetWorld()->SweepSingleByChannel(
		OutHit, StartVec, EndVec, FQuat::Identity, GrabChannel, Sphere);
}

void UGrabber::Release()
{
	if (PhysicsHandleComp->GetGrabbedComponent())
	{
		AActor* GrabbedActor = PhysicsHandleComp->GetGrabbedComponent()->GetOwner();
		GrabbedActor->Tags.Remove("Grabbed");

		PhysicsHandleComp->GetGrabbedComponent()->WakeAllRigidBodies();
		PhysicsHandleComp->ReleaseComponent();
	}
}