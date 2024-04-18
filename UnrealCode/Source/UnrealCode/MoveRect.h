// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveRect.generated.h"

UENUM(BlueprintType)
enum class EN_MoveType : uint8
{
	MoveRight UMETA(display = "Right"),
	MoveUp UMETA(display = "Up"),
	MoveLeft UMETA(display = "Left"),
	MoveDown UMETA(display = "Down"),
};

UCLASS()
class UNREALCODE_API AMoveRect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveRect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	USceneComponent* Scene;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UStaticMeshComponent* StaticMesh;

	float LocX, LocZ;

	EN_MoveType MoveType;

};
