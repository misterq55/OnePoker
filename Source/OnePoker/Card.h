// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.generated.h"

struct CardInfo {
	char Number;
	char Mark;

	CardInfo()
		: Number(0), Mark(0)
	{}

	CardInfo(char number, char mark)
		: Number(number), Mark(mark)
	{}
};

UCLASS()
class ONEPOKER_API ACard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnyWhere)
	UStaticMeshComponent* CardBody;

	CardInfo Info;
	FString BasePath;

public:
	void SetCardInfo(char number, char mark);
	CardInfo getCardInfo() { return Info; }
};
