#pragma once
#ifndef DISPLAYEVENT_INCLUDED
#define DISPLAYEVENT_INCLUDED
#include <ctime>
#include "SelectableList.h"
#include "ButtonChangeState.h"

class DisplayEvent
{
public:
	friend class Event;
	DisplayEvent(void);
	static tm* dateShown;
	static SelectableList<Event>* eventList;
	static void selectDate(tm);
	static void draw(sf::RenderWindow*, sf::Font*);
	static void initButtons(ButtonHelper*,PrgmState*);
	~DisplayEvent(void);
};

#endif