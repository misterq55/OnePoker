// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <list>
#include "Card.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Deck.generated.h"

using std::list;

//class ACard;

UCLASS()
class ONEPOKER_API ADeck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeck();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ACard* Cards[2];
	list<CardInfo> CardList;
	void Init();

public:
	void addCard(char number, char mark);
	void InitDeck();
	void shuffle();
};
