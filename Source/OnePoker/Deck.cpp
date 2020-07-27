// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"
#include <random>

// Sets default values
ADeck::ADeck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	memset(Cards, 0, sizeof(Cards));

	InitDeck();

	// GetWorld()->get
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
	CardList.push_back(CardInfo(number, mark));
}

void ADeck::InitDeck()
{
	char numberBuffer[13] = { 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' };
	char markBuffer[4] = { 'C', 'D', 'H', 'S' };

	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				addCard(numberBuffer[j], markBuffer[i]);
			}
		}
	}

	shuffle();

	UWorld *world = GetWorld();

	if (!UObject::IsTemplate(RF_Transient) && world) {
		ACard* card0 = (ACard*)world->SpawnActor(ACard::StaticClass());
		card0->Rename(TEXT("TestCard0"));
		card0->SetCardInfo(CardList.front());
		CardList.pop_front();
		Cards[0] = card0;

		ACard* card1 = (ACard*)world->SpawnActor(ACard::StaticClass());
		card1->Rename(TEXT("TestCard1"));
		card1->SetCardInfo(CardList.front());
		CardList.pop_front();
		Cards[1] = card1;
	}
}

void ADeck::shuffle() {
	std::vector<CardInfo> vec(CardList.begin(), CardList.end());
	std::shuffle(vec.begin(), vec.end(), std::mt19937_64{ std::random_device{}() });

	std::list<CardInfo> shuffled_card_list{ vec.begin(), vec.end() };
	CardList.swap(shuffled_card_list);
}