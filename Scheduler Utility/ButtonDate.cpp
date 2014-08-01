#include "ButtonDate.h"


ButtonDate::ButtonDate(void) {

}

ButtonDate::ButtonDate(sf::Vector2i tl, sf::Vector2i br, ButtonHelper* activeScreen, tm date)
	:Button(tl,br,activeScreen),date(date) {
}

void ButtonDate::click() {
	Calendar::selectDate(date);
}

void ButtonDate::setDate(tm dateToSet) {
	date = dateToSet;
}

ButtonDate::~ButtonDate(void) {

}
