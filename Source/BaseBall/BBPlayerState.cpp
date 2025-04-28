// Fill out your copyright notice in the Description page of Project Settings.


#include "BBPlayerState.h"
#include "Net/UnrealNetwork.h"

void ABBPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);


    DOREPLIFETIME(ABBPlayerState, PlayerUniqueID);
    DOREPLIFETIME(ABBPlayerState, PlayerCount);
}



