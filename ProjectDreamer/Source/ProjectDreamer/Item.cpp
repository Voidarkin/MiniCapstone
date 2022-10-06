// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/DataComponent.h"

/*
	Base item class
*/
UItem::UItem()
{

}

UItem::UItem(FString n, FString d, int v)
	: Name(n)
	, Description(d)
	, SaleValue(v)
{

}

UItem::~UItem()
{
}
