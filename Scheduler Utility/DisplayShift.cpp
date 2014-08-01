#include "DisplayShift.h"
#include "Calendar.h"
#include <iostream>

tm* DisplayShift::dateShown = new tm();
SelectableList<Shift>* DisplayShift::shiftList = new SelectableList<Shift>();
SelectableList<Person>* DisplayShift::personAssignedList = new SelectableList<Person>();

DisplayShift::DisplayShift(void) {

}

void DisplayShift::selectDate(tm dateToSelect) {
	*dateShown = dateToSelect;
	shiftList->clearList();
	bool startedDayShifts = false;
	if (Shift::shifts.size()==0)
		return;
	for(std::vector<Shift*>::const_iterator i=Shift::shifts.begin(); i!=Shift::shifts.end(); ++i) {
		switch (startedDayShifts) {
		case false:
			if ((*i)->start.tm_mon==dateShown->tm_mon && (*i)->start.tm_mday==dateShown->tm_mday && (*i)->start.tm_year==dateShown->tm_year) {
				shiftList->addItem(*i);
				startedDayShifts = true;
			}
			break;
		case true:
			if ((*i)->start.tm_mon==dateShown->tm_mon && (*i)->start.tm_mday==dateShown->tm_mday && (*i)->start.tm_year==dateShown->tm_year)
				shiftList->addItem(*i);
			else {
				shiftList->updateButtons();
				return;
			}
			break;
		}
	}
	shiftList->updateButtons();
}

void DisplayShift::selectShift(std::vector<Shift*> selectedShift) {
	personAssignedList->clearList();
	for (std::vector<Person*>::const_iterator i = selectedShift[0]->assignedPersons.begin(); i!= selectedShift[0]->assignedPersons.end(); i++)
		personAssignedList->addItem(*i);
	personAssignedList->updateButtons();
}

void DisplayShift::draw(sf::RenderWindow* window, sf::Font* font) {
	shiftList->draw(window,font);

	sf::RectangleShape editButton(sf::Vector2f(125,20));
	editButton.setPosition(715,331);
	editButton.setFillColor(sf::Color(255,255,80));
	window->draw(editButton);
	sf::RectangleShape deleteButton(editButton);
	deleteButton.move(133,0);
	deleteButton.setSize(sf::Vector2f(148,20));
	window->draw(deleteButton);
	sf::Text newText("Edit Shift", *font, 20);
	newText.setPosition(718,329);
	newText.setColor(sf::Color());
	window->draw(newText);
	sf::Text editText(newText);
	editText.setString("Delete Shift");
	editText.move(133,0);
	window->draw(editText);

	sf::RectangleShape midline(sf::Vector2f(290,2));
	midline.setFillColor(sf::Color(100,100,55));
	midline.setPosition(710,355);
	window->draw(midline);

	sf::Text titleText("Assigned Persons:", *font, 20);
	titleText.setColor(sf::Color());
	titleText.setPosition(716,357);
	window->draw(titleText);
}

void DisplayShift::initButtons(ButtonHelper* activeScreen, PrgmState* currentState) {
	shiftList = new SelectableList<Shift>(activeScreen,sf::Vector2f(713,30),sf::Vector2f(284,295),12,1,20);
	personAssignedList = new SelectableList<Person>(activeScreen,sf::Vector2f(713,360),sf::Vector2f(287,250),8,1,20);
}

DisplayShift::~DisplayShift(void) {
	delete dateShown;
	delete shiftList;
}
