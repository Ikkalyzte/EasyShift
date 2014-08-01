#pragma once
#ifndef SIDEPANEL_INCLUDED
#define SIDEPANEL_INCLUDED
#include <SFML\Graphics.hpp>
#include "ButtonChangeState.h"
#include "ButtonHelper.h"
#include "SelectableList.h"
#include <ctime>

class SidePanel
{
public:
	SidePanel(void);
	static tm* dateShown;
	static void selectDate(tm);
	static void initButtons(ButtonHelper*,PrgmState*);
	static void draw(sf::RenderWindow*,sf::Font*);
	~SidePanel(void);
};

#endif