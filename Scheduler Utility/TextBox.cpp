#include "TextBox.h"
#include <iostream>

TextBox::TextBox(void) {

}

TextBox::TextBox(sf::Vector2i tl, sf::Vector2i br, ButtonHelper* screen, TextBox** activeTextBox):Button(tl,br,screen),activeTextBox(activeTextBox) {
	maxLineWidth = floor((br.x-tl.x)/12);
	maxLines = floor((br.y-tl.y)/20);
	maxChars = maxLineWidth*maxLines;
}

bool TextBox::type(sf::Event::TextEvent character) {
	if (character.unicode == 8)
		this->backspace();
	else if (character.unicode<32 || character.unicode>126)
		return false;
	else if (inputText.length()==maxChars)
		return false;
	else {
		std::string stringToAdd;
		sf::Utf32::encodeAnsi(character.unicode,std::back_inserter(stringToAdd),0,std::locale::classic());
		inputText += stringToAdd;
	}
	return true;
}

bool TextBox::backspace() {
	if (inputText.length()==0)
		return false;
	else
		inputText.pop_back();
	return true;
}

bool TextBox::clear() {
	if (inputText.length()==0)
		return false;
	else
		inputText.clear();
	return true;
}

void TextBox::click() {
	*activeTextBox = this;
}

void TextBox::draw(sf::RenderWindow* window, sf::Font* font) {
	if (inputText.length()>0) {
		std::vector<std::string> textLines;
		for (int i = 0; i < maxLines; i++) {
			try {
				textLines.push_back(inputText.substr(i*maxLineWidth,maxLineWidth));
			}
			catch (const std::out_of_range& oorException) {
				break;
			}
		}
		int iterInt = 0;
		for (std::vector<std::string>::const_iterator i = textLines.begin(); i != textLines.end(); ++i) {
			sf::Text line = sf::Text(*i,*font,20);
			line.setPosition(tl.x,tl.y + 20*iterInt - 2);
			line.setColor(sf::Color());
			window->draw(line);
			iterInt++;
		}
	}
}

TextBox::~TextBox(void) {

}
