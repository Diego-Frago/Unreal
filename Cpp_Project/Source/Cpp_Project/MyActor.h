

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "MyActor.generated.h"



UCLASS()
class CPP_PROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "MisVariables")
	UStaticMeshComponent * StaticMeshComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MisVariables")
	float Speed;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "MisVariables")
	FVector Scale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MisVariables")
	FVector ScaleFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MisVariables")

	FVector Position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MisVariables")

	FRotator Rotate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Addition Variables")

	int num1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Addition Variables")

	int num2;

public:
	// Para definir funciones 
	int Addition(int a, int b);
};
