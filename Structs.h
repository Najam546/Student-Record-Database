#pragma once
struct AccountRecord
{
	int recNum; //Record number
	int acctID; //Student identifier
	char firstName[10]; //First name
	char lastName[10]; //Last name
	char program[10]; //degree program of a student
	double cgpa; //Student’s CGPA
};
struct IndexEntry
{
	int acctID; //(Key) Account identifier
	long recNum; //Record number

	//Return key field
	int getKey() const
	{
		return acctID;
	}
};
