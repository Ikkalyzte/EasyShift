#pragma once
#ifndef SELECTABLELIST_INCLUDED
#define SELECTABLELIST_INCLUDED
#include "ButtonHelper.h"
#include "Shift.h"
#include "Person.h"
#include "Event.h"
#include "IScrollable.h"
#include <SFML\Graphics.hpp>
#include <vector>

template <class I>
class ButtonListSelect;

class Scroll;

template <class I>
class SelectableList : IScrollable
{
public:
	SelectableList(void);
	//Arguments: Screen on which to display, position, size, amount to show at once, maximum selected, font size
	SelectableList(ButtonHelper*,sf::Vector2f,sf::Vector2f,int,int,int);
	SelectableList(ButtonHelper*,sf::Vector2f,sf::Vector2f,int,int,int,void(*)(std::vector<I*>));
	void draw(sf::RenderWindow*,sf::Font*);
	void updateButtons();
	void selectItem(int);
	void addItem(I*);
	void clearList();
	void scroll(int);
	std::string createString(Shift*);
	std::string createString(Person*);
	std::string createString(Event*);
	~SelectableList(void);
	std::vector<I*> items;
	std::vector<I*> selectedItems;
	std::vector<ButtonListSelect<I>*> listButtons;
	int amtDisplayed;
	int listOffset;
	int maxSelected;
	int fontSize;
	void (*update)(std::vector<I*>);
	sf::Vector2f position;
	sf::Vector2f size;
	Scroll* scrollArea;
};

#endif