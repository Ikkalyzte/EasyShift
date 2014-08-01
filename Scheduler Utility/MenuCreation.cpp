#include "MenuCreation.h"


MenuCreation::MenuCreation(void) {

}

void MenuCreation::draw(sf::RenderWindow* window, sf::Font* font) {
	sf::RectangleShape bg(sf::Vector2f(325,450));
	bg.setFillColor(sf::Color(192,255,62));
	bg.setPosition(337,75);
	bg.setOutlineThickness(5);
	bg.setOutlineColor(sf::Color(128,128,30));
	window->draw(bg);

	sf::RectangleShape newButton(sf::Vector2f(225,75));
	newButton.setFillColor(sf::Color(180,180,0));
	newButton.setPosition(387,125);
	window->draw(newButton);
	newButton.move(0,115);
	window->draw(newButton);
	newButton.move(0,115);
	window->draw(newButton);
	sf::RectangleShape cancelButton(sf::Vector2f(80,24));
	cancelButton.setFillColor(sf::Color(180,180,0));
	cancelButton.setPosition(459,465);
	window->draw(cancelButton);

	sf::Text newText("New Event",*font,35);
	newText.setColor(sf::Color());
	newText.setPosition(405,142);
	window->draw(newText);
	newText.setString("New Shift");
	newText.move(0,115);
	window->draw(newText);
	newText.setString("New Person");
	newText.move(-10,115);
	window->draw(newText);
	sf::Text cancelText("Cancel",*font,20);
	cancelText.setColor(sf::Color());
	cancelText.setPosition(465,465);
	window->draw(cancelText);
}

void MenuCreation::initButtons(ButtonHelper* screen, PrgmState* currentState) {
	ButtonChangeState* newEventButton = new ButtonChangeState(sf::Vector2i(387,125),sf::Vector2i(612,200),screen,currentState,eventCreation);
	ButtonChangeState* newShiftButton = new ButtonChangeState(sf::Vector2i(387,240),sf::Vector2i(612,315),screen,currentState,shiftCreation,MenuShiftCreation::load);
	ButtonChangeState* newPersonButton = new ButtonChangeState(sf::Vector2i(387,355),sf::Vector2i(612,430),screen,currentState,personCreation,MenuPersonCreation::load);
	ButtonCancel* cancelButton = new ButtonCancel(sf::Vector2i(459,465),sf::Vector2i(539,489),screen,currentState);
}

MenuCreation::~MenuCreation(void) {

}
