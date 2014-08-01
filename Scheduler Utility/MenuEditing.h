#pragma once
#ifndef MENUEDITING_INCLUDED
#define MENUEDITING_INCLUDED

#include <SFML\Graphics.hpp>
#include "ButtonHelper.h"
#include "ButtonChangeState.h"
#include "ButtonCancel.h"

class MenuEditing
{
public:
	MenuEditing(void);
	static void draw(sf::RenderWindow*,sf::Font*);
	static void initButtons(ButtonHelper*,PrgmState*);
	~MenuEditing(void);
};

#endif