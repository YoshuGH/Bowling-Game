// Fill out your copyright notice in the Description page of Project Settings.


#include "RoundData.h"

FRoundData::FRoundData()
{
	IsValid = false;
}

FRoundData::FRoundData(bool IsValided)
{
	IsValid = IsValided;
	Shoots.Add(-1);
}
