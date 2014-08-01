#pragma once
#ifndef BUTTONCHANGESTATE_INCLUDED
#define BUTTONCHANGESTATE_INCLUDED
#include "Button.h"
#include "PrgmState.h"

class ButtonChangeState :
	public Button
{
public:
	friend class DisplayShift;
	ButtonChangeState(void);
	ButtonChangeState(sf::Vector2i,sf::Vector2i,ButtonHelper*,PrgmState*,PrgmState);
	ButtonChangeState(sf::Vector2i,sf::Vector2i,ButtonHelper*,PrgmState*,PrgmState,void(*)());
	PrgmState* prgmCurrentState;
	PrgmState targetState;
	void click();
	void (*load)();
	~ButtonChangeState(void);
};

#endif