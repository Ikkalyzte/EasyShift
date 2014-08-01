#include "ButtonMonthChange.h"

ButtonMonthChange::ButtonMonthChange(void) {

}

ButtonMonthChange::ButtonMonthChange(sf::Vector2i tl, sf::Vector2i br, ButtonHelper* activeScreen, int shiftAmt)
	:Button(tl,br,activeScreen),shiftAmt(shiftAmt) {

}

void ButtonMonthChange::click() {
	Calendar::shiftMonth(shiftAmt);
}

ButtonMonthChange::~ButtonMonthChange(void) {

}
