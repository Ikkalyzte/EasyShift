#include "ButtonHelper.h"
#include "Button.h"
#include "Scroll.h"
#include <iostream>

ButtonHelper::ButtonHelper(void) {
	
}

void ButtonHelper::setButton(Button* buttonToAdd) {
	activeButtons.push_back(buttonToAdd);
}

void ButtonHelper::delButton(Button* buttonToDelete) {
	for(std::vector<Button*>::const_iterator i=activeButtons.begin(); i!=activeButtons.end(); ++i) {
		if (*i == buttonToDelete) {
			activeButtons.erase(i);
			break;
		}
    }
}

void ButtonHelper::setScroll(Scroll* scrollToAdd) {
	activeScrolls.push_back(scrollToAdd);
}

void ButtonHelper::delScroll(Scroll* scrollToDelete) {
	for(std::vector<Scroll*>::const_iterator i=activeScrolls.begin(); i!=activeScrolls.end(); ++i) {
		if (*i == scrollToDelete) {
			activeScrolls.erase(i);
			break;
		}
    }
}

bool ButtonHelper::click(sf::Vector2i coord) {
	for(std::vector<Button*>::const_iterator i=activeButtons.begin(); i!=activeButtons.end(); ++i) {
		if (containsCoord(*i,coord) && (*i)->isActive && (*i == selectedButton)) {
			(*i)->click();
			deselect();
			std::cout<<"Clicked "<<this;
			return true;
		}
	}
	deselect();
	return false;
}

bool ButtonHelper::select(sf::Vector2i coord) {
	for(std::vector<Button*>::const_iterator i=activeButtons.begin(); i!=activeButtons.end(); ++i) {
		if (containsCoord(*i,coord) && (*i)->isActive) {
			selectedButton = *i;
			return true;
		}
	}
	return false;
}

bool ButtonHelper::scroll(sf::Vector2i coord,int amt) {
	for(std::vector<Scroll*>::const_iterator i=activeScrolls.begin(); i!=activeScrolls.end(); ++i) {
		if (containsCoord(*i,coord)) {
			std::cout<<"contained coord in "<<(*i);
			(*i)->scroll(amt);
			deselect();
			return true;
		}
	}
	deselect();
	return false;
}

void ButtonHelper::deselect() {
	selectedButton = NULL;
}

void ButtonHelper::highlight(sf::RenderWindow* window) {
	if (selectedButton!=NULL) {
		sf::RectangleShape selectBox(sf::Vector2f(selectedButton->br.x - selectedButton->tl.x,selectedButton->br.y - selectedButton->tl.y));
		selectBox.setPosition(selectedButton->tl.x,selectedButton->tl.y);
		selectBox.setFillColor(sf::Color(255,255,255,128));
		window->draw(selectBox);
	}
}

bool ButtonHelper::containsCoord(void* rect, sf::Vector2i coord) {
	Button* button = (Button*)rect;
	if (button->br.x > coord.x && coord.x > button->tl.x && button->br.y > coord.y && coord.y > button->tl.y)
		return true;
	else
		return false;
}

ButtonHelper::~ButtonHelper(void) {
}
