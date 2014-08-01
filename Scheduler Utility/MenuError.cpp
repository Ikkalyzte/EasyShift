#include "MenuError.h"


MenuError::MenuError(void) {

}

void MenuError::draw(sf::RenderWindow* window,sf::Font* font) {
	sf::RectangleShape bg(sf::Vector2f(300,150));
	bg.setPosition(250,175);
	bg.setFillColor(sf::Color(150,150,255));
	bg.setOutlineThickness(3);
	bg.setOutlineColor(sf::Color(0,0,255));
	window->draw(bg);

	sf::Text errorText("User input error!",*font,20);
	errorText.setColor(sf::Color());
	errorText.setPosition(265,200);
	window->draw(errorText);
	errorText.move(0,20);
	errorText.setString("Event: Name conflicts or is missing");
	window->draw(errorText);
	errorText.move(0,20);
	errorText.setString("Shift: Numbers illogical");
	window->draw(errorText);

	sf::RectangleShape buttonOk(sf::Vector2f(50,28));
	buttonOk.setFillColor(sf::Color(230,125,255));
	buttonOk.setPosition(438,280);
	window->draw(buttonOk);

	sf::Text okText("OK",*font,17);
	okText.setPosition(450,282);
	okText.setColor(sf::Color());
	window->draw(okText);
}

void MenuError::initButtons(ButtonHelper* screen,PrgmState* currentState) {
	ButtonCancel* okButton = new ButtonCancel(sf::Vector2i(450,280),sf::Vector2i(500,308),screen,currentState);
}

MenuError::~MenuError(void) {

}
