// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"
#include "Card.h"

// Sets default values
ADeck::ADeck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	addCard('C', 'K');
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

void ADeck::Init()
{

}

void ADeck::addCard(char number, char mark)
{
	UWorld* world = GetWorld();

	if (world) {
		ACard* temp = (ACard*)world->SpawnActor(ACard::StaticClass());
		CardList.push_back(temp);
		// int itemp = 0;
		// temp->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, true));
	}
}