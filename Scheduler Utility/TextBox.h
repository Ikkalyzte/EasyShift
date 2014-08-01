#pragma once
#ifndef TEXTBOX_INCLUDED
#define TEXTBOX_INCLUDED
#include "ButtonHelper.h"
#include <SFML\Graphics.hpp>
#include "Button.h"

class TextBox:
	public Button
{
public:
	TextBox(void);
	TextBox(sf::Vector2i,sf::Vector2i,ButtonHelper*,TextBox**);
	bool type(sf::Event::TextEvent);
	bool backspace();
	bool clear();
	void click();
	void draw(sf::RenderWindow*,sf::Font*);
	std::string inputText;
	int maxChars;
	int maxLines;
	int maxLineWidth;
	TextBox** activeTextBox;
	~TextBox(void);
};

#endif