// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"

// Sets default values
AMoveLeftRight::AMoveLeftRight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Scene : �����ؼ� ���� ����
	// = : ���� ������(�����ʿ� �ִ� ���� ���ʿ� �ִ´�.)
	// CreateDefaultSubobject : ���� ����
	// USceneComponent : ������ Ŭ���� ����
	// TEXT("Scene") : �������Ʈ���� ������ �̸�

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

}

// Called when the game starts or when spawned
void AMoveLeftRight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveLeftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

