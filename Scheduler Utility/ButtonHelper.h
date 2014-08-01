#pragma once
#ifndef BUTTONHELPER_INCLUDED
#define BUTTONHELPER_INCLUDED
#include <SFML\Graphics.hpp>
#include <vector>
class Button;
class Scroll;
class TextBox;

//An interactive screen manager. Each instance is its own clickable "screen". Only one should be active at once.
class ButtonHelper
{
public:
	ButtonHelper(void);
	~ButtonHelper(void);
	static bool containsCoord(void*,sf::Vector2i);
	//Selects the correct button, returns success. Arguments: coords of click
	bool select(sf::Vector2i);
	//Clicks on the correct button, returns success. Arguments: coords of click
	bool click(sf::Vector2i);
	//Scrolls the given amount on the correct scroll area. Arguments: coords, scroll amount
	bool scroll(sf::Vector2i,int);
	//Add a button to the active list. Arguments: pointer to button
	void setButton(Button*);
	//Remove a button from the active list. Arguments: pointer to button
	void delButton(Button*);
	//Add a scroll to the active list.
	void setScroll(Scroll*);
	//Remove a scroll from the list
	void delScroll(Scroll*);
	//Clear the selected button
	void deselect();
	//Highlights the selected button
	void highlight(sf::RenderWindow*);
	//Dynamic-sized array of currently "clickable" buttons
	std::vector<Button*> activeButtons;
	//Dynamic-sized array of currrently "scrollable" areas
	std::vector<Scroll*> activeScrolls;
	//Currently selected button
	Button* selectedButton;
};

#endif