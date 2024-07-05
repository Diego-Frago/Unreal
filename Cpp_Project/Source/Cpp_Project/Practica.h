#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "InputActionValue.h"
#include "Practica.generated.h"


UCLASS()
class CPP_PROJECT_API APractica : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APractica();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
    float speed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
    FRotator rotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
    FVector scalation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SUMA")
    float num1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SUMA")
    float num2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SUMA")
    FString Inputstr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SUMA")
    int32 amountpermu;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SUMA")
    FString PPalabra;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SUMA")
    FString SPalabra;

public:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComponent;



    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    class UInputMappingContext* InputMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    class UInputAction* JumpAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    class UInputAction* MoveAction;




    float SumaPequena(float a, float b);

    // Input handling functions
    void Jump(const FInputActionValue& Value);
    void Move(const FInputActionValue& Value);

private:
    void SetupEnhancedInputComponent();

public:
    void Permutacion(FString str, int32 start, int32 end);
    void ShowPermutacion(FString str);
    void Anagramas(FString palabra1, FString palabra2);
};

