// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TESTPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void move();
	int32_t step();
	int32 createEvent();
	float distance(FVector2D first, FVector2D second);

protected:
	FVector2D start;
	int32 evCnt;
	int32 totDist;
	TArray<FVector2D> moveArr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystem* particleSys;

private:
	float timer;
};
