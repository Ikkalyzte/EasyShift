#pragma once
#ifndef MENUEVENTCREATION_INCLUDED
#define MENUEVENTCREATION_INCLUDED
#include "ButtonHelper.h"
#include "TextBox.h"
#include <SFML\Graphics.hpp>
#include "ButtonSave.h"
#include "ButtonCancel.h"
#include "Event.h"

class MenuEventCreation
{
public:
	MenuEventCreation(void);
	~MenuEventCreation(void);
	static void draw(sf::RenderWindow*,sf::Font*);
	static void initButtons(ButtonHelper*,PrgmState*,TextBox**);
	static bool save();
	static TextBox* nameTextBox;
	static TextBox* locationTextBox;
	static TextBox* descriptionTextBox;
};

#endif