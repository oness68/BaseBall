// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "BBGameState.generated.h"

/**
 * 
 */
UCLASS()
class BASEBALL_API ABBGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	ABBGameState();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;




};
