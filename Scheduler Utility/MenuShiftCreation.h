#pragma once
#ifndef MENUSHIFTCREATION_INCLUDED
#define MENUSHIFTCREATION_INCLUDED
#include "ButtonHelper.h"
#include <SFML\Graphics.hpp>
#include "LoopInt.h"
#include "ButtonCancel.h"
#include "ButtonScroll.h"
#include "SelectableList.h"
#include "Calendar.h"
#include "ButtonSave.h"

class MenuShiftCreation
{
	friend class Calendar;
public:
	static LoopInt
		startHourTens, startHourOnes, startMinTens, startMinOnes,
		endHourTens, endHourOnes, endMinTens, endMinOnes,
		peopleMinTens, peopleMinOnes,
		peopleMaxTens, peopleMaxOnes,
		repeatAmtTens, repeatAmtOnes,
		repeatFreqNum;
	static std::string repeatFreqStr[4];
	static SelectableList<Event>* eventList;
	MenuShiftCreation(void);
	~MenuShiftCreation(void);
	static void draw(sf::RenderWindow*,sf::Font*);
	static void update();
	static void initButtons(ButtonHelper*,PrgmState*);
	static void load();
	static bool save();
};

#endif