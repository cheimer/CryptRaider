// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"
#include "Mover.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (AActor* AcceptActor = GetAcceptableActor())
	{
		AcceptActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
		Mover->SetMove(true);

		auto AcceptActorPhysics = Cast<UPrimitiveComponent>(AcceptActor->GetRootComponent());
		if (AcceptActorPhysics)
		{
			AcceptActorPhysics->SetSimulatePhysics(false);
		}

	}
	else
	{
		Mover->SetMove(false);

	}
}

AActor* UTriggerComponent::GetAcceptableActor() const
{
	TArray<AActor*> OverlapActors;
	GetOverlappingActors(OverlapActors);

	for (AActor* OverlapAct : OverlapActors)
	{
		if (OverlapAct->ActorHasTag(TriggedActorTag) && !OverlapAct->ActorHasTag("Grabbed"))
		{
			return OverlapAct;
		}
	}

	return nullptr;
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
	if (!NewMover) return;

	Mover = NewMover;

}
