// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDWidget.h"

void UHUDWidget::sethealthpercent(float newpercent)
{
	if (newpercent >=0.0f && newpercent <=1.0f&&healthbar) {
		healthbar->SetPercent(newpercent);
	}
}
