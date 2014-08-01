#pragma once
#ifndef SHIFT_INCLUDED
#define SHIFT_INCLUDED
#include <ctime>
#include <vector>
#include <string>
#include "Event.h"
class Person;

//One duration of time, also stores whoever is allotted to it
class Shift
{
public:
	Shift();
	//Arguments: start, end, max people, min people, owner Event
	Shift(tm, tm, int, int, Event*);
	static void delShift(Shift*);
	~Shift(void);
	bool precedes(Shift*);
	tm start;
	tm end;
	//Number of people required for this shift
	int minPeople;
	int maxPeople;
	//For testing usage
	int testMinPeople;
	int testMaxPeople;
	//Event to which this shift belongs
	Event* ownerEvent;
	//Dynamic-sized array of people in this shift
	std::vector<Person*> assignedPersons;
	//Amount of people available
	std::vector<Person*> availablePersons;
	//For testing usage
	std::vector<Person*> testAvailablePersons;
	//Dynamic-sized array of all shifts in current schedule
	static std::vector<Shift*> shifts;
};

#endif