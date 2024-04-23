// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterWidget.h"
#include "MyStatComponent.h"
#include "Components/ProgressBar.h"

void UMyCharacterWidget::BindHp(class UMyStatComponent* StatComp)
{
	CurrentStatComp = StatComp;
	StatComp->OnHpChanged.AddUObject(this, &UMyCharacterWidget::UpdateHP);

}

void UMyCharacterWidget::UpdateHP()
{
	if(CurrentStatComp.IsValid())
	PB_HpBar->SetPercent(CurrentStatComp->GetHpRatio());
}
