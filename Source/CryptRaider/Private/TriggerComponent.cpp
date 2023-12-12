// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TArray<AActor*> OverlapActors;
	GetOverlappingActors(OverlapActors);

	for (AActor* OverlapAct : OverlapActors)
	{
		if (OverlapAct->ActorHasTag(TriggedActorTag))
		{

		}
	}

}
