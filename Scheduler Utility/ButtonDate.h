#pragma once
#ifndef BUTTONDATE_INCLUDED
#define BUTTONDATE_INCLUDED

#include "Button.h"
#include "Calendar.h"

class ButtonDate :
	public Button
{
public:
	friend class Calendar;
	ButtonDate(void);
	ButtonDate(sf::Vector2i,sf::Vector2i,ButtonHelper*,tm);
	void click();
	void setDate(tm);
	tm date;
	~ButtonDate(void);
};

#endif