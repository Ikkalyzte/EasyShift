#include "Scroll.h"
#include <iostream>

Scroll::Scroll(void) {

}

Scroll::Scroll(sf::Vector2i tl, sf::Vector2i br, ButtonHelper* screen, IScrollable* list):tl(tl),br(br),list(list) {
	screen->setScroll(this);
	std::cout<<this<<" is at "<<tl.x<<" by "<<tl.y<<" to "<<br.x<<" by "<<br.y<<std::endl;
}

void Scroll::scroll(int amt) {
	list->scroll(amt);
}

Scroll::~Scroll(void)
{
}
