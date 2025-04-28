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
            // ���⼭ ChatMessage�� ������ �����ų�, ä��â�� �߰�
            UE_LOG(LogTemp, Log, TEXT("Send Chat: %s"), *ChatMessage);

            // ä�� ������ ���� �Է�â �ʱ�ȭ
            InputBox->SetText(FText::GetEmpty());
        }
    }
}
