// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "AIController.h"

#include "UEShooter/Characters/ShooterCharacter.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (ShooterCharacter)
	{
		ShooterCharacter->Shoot();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Cant cast to owning pawn"));
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::Succeeded;
}
