#pragma once
#ifndef MENUCREATION_INCLUDED
#define MENUCREATION_INCLUDED
#include <SFML\Graphics.hpp>
#include "ButtonHelper.h"
#include "ButtonChangeState.h"
#include "ButtonCancel.h"
#include "MenuShiftCreation.h"
#include "MenuPersonCreation.h"

class MenuCreation
{
public:
	MenuCreation(void);
	static void draw(sf::RenderWindow*,sf::Font*);
	static void initButtons(ButtonHelper*,PrgmState*);
	~MenuCreation(void);
};

#endif