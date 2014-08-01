#pragma once
#ifndef CALENDAR_INCLUDED
#define CALENDAR_INCLUDED

#include <SFML\Graphics.hpp>
#include "ButtonHelper.h"
#include "DisplayShift.h"
#include <vector>
#include <ctime>
#include "SidePanel.h"
class ButtonDate;

class Calendar
{
public:
	Calendar(void);
	static void draw(sf::RenderWindow*, sf::Font*);
	static void shiftMonth(int);
	static void selectDate(tm);
	static void deselectDate();
	static void initButtons(ButtonHelper*);
	static void updateButtons();
	static tm* today;
	static time_t todayInSec;
	static std::string weekdays[7];
	static std::string months[12];
	static tm* firstDay;
	static tm* selectedDate;
	static std::vector<ButtonDate*> dateButtons;
	~Calendar(void);
};

#endif