// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"

// Sets default values
AMoveLeftRight::AMoveLeftRight():isMoveRight(true), LocX(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Scene : 생성해서 넣을 변수
	// = : 대입 연산자(오른쪽에 있는 것을 왼쪽에 넣는다.)
	// CreateDefaultSubobject : 생성 도구
	// USceneComponent : 생성할 클래스 지정
	// TEXT("Scene") : 블루프린트에서 보여질 이름

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	SetRootComponent(Scene); //Scene을 RootComponent로 만들기(SetRootComponent 메서드)

	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform); //StaticMesg를 상대 좌표계 기준으로 Scen(RootComponent)에 붙임
	StaticMesh->SetRelativeTransform(FTransform::Identity);//StaticMesh의 Transform을 초기값으로 설정

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



	if (isMoveRight) 
	{
		//True
		LocX += 1;

		StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));

		if (StaticMesh->GetRelativeLocation().X > 200) {
			isMoveRight = false;
			
		}
	}
	else 
	{
		//False
		LocX -= 1;

		StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));

		if (StaticMesh->GetRelativeLocation().X < 0) {
			isMoveRight = true;
		}
	}
}

