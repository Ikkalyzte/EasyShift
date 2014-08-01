#include "ButtonScroll.h"


ButtonScroll::ButtonScroll(void) {

}

ButtonScroll::ButtonScroll(sf::Vector2i tl, sf::Vector2i br, ButtonHelper* screen, IScrollable* item, int amt):Button(tl,br,screen),item(item),amt(amt) {
	
}

void ButtonScroll::click() {
	item->scroll(amt);
}

ButtonScroll::~ButtonScroll(void)
{
}