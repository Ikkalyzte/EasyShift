#include "Button.h"
#include "ButtonHelper.h"
#include <iostream>

Button::Button(void) {

}

Button::Button(sf::Vector2i tl, sf::Vector2i br, ButtonHelper* activeScreen):tl(tl),br(br),isActive(true) {
	activeScreen->setButton(this);
}

Button::Button(sf::Vector2i tl, sf::Vector2i br, ButtonHelper* activeScreen, bool active):tl(tl),br(br),isActive(active) {
	activeScreen->setButton(this);
}

void Button::setActive(bool active) {
	isActive = active;
}

void Button::click() {
	std::cout << "Please use a sub-class for this button: " << this << std::endl;
}

Button::~Button(void) {

}
