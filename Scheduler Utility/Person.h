#pragma once
#ifndef PERSON_INCLUDED
#define PERSON_INCLUDED
#include "Shift.h"
#include <vector>

class Person
{
public:
	Person(void);
	Person(std::string,int);
	~Person(void);
	//Add a shift to the Person's unavailableShifts list
	bool setUnavailableShift(Shift*);
	//Remove a shift from the Person's unavailableShifts list
	bool delUnavailableShift(Shift*);
	void clearUnavailableShifts();
	int maxShiftsPerDay;
	std::string name;
	std::vector<Shift*> unavailableShifts;
	//Dynamic-sized array of all Persons
	static std::vector<Person*> persons;
	//For the algorithm
	std::vector<Shift*> assignedShifts;
	std::vector<Shift*> availableShifts;
	std::vector<Shift*> testAvailableShifts;
};

#endif