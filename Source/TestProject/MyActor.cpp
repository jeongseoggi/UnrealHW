// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	start = FVector2D(0, 0);
	moveArr.Add(start);
	UE_LOG(LogTemp, Warning, TEXT("Start : x = %f, y = %f"), start.X, start.Y);
	timer = 0;


}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	timer += DeltaTime;

	if (timer >= 1.f && totDist <= 10)
	{
		move();
		timer = 0;
	}

}

void AMyActor::move()
{
	totDist++;
	int32_t x = step() * 10;
	int32_t y = step() * 10;
	start = FVector2D((start.X + x),(start.Y + y));

	moveArr.Add(start);

	SetActorLocation(GetActorLocation() + FVector((start.X + x), (start.Y + y), 0));
	

	UE_LOG(LogTemp, Log, TEXT("x = %f, y = %f"), start.X, start.Y);

	if (moveArr.Num() != 0)
	{
		float dist = distance(moveArr[totDist - 1], moveArr[totDist]);
		UE_LOG(LogTemp, Log, TEXT("distance = %f"), dist);
	}

	if (createEvent() != 0)
	{
		UE_LOG(LogTemp, Log, TEXT("Event!!"));

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), particleSys, GetActorLocation(), FRotator::ZeroRotator);
		evCnt++;
	}

	if (totDist > 10)
	{
		UE_LOG(LogTemp, Warning, TEXT("End : x = %f, y = %f"), start.X, start.Y);
		UE_LOG(LogTemp, Warning, TEXT("EventCount : %d"), evCnt);
	}
}

int32_t AMyActor::step()
{
	int32_t t = FMath::RandRange(0, 1);
	return t;
}

int32 AMyActor::createEvent()
{
	int32 t = FMath::RandRange(0, 1);

	return t;
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	float DeltaX = first.X - second.X;
	float DeltaY = first.Y - second.Y;

	float tot = (DeltaX * DeltaX) + (DeltaY * DeltaY);

	return FMath::Sqrt(tot);
}

