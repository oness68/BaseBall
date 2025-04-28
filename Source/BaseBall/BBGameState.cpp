// Fill out your copyright notice in the Description page of Project Settings.


#include "BBGameState.h"
#include "Net/UnrealNetwork.h"

ABBGameState::ABBGameState()
{
}

void ABBGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}


