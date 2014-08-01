#include "Calendar.h"
#include "ButtonDate.h"
#include "ButtonMonthChange.h"
#include <iostream>

tm* Calendar::today = new tm();
time_t Calendar::todayInSec = 0;
tm* Calendar::firstDay = new tm();
tm* Calendar::selectedDate = new tm();
std::vector<ButtonDate*> Calendar::dateButtons(0);
std::string Calendar::weekdays[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
std::string Calendar::months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

Calendar::Calendar(void) {

}

void Calendar::draw(sf::RenderWindow* window, sf::Font* font) {
	sf::RectangleShape bg(sf::Vector2f(710,600));
	bg.setFillColor(sf::Color(255,255,115));
	window->draw(bg);

	tm* dateIter = new tm(*Calendar::firstDay);
	dateIter->tm_mday -= Calendar::firstDay->tm_wday;
	for (int y = 0; y <= 5; y++) {
		for (int x = 0; x <= 6; x++) {
			if (dateIter->tm_mon == today->tm_mon && dateIter->tm_mday == today->tm_mday && dateIter->tm_year == today->tm_year) {
				sf::RectangleShape todayHighlight(sf::Vector2f(100,85));
				todayHighlight.setPosition((x*100)+5,(y*85)+85);
				todayHighlight.setFillColor(sf::Color(145,145,0));
				window->draw(todayHighlight);
			}
			if (Calendar::selectedDate != NULL && mktime(dateIter) == mktime(Calendar::selectedDate)) {
				sf::RectangleShape selectedDayHighlight(sf::Vector2f(100,85));
				selectedDayHighlight.setPosition((x*100)+5,(y*85)+85);
				selectedDayHighlight.setFillColor(sf::Color(0,145,0));
				window->draw(selectedDayHighlight);
			}
			sf::RectangleShape dayBox(sf::Vector2f(90,75));
			dayBox.setPosition((x*100)+10,(y*85)+90);
			dayBox.setFillColor(sf::Color(215,215,0));
			window->draw(dayBox);
			sf::Text dateText(std::to_string(dateIter->tm_mday),*font,75);
			dateText.setPosition((x*100)+10,(y*85)+80);
			if (dateIter->tm_mon!=Calendar::firstDay->tm_mon)
				dateText.setColor(sf::Color(128,128,128));
			else
				dateText.setColor(sf::Color(64,64,64));
			window->draw(dateText);

			dateIter->tm_mday++;
			mktime(dateIter);
		}
	}

	for (int day = 0;day <= 6;day++) {
		sf::Text dayLabelText(weekdays[day],*font,15);
		dayLabelText.setPosition((day*100)+15,65);
		dayLabelText.setColor(sf::Color(0,0,0));
		window->draw(dayLabelText);
	}
	sf::RectangleShape rightArrow(sf::Vector2f(60,20));
	rightArrow.setPosition(640,10);
	rightArrow.setFillColor(sf::Color(205,205,0));
	window->draw(rightArrow);
	sf::Text rightArrowText("Next",*font,20);
	rightArrowText.setPosition(646,7);
	rightArrowText.setColor(sf::Color(0,0,0));
	window->draw(rightArrowText);

	sf::RectangleShape leftArrow(sf::Vector2f(60,20));
	leftArrow.setPosition(10,10);
	leftArrow.setFillColor(sf::Color(205,205,0));
	window->draw(leftArrow);
	sf::Text leftArrowText("Prev",*font,20);
	leftArrowText.setPosition(16,7);
	leftArrowText.setColor(sf::Color(0,0,0));
	window->draw(leftArrowText);

	std::string monthAndYear = months[firstDay->tm_mon];
	monthAndYear += " ";
	monthAndYear += std::to_string(firstDay->tm_year+1900);
	sf::Text monthAndYearText(monthAndYear,*font,30);
	monthAndYearText.setPosition(300,7);
	monthAndYearText.setColor(sf::Color(0,0,0));
	window->draw(monthAndYearText);
}

void Calendar::shiftMonth(int amt) {
	Calendar::firstDay->tm_mon += amt;
	mktime(Calendar::firstDay);
	updateButtons();
}

void Calendar::selectDate(tm dateToSelect) {
	*selectedDate = dateToSelect;
	SidePanel::selectDate(dateToSelect);
}

void Calendar::deselectDate() {
	selectedDate = NULL;
}

void Calendar::initButtons(ButtonHelper* activeScreen) {
	ButtonMonthChange* leftArrow = new ButtonMonthChange(sf::Vector2i(10,10),sf::Vector2i(70,30),activeScreen,-1);
	ButtonMonthChange* rightArrow = new ButtonMonthChange(sf::Vector2i(640,10),sf::Vector2i(700,30),activeScreen,1);
	
	tm* dateIter = new tm(*Calendar::firstDay);
	dateIter->tm_mday -= Calendar::firstDay->tm_wday;
	mktime(dateIter);
	for (int y = 0; y <= 5; y++) {
		for (int x = 0; x <= 6; x++) {
			ButtonDate* dateButton = new ButtonDate(sf::Vector2i((x*100)+10,(y*85)+90),sf::Vector2i((x*100)+100,(y*85)+165),activeScreen,*dateIter);
			dateButtons.push_back(dateButton);
			dateIter->tm_mday++;
			mktime(dateIter);
		}
	}
}

void Calendar::updateButtons() {
	tm* dateIter = new tm(*Calendar::firstDay);
	dateIter->tm_mday -= Calendar::firstDay->tm_wday;
	mktime(dateIter);
	for(std::vector<ButtonDate*>::const_iterator i=dateButtons.begin(); i!=dateButtons.end(); ++i) {
		(*i)->setDate(*dateIter);
		dateIter->tm_mday++;
		mktime(dateIter);
	}
}

Calendar::~Calendar(void) {
	delete today, firstDay, selectedDate;
}