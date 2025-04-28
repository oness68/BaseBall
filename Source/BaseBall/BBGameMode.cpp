// Fill out your copyright notice in the Description page of Project Settings.


#include "BBGameMode.h"
#include "BBPlayerState.h"
#include "BBGameState.h"
#include "BBPlayerController.h"

ABBGameMode::ABBGameMode()
{


}



void ABBGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	ABBPlayerController* BBController = Cast<ABBPlayerController>(NewPlayer);
	if (BBController)
	{
		ConnectedControllers.Add(BBController);
		UE_LOG(LogTemp, Log, TEXT("BBPlayerController added: %s"), *BBController->GetName());
	}

	GrantUserID(BBController);
}

void ABBGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ABBGameMode::BroadcastChatMessage(const FString& Message)
{
	MulticastChatMessage(Message);
}

void ABBGameMode::MulticastChatMessage_Implementation(const FString& Message)
{

	/*for (ABBPlayerController* Controller : ConnectedControllers)
	{
		
	}*/
}

void ABBGameMode::GrantUserID(ABBPlayerController* NewPlayer)
{
	
	check(NewPlayer);

	ABBPlayerState* BBPlayerState = Cast<ABBPlayerState>(NewPlayer->PlayerState);

	check(BBPlayerState);

	int32 PlayerCount = GetNumPlayers();
	FString ID = TEXT("Unknown");

	if (PlayerCount == 1)
	{
		ID = TEXT("Host");
	}
	else
	{
		ID = TEXT("Guest");
	}

	BBPlayerState->SetPlayerUniaueID(ID);
	 
}


