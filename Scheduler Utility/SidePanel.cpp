#include "SidePanel.h"
#include "Calendar.h"

tm* SidePanel::dateShown = new tm();

SidePanel::SidePanel(void) {

}

void SidePanel::draw(sf::RenderWindow* window,sf::Font* font) {
	sf::RectangleShape bg(sf::Vector2f(290,600));
	bg.setFillColor(sf::Color(200,200,115));
	bg.setPosition(710,0);
	window->draw(bg);

	std::string dateString = Calendar::months[dateShown->tm_mon];
	dateString += " ";
	dateString += std::to_string(dateShown->tm_mday);
	dateString += ", ";
	dateString += std::to_string(dateShown->tm_year + 1900);
	sf::Text dateText(dateString,*font,20);
	dateText.setPosition(716,-2);
	dateText.setColor(sf::Color(0,0,0));
	window->draw(dateText);

	DisplayShift::draw(window,font);

	sf::RectangleShape bottomline(sf::Vector2f(290,5));
	bottomline.setFillColor(sf::Color(100,100,55));
	bottomline.setPosition(710,560);
	window->draw(bottomline);
	sf::RectangleShape newButton(sf::Vector2f(82,20));
	newButton.setPosition(720,570);
	newButton.setFillColor(sf::Color(255,255,80));
	window->draw(newButton);
	sf::RectangleShape editButton(newButton);
	editButton.move(94,0);
	window->draw(editButton);
	sf::RectangleShape deleteButton(editButton);
	deleteButton.move(94,0);
	window->draw(deleteButton);

	sf::Text newText("New", *font, 20);
	newText.setPosition(726,568);
	newText.setColor(sf::Color());
	window->draw(newText);
	sf::Text editText(newText);
	editText.setString("Edit");
	editText.move(94,0);
	window->draw(editText);
	sf::Text deleteText(editText);
	deleteText.setString("Delete");
	deleteText.move(94,0);
	window->draw(deleteText);
}

void SidePanel::initButtons(ButtonHelper* activeScreen, PrgmState* currentState) {
	ButtonChangeState* newButton = new ButtonChangeState(sf::Vector2i(720,570),sf::Vector2i(802,590),activeScreen,currentState,creation);
	DisplayShift::initButtons(activeScreen,currentState);
}

void SidePanel::selectDate(tm dateToSelect) {
	*dateShown = dateToSelect;
	DisplayShift::selectDate(dateToSelect);
}

SidePanel::~SidePanel(void) {

}
