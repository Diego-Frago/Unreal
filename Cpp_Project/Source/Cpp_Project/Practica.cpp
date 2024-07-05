#include "Practica.h"

#include "Engine/Engine.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"

// Sets default values
APractica::APractica()
{
    PrimaryActorTick.bCanEverTick = true;

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMeshComponent"));
    RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void APractica::BeginPlay()
{
    Super::BeginPlay();

    SetupEnhancedInputComponent();
    Permutacion(Inputstr, 0, Inputstr.Len() - 1);

    UE_LOG(LogTemp, Warning, TEXT("Hola WEA 2"));
   // GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("La suma de num1 y num2 es: %.1f"), SumaPequena(num1, num2)));
}

// Called every frame
void APractica::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector newLocation = GetActorLocation();
    newLocation.X += speed * DeltaTime;
    SetActorLocation(newLocation);

    FRotator NewRotation = GetActorRotation();
    NewRotation += rotation * DeltaTime;
    SetActorRotation(NewRotation);

    FVector NewScale = FMath::VInterpTo(GetActorScale3D(), scalation, DeltaTime, 1.0f);
    SetActorScale3D(NewScale);
}

float APractica::SumaPequena(float a, float b)
{
    return a + b;
}

void APractica::SetupEnhancedInputComponent()
{
    if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(InputMappingContext, 0);
        }

        if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
        {
            EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &APractica::Jump);
            EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APractica::Move);
        }
    }
}

void APractica::Permutacion(FString palabra, int32 start, int32 end)
{
    if (start == end) 
    {
        ShowPermutacion(palabra);
    }
    else
    {
        for (int32 i = start; i <= end; i++) 
        {
            TCHAR Temp = palabra[start];
            palabra[start] = palabra[i];
            palabra[i] = Temp;

            Permutacion(palabra, start + 1, end);

            Temp = palabra[start];
            palabra[start] = palabra[i];
            palabra[i] = Temp;

        }
    }
}

void APractica::ShowPermutacion(FString str)
{
    amountpermu++;
    GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, str);
}

void APractica::Anagramas(FString palabra1, FString palabra2)
{
    if (palabra1.Len() != palabra2.Len()) 
    {

    }
    else 
    {
        TArray array1 = palabra1.GetCharArray();
        TArray array2 = palabra2.GetCharArray();
        array1.Sort();
        array2.Sort();

        if (array1 == array2) 
        {
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Las palabras son anagramas")));
        }
        else
        {
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, FString::Printf(TEXT("Las palabras no son anagramas")));
        }
    }    
}


    /*FString APractica::Permutacion()
    {
        for (int8 i = 0; i < palabra.Len(); i++)
        {

            if (palabra[i] != palabra[palabra.Len() - i - 1])
            {
                return FString::Printf(TEXT("No es palindroma"));
            }
        }
        return FString::Printf(TEXT("Es palindroma"));
    }*/

void APractica::Jump(const FInputActionValue& Value)
{
    UE_LOG(LogTemp, Warning, TEXT("Jump action triggered"));
}

void APractica::Move(const FInputActionValue& Value)
{
    const float MovementValue = Value.Get<float>();
    if (MovementValue != 0.0f)
    {
        UE_LOG(LogTemp, Warning, TEXT("Move forward with value: %f"), MovementValue);
        FVector newLocation = GetActorLocation();
        newLocation.X += MovementValue * speed * GetWorld()->GetDeltaSeconds();
        SetActorLocation(newLocation);
    }
}






