#include "ButtonSave.h"


ButtonSave::ButtonSave(void) {

}

ButtonSave::ButtonSave(sf::Vector2i tl,sf::Vector2i br,ButtonHelper* activeScreen,PrgmState* currentState,bool (*saveFunc)()):Button(tl,br,activeScreen),prgmCurrentState(currentState),save(saveFunc) {
	
}

void ButtonSave::click() {
	if (save())
		*prgmCurrentState = background;
	else
		(*prgmCurrentState)++;
}

ButtonSave::~ButtonSave(void) {

}
