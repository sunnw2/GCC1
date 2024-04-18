// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveLeftRight.generated.h" //Unral Class ���̺귯�� ����

UCLASS() //Unreal Class �ɼ� �Է�
class UNREALCODE_API /*��� API �̸�*/ AMoveLeftRight : public AActor
{
	GENERATED_BODY() //Unreal �ڵ� ���� ó��
	
public:	
	// Sets default values for this actor's properties
	AMoveLeftRight(); //class�� ������ �� ����

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(BlueprintReadWrite)
	USceneComponent* Scene;

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;
};
