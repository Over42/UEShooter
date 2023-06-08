// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class UESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Shoot();

private:
	//======================================================================
	// Visuals

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category="Appearance")
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere, Category="Appearance")
	USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere, Category="Appearance")
	UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere, Category="Appearance")
	USoundBase* ImpactSound;


	//======================================================================
	// Parameters

	// Max range in cm
	UPROPERTY(EditAnywhere, Category="Stats")
	float MaxRange = 3000.f;

	UPROPERTY(EditAnywhere, Category="Stats")
	float Damage = 10.f;


	//======================================================================
	// Functions

	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);

	AController* GetOwnerController() const;
};
