#include "MenuEditing.h"


MenuEditing::MenuEditing(void)
{
}

void MenuEditing::draw(sf::RenderWindow* window, sf::Font* font) {
	sf::RectangleShape bg(sf::Vector2f(325,450));
	bg.setFillColor(sf::Color(192,255,62));
	bg.setPosition(337,75);
	bg.setOutlineThickness(5);
	bg.setOutlineColor(sf::Color(128,128,30));
	window->draw(bg);

	sf::RectangleShape editButton(sf::Vector2f(225,75));
	editButton.setFillColor(sf::Color(180,180,0));
	editButton.setPosition(387,125);
	window->draw(editButton);
	editButton.move(0,115);
	window->draw(editButton);
	editButton.move(0,115);
	window->draw(editButton);
	sf::RectangleShape cancelButton(sf::Vector2f(80,24));
	cancelButton.setFillColor(sf::Color(180,180,0));
	cancelButton.setPosition(459,465);
	window->draw(cancelButton);

	sf::Text editText("New Event",*font,35);
	editText.setColor(sf::Color());
	editText.setPosition(405,142);
	window->draw(editText);
	editText.setString("New Shift");
	editText.move(0,115);
	window->draw(editText);
	editText.setString("New Person");
	editText.move(-10,115);
	window->draw(editText);
	sf::Text cancelText("Cancel",*font,20);
	cancelText.setColor(sf::Color());
	cancelText.setPosition(465,465);
	window->draw(cancelText);
}

void MenuEditing::initButtons(ButtonHelper* screen, PrgmState* currentState) {
	ButtonChangeState* editEventButton = new ButtonChangeState(sf::Vector2i(387,125),sf::Vector2i(612,200),screen,currentState,eventCreation);
	ButtonChangeState* editShiftButton = new ButtonChangeState(sf::Vector2i(387,240),sf::Vector2i(612,315),screen,currentState,shiftCreation);
	ButtonChangeState* editPersonButton = new ButtonChangeState(sf::Vector2i(387,355),sf::Vector2i(612,430),screen,currentState,personCreation);
	ButtonCancel* cancelButton = new ButtonCancel(sf::Vector2i(459,465),sf::Vector2i(539,489),screen,currentState);
}

MenuEditing::~MenuEditing(void)
{
}
