#include "ButtonChangeState.h"
#include <iostream>


ButtonChangeState::ButtonChangeState(void) {

}

ButtonChangeState::ButtonChangeState(sf::Vector2i tl,sf::Vector2i br,ButtonHelper* activeScreen,PrgmState* currentState,PrgmState target):Button(tl,br,activeScreen),targetState(target),prgmCurrentState(currentState) {
	
}

ButtonChangeState::ButtonChangeState(sf::Vector2i tl,sf::Vector2i br,ButtonHelper* activeScreen,PrgmState* currentState,PrgmState target,void (*loadFunc)()):Button(tl,br,activeScreen),targetState(target),prgmCurrentState(currentState),load(loadFunc) {
	
}

void ButtonChangeState::click() {
	*prgmCurrentState = targetState;
	if (load)
		load();
}

ButtonChangeState::~ButtonChangeState(void) {

}
