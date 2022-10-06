// Fill out your copyright notice in the Description page of Project Settings.


#include "ConditionDatabase.h"
#include "Condition.h"

UConditionDatabase::UConditionDatabase()
{
	//	Create conditions here


}

UConditionDatabase::~UConditionDatabase()
{

}

UCondition* UConditionDatabase::GetCondition(FString pName)
{
	/*
	passing in the name to search the database for the condition with the same name

	*/
	for (int i = 0; i < database.Max(); i++)
	{
		if (database[i]->GetConditionName() == pName)
		{
			return database[i];
		}
	}
	return nullptr;
}