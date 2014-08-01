#pragma once
#ifndef MENUPERSONCREATION_INCLUDED
#define MENUPERSONCREATION_INCLUDED
#include "ButtonHelper.h"
#include "ButtonSave.h"
#include <SFML\Graphics.hpp>
#include "TextBox.h"
#include "LoopInt.h"
#include "ButtonScroll.h"
#include "SelectableList.h"
#include "ButtonCancel.h"

class MenuPersonCreation
{
public:
	MenuPersonCreation(void);
	~MenuPersonCreation(void);
	static void draw(sf::RenderWindow*,sf::Font*);
	static void initButtons(ButtonHelper*,PrgmState*,TextBox**);
	static bool save();
	static void load();
	static TextBox* nameTextBox;
	static LoopInt maxShiftsPerDay;
	static SelectableList<Shift>* shiftList;
};

#endif