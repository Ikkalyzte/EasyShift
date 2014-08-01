#pragma once
#ifndef BUTTONMONTHCHANGE_INCLUDED
#define BUTTONMONTHCHANGE_INCLUDED

#include "Button.h"
#include <SFML\Graphics.hpp>
#include "Calendar.h"

class ButtonMonthChange :
	public Button
{
public:
	friend class Calendar;
	ButtonMonthChange(void);
	~ButtonMonthChange(void);
	//Arguments: top left, bottom right, active sceen, whether this shifts months forward
	ButtonMonthChange(sf::Vector2i, sf::Vector2i, ButtonHelper*,int);
	void click();
	//How far + which direction it shifts
	int shiftAmt;
};

#endif