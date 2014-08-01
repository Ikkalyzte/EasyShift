#pragma once
#ifndef BUTTON_INCLUDED
#define BUTTON_INCLUDED
#include <SFML\Graphics.hpp>
class ButtonHelper;

//Buttons! clicky clicky clicky
class Button
{
public:
	Button(void);
	~Button(void);
	//Arguments: top left, bottom right, active screen
	Button(sf::Vector2i, sf::Vector2i, ButtonHelper*);
	//Arguments: top left, bottom right, active screen, whether active
	Button(sf::Vector2i, sf::Vector2i, ButtonHelper*,bool);
	//Called on button click. Must be overridden in sub-class
	virtual void click();
	//Checks if given coord is within button's area. Arguments: coordinate
	bool containsCoord(sf::Vector2i);
	//Set the button's activity
	void setActive(bool);
	//Coords of corners
	sf::Vector2i tl, br;
	//Whether the individual button is "active"
	bool isActive;
};

#endif