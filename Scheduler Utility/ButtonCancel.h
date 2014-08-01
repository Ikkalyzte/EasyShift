#pragma once
#ifndef BUTTONCANCEL_INCLUDED
#define BUTTONCANCEL_INCLUDED
#include "button.h"
#include "PrgmState.h"


class ButtonCancel :
	public Button
{
public:
	ButtonCancel(void);
	ButtonCancel(sf::Vector2i,sf::Vector2i,ButtonHelper*,PrgmState*);
	PrgmState* prgmCurrentState;
	void click();
	~ButtonCancel(void);
};

#endif