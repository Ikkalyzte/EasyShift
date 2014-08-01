#pragma once
#include "Button.h"
#include "IScrollable.h"

class ButtonScroll :
	public Button
{
public:
	ButtonScroll(void);
	ButtonScroll(sf::Vector2i, sf::Vector2i, ButtonHelper*,IScrollable*,int);
	void click();
	sf::Vector2i tl, br;
	int amt;
	IScrollable* item;
	~ButtonScroll(void);
};