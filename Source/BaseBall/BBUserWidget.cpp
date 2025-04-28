// Fill out your copyright notice in the Description page of Project Settings.


#include "BBUserWidget.h"

void UBBUserWidget::NativeConstruct() 
{
	Super::NativeConstruct();

	if (InputBox)
	{
		InputBox->OnTextCommitted.AddDynamic(this, &UBBUserWidget::OnMessageCommitted);
	}

}



void UBBUserWidget::OnMessageCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
    if (CommitMethod == ETextCommit::OnEnter)
    {
        FString ChatMessage = Text.ToString();

        if (!ChatMessage.IsEmpty())
        {
            // 여기서 ChatMessage를 서버로 보내거나, 채팅창에 추가
            UE_LOG(LogTemp, Log, TEXT("Send Chat: %s"), *ChatMessage);

            // 채팅 보내고 나면 입력창 초기화
            InputBox->SetText(FText::GetEmpty());
        }
    }
}
