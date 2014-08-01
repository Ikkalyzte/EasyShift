#pragma once
#ifndef MENUERROR_INCLUDED
#define MENUERROR_INCLUDED
#include <SFML\Graphics.hpp>
#include "ButtonHelper.h"
#include "PrgmState.h"
#include "ButtonCancel.h"

class MenuError
{
public:
	MenuError(void);
	static void draw(sf::RenderWindow*,sf::Font*);
	static void initButtons(ButtonHelper*,PrgmState*);
	~MenuError(void);
};

#endif