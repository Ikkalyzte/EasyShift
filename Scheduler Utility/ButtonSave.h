#pragma once
#ifndef BUTTONSAVE_INCLUDED
#define BUTTONSAVE_INCLUDED
#include "Button.h"
#include "PrgmState.h"

class ButtonSave :
	public Button
{
public:
	ButtonSave(void);
	ButtonSave(sf::Vector2i,sf::Vector2i,ButtonHelper*,PrgmState*,bool(*)());
	PrgmState* prgmCurrentState;
	void click();
	bool (*save)();
	~ButtonSave(void);
};

#endif