#include "ButtonCancel.h"


ButtonCancel::ButtonCancel(void) {

}

ButtonCancel::ButtonCancel(sf::Vector2i tl,sf::Vector2i br,ButtonHelper* activeScreen,PrgmState* currentState):Button(tl,br,activeScreen),prgmCurrentState(currentState) {
	
}

void ButtonCancel::click() {
	(*prgmCurrentState)--;
}

ButtonCancel::~ButtonCancel(void) {

}
