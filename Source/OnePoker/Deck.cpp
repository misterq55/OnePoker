// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"

// Sets default values
ADeck::ADeck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// D:/Unreal Projects/OnePoker/onepoker/Content/HG_Playing_Cards/Blueprints/BP_Playing_Card.uasset
	// Blueprint'/Game/HG_Playing_Cards/Blueprints/BP_Playing_Card.BP_Playing_Card'

	static ConstructorHelpers::FObjectFinder<UBlueprint> BP_CARD(TEXT("Blueprint'/Game/HG_Playing_Cards/Blueprints/BP_Playing_Card.BP_Playing_Card'"));

	TSubclassOf<AActor> cardClass = (UClass*)BP_CARD.Object->GeneratedClass;
	Card = cardClass->GetDefaultObject();
}

// Called when the game starts or when spawned
void ADeck::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

