// Fill out your copyright notice in the Description page of Project Settings.


#include "DatabaseManager.h"
#include "ItemDatabase.h"

UDatabaseManager::UDatabaseManager()
{
	ItemDatabase = Cast<UItemDatabase>(UItemDatabase::StaticClass()->GetDefaultObject());
}


