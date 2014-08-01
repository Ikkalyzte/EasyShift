#pragma once
#include <SFML\Graphics.hpp>
#include "ButtonHelper.h"
#include "SelectableList.h"
#include "IScrollable.h"

class Scroll:
	public IScrollable
{
public:
	Scroll(void);
	Scroll(sf::Vector2i, sf::Vector2i, ButtonHelper*,IScrollable*);
	void scroll(int);
	sf::Vector2i tl, br;
	IScrollable* list;
	~Scroll(void);
};

