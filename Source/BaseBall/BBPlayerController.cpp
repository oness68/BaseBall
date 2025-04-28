// Fill out your copyright notice in the Description page of Project Settings.


#include "BBPlayerController.h"
#include "BBPlayerState.h"
ABBPlayerController::ABBPlayerController()
{

}

void ABBPlayerController::MakeMessagetoSend(const FString& Message)
{
	ABBPlayerState* BBPlayerState = GetPlayerState<ABBPlayerState>();

	check(BBPlayerState);

	FString SendMessage = BBPlayerState->GetPlayerUniaueID() + TEXT(" : ") + Message;



}





void ABBPlayerController::BeginPlay()
{
	Super::BeginPlay();
	AddWidget();
	ShowMouseAndFocusUI();

}

void ABBPlayerController::ServerSendMessage_Implementation(const FString& FullMessage)
{
	/*if (ABBGameMode* GM = GetWorld()->GetAuthGameMode<ABBGameMode>())
	{
		GM->BroadcastChatMessage(FullMessage);
	}*/
}

void ABBPlayerController::AddWidget()
{
	if (IsLocalController())
	{
		if (MainWidgetClass)
		{
			MainWidget = CreateWidget<UBBUserWidget>(this, MainWidgetClass);
			if (MainWidget)
			{
				MainWidget->AddToViewport();
				UE_LOG(LogTemp, Log, TEXT("Succeed UI AddToViePort"));
			}
		}
	}
}

void ABBPlayerController::ShowMouseAndFocusUI()
{

	bShowMouseCursor = true;

	// UI 입력 모드 설정
	FInputModeUIOnly InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	if (MainWidget)
	{
		InputModeData.SetWidgetToFocus(MainWidget->TakeWidget());
	}

	SetInputMode(InputModeData);

}

