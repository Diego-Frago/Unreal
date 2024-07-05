// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"


// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    Speed = 0.5f;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MiMalla"));
    RootComponent = StaticMeshComponent;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
    //GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor: : Blue, FString : : Printf(TEXT("Speed: %.1f"), Speed));

    UE_LOG(LogTemp, Warning, TEXT("The result of the addition is: %d"), Addition(num1, num2));
    Addition(num1, num2);
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    FVector NewLocation = GetActorLocation();
    NewLocation.X += Speed * DeltaTime;
    SetActorLocation(NewLocation);

    FRotator NewRotation = GetActorRotation();
    NewRotation += Rotate * DeltaTime;
    SetActorRotation(NewRotation);

    /*FVector NewScale = GetActorScale3D();
    NewScale += Scale * DeltaTime;
    SetActorScale3D(NewScale);*/

    FVector NewScale = FMath :: VInterpTo(GetActorScale3D(), ScaleFactor, DeltaTime, Speed);
    SetActorScale3D(NewScale);
}

int AMyActor::Addition(int a, int b)
{
    return a + b;
}

