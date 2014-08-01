#pragma once
#ifndef DISPLAYSHIFT_INCLUDED
#define DISPLAYSHIFT_INCLUDED
#include "Shift.h"
#include "ButtonHelper.h"
#include "ButtonChangeState.h"
#include "SelectableList.h"
#include <SFML\Graphics.hpp>
#include <ctime>
#include <vector>

class DisplayShift
{
public:
	friend class Shift;
	friend class Calendar;
	DisplayShift(void);
	static tm* dateShown;
	static SelectableList<Shift>* shiftList;
	static SelectableList<Person>* personAssignedList;
	static void selectDate(tm);
	static void selectShift(std::vector<Shift*>);
	static void draw(sf::RenderWindow*, sf::Font*);
	static void initButtons(ButtonHelper*,PrgmState*);
	~DisplayShift(void);
};

#endif