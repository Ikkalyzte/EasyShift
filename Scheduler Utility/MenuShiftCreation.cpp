#include "MenuShiftCreation.h"
#include <iostream>

std::string MenuShiftCreation::repeatFreqStr[4];
LoopInt MenuShiftCreation::startHourTens(2);
LoopInt MenuShiftCreation::startHourOnes(9);
LoopInt MenuShiftCreation::startMinTens(5);
LoopInt MenuShiftCreation::startMinOnes(9);
LoopInt MenuShiftCreation::endHourTens(2);
LoopInt MenuShiftCreation::endHourOnes(9);
LoopInt MenuShiftCreation::endMinTens(5);
LoopInt MenuShiftCreation::endMinOnes(9,0,1);
LoopInt MenuShiftCreation::peopleMinTens(9);
LoopInt MenuShiftCreation::peopleMinOnes(9);
LoopInt MenuShiftCreation::peopleMaxTens(9);
LoopInt MenuShiftCreation::peopleMaxOnes(9,0,1);
LoopInt MenuShiftCreation::repeatAmtTens(9);
LoopInt MenuShiftCreation::repeatAmtOnes(9);
LoopInt MenuShiftCreation::repeatFreqNum(3);
SelectableList<Event>* MenuShiftCreation::eventList;

MenuShiftCreation::MenuShiftCreation(void) {

}

void MenuShiftCreation::draw(sf::RenderWindow* window, sf::Font* font) {
	sf::RectangleShape bg(sf::Vector2f(800,500));
	bg.setFillColor(sf::Color(192,255,62));
	bg.setPosition(100,50);
	bg.setOutlineThickness(5);
	bg.setOutlineColor(sf::Color(128,128,30));
	window->draw(bg);
	
	sf::RectangleShape saveButtonBox(sf::Vector2f(125,28));
	saveButtonBox.setPosition(500,500);
	saveButtonBox.setFillColor(sf::Color(180,180,0));
	window->draw(saveButtonBox);
	sf::RectangleShape cancelBox(sf::Vector2f(100,28));
	cancelBox.setPosition(365,500);
	cancelBox.setFillColor(sf::Color(180,180,0));
	window->draw(cancelBox);

	sf::Text startText("Start time:",*font,20);
	startText.setPosition(116,58);
	startText.setColor(sf::Color());
	window->draw(startText);
	sf::Text endText(startText);
	endText.move(200,0);
	endText.setString("End time:");
	window->draw(endText);
	sf::Text peopleText(startText);
	peopleText.move(0,200);
	peopleText.setString("Number of people required:");
	window->draw(peopleText);
	sf::Text repeatText(endText);
	repeatText.move(165,0);
	repeatText.setString("Repeat:");
	window->draw(repeatText);
	sf::Text locationText(repeatText);
	locationText.move(150,0);
	locationText.setString("Event:");
	window->draw(locationText);
	sf::Text maxMinText("Max:",*font,16);
	maxMinText.setColor(sf::Color());
	maxMinText.setPosition(120,400);
	window->draw(maxMinText);
	maxMinText.setString("Min:");
	maxMinText.move(140,0);
	window->draw(maxMinText);
	sf::Text repeatAmtLabel("Repeat",*font,16);
	repeatAmtLabel.setColor(sf::Color());
	repeatAmtLabel.setPosition(465,195);
	window->draw(repeatAmtLabel);
	repeatAmtLabel.setString("times");
	repeatAmtLabel.move(114,0);
	window->draw(repeatAmtLabel);
	sf::Text saveButtonText("Save Shift",*font,20);
	saveButtonText.setColor(sf::Color());
	saveButtonText.setPosition(502,500);
	window->draw(saveButtonText);
	sf::Text cancelButtonText("Cancel",*font,20);
	cancelButtonText.setColor(sf::Color());
	cancelButtonText.setPosition(367,500);
	window->draw(cancelButtonText);

	sf::RectangleShape numberBox(sf::Vector2f(20,30));
	numberBox.setPosition(120,155);
	numberBox.setFillColor(sf::Color(180,180,0));
	window->draw(numberBox);
	numberBox.move(25,0);
	window->draw(numberBox);
	numberBox.move(40,0);
	window->draw(numberBox);
	numberBox.move(25,0);
	window->draw(numberBox);
	numberBox.move(110,0);
	window->draw(numberBox);
	numberBox.move(25,0);
	window->draw(numberBox);
	numberBox.move(40,0);
	window->draw(numberBox);
	numberBox.move(25,0);
	window->draw(numberBox);
	numberBox.move(120,35);
	window->draw(numberBox);
	numberBox.move(25,0);
	window->draw(numberBox);
	sf::RectangleShape bigBox(sf::Vector2f(30,50));
	bigBox.setPosition(170,385);
	bigBox.setFillColor(sf::Color(180,180,0));
	window->draw(bigBox);
	bigBox.move(40,0);
	window->draw(bigBox);
	bigBox.move(100,0);
	window->draw(bigBox);
	bigBox.move(40,0);
	window->draw(bigBox);
	sf::RectangleShape repeatBox(sf::Vector2f(115,28));
	repeatBox.setPosition(495,116);
	repeatBox.setFillColor(sf::Color(180,180,0));
	window->draw(repeatBox);

	//Up & down arrows
	sf::ConvexShape triangle(3);
	triangle.setPoint(0,sf::Vector2f(0,15));
	triangle.setPoint(1,sf::Vector2f(20,15));
	triangle.setPoint(2,sf::Vector2f(10,0));
	//Up
	triangle.setFillColor(sf::Color(180,180,0));
	triangle.setPosition(120,134);
	window->draw(triangle);
	triangle.move(25,0);
	window->draw(triangle);
	triangle.move(40,0);
	window->draw(triangle);
	triangle.move(25,0);
	window->draw(triangle);
	triangle.move(110,0);
	window->draw(triangle);
	triangle.move(25,0);
	window->draw(triangle);
	triangle.move(40,0);
	window->draw(triangle);
	triangle.move(25,0);
	window->draw(triangle);
	triangle.move(120,35);
	window->draw(triangle);
	triangle.move(25,0);
	window->draw(triangle);
	triangle.move(-85,-57);
	window->draw(triangle);
	//Down
	triangle.setPosition(140,206);
	triangle.setRotation(180);
	window->draw(triangle);
	triangle.move(25,0);
	window->draw(triangle);
	triangle.move(40,0);
	window->draw(triangle);
	triangle.move(25,0);
	window->draw(triangle);
	triangle.move(110,0);
	window->draw(triangle);
	triangle.move(25,0);
	window->draw(triangle);
	triangle.move(40,0);
	window->draw(triangle);
	triangle.move(25,0);
	window->draw(triangle);
	triangle.move(120,35);
	window->draw(triangle);
	triangle.move(25,0);
	window->draw(triangle);
	triangle.move(-85,-93);
	window->draw(triangle);
	//Big
	triangle.scale(1.5,1.5);
	triangle.setPosition(200,470);
	window->draw(triangle);
	triangle.move(40,0);
	window->draw(triangle);
	triangle.move(100,0);
	window->draw(triangle);
	triangle.move(40,0);
	window->draw(triangle);
	triangle.setRotation(0);
	triangle.move(-210,-120);
	window->draw(triangle);
	triangle.move(40,0);
	window->draw(triangle);
	triangle.move(100,0);
	window->draw(triangle);
	triangle.move(40,0);
	window->draw(triangle);

	//Colons
	sf::Text colon(":",*font,35);
	colon.setColor(sf::Color());
	colon.setPosition(165,145);
	window->draw(colon);
	colon.move(200,0);
	window->draw(colon);
	//Variables
	sf::Text varText(startHourTens,*font,30);
	varText.setPosition(121,150);
	varText.setColor(sf::Color());
	window->draw(varText);
	varText.move(25,0);
	varText.setString(startHourOnes);
	window->draw(varText);
	varText.move(40,0);
	varText.setString(startMinTens);
	window->draw(varText);
	varText.move(25,0);
	varText.setString(startMinOnes);
	window->draw(varText);
	varText.move(110,0);
	varText.setString(endHourTens);
	window->draw(varText);
	varText.move(25,0);
	varText.setString(endHourOnes);
	window->draw(varText);
	varText.move(40,0);
	varText.setString(endMinTens);
	window->draw(varText);
	varText.move(25,0);
	varText.setString(endMinOnes);
	window->draw(varText);
	varText.move(120,35);
	varText.setString(repeatAmtTens);
	window->draw(varText);
	varText.move(25,0);
	varText.setString(repeatAmtOnes);
	window->draw(varText);
	
	sf::Text bigVarText(peopleMaxTens,*font,52);
	bigVarText.setPosition(170,376);
	bigVarText.setColor(sf::Color());
	window->draw(bigVarText);
	bigVarText.move(40,0);
	bigVarText.setString(peopleMaxOnes);
	window->draw(bigVarText);
	bigVarText.move(100,0);
	bigVarText.setString(peopleMinTens);
	window->draw(bigVarText);
	bigVarText.move(40,0);
	bigVarText.setString(peopleMinOnes);
	window->draw(bigVarText);

	sf::Text repeatFreqText(repeatFreqStr[repeatFreqNum],*font,20);
	repeatFreqText.setPosition(499,117);
	repeatFreqText.setColor(sf::Color());
	window->draw(repeatFreqText);

	eventList->draw(window,font);
}

void MenuShiftCreation::initButtons(ButtonHelper* screen, PrgmState* currentState) {
	//Init vars
	repeatFreqStr[0] = "Daily"; repeatFreqStr[1] = "Weekly"; repeatFreqStr[2] = "Bi-Weekly"; repeatFreqStr[3] = "Monthly";

	//Value-modification buttons
	ButtonScroll* upButtonStartHourTens = new ButtonScroll(sf::Vector2i(120,134),sf::Vector2i(140,149),screen,&startHourTens,1);
	ButtonScroll* upButtonStartHourOnes = new ButtonScroll(sf::Vector2i(145,134),sf::Vector2i(165,149),screen,&startHourOnes,1);
	ButtonScroll* upButtonStartMinTens = new ButtonScroll(sf::Vector2i(185,134),sf::Vector2i(205,149),screen,&startMinTens,1);
	ButtonScroll* upButtonStartMinOnes = new ButtonScroll(sf::Vector2i(210,134),sf::Vector2i(230,149),screen,&startMinOnes,1);
	ButtonScroll* upButtonEndHourTens = new ButtonScroll(sf::Vector2i(320,134),sf::Vector2i(340,149),screen,&endHourTens,1);
	ButtonScroll* upButtonEndHourOnes = new ButtonScroll(sf::Vector2i(345,134),sf::Vector2i(365,149),screen,&endHourOnes,1);
	ButtonScroll* upButtonEndMinTens = new ButtonScroll(sf::Vector2i(385,134),sf::Vector2i(405,149),screen,&endMinTens,1);
	ButtonScroll* upButtonEndMinOnes = new ButtonScroll(sf::Vector2i(410,134),sf::Vector2i(430,149),screen,&endMinOnes,1);
	ButtonScroll* downButtonStartHourTens = new ButtonScroll(sf::Vector2i(120,191),sf::Vector2i(140,206),screen,&startHourTens,-1);
	ButtonScroll* downButtonStartHourOnes = new ButtonScroll(sf::Vector2i(145,191),sf::Vector2i(165,206),screen,&startHourOnes,-1);
	ButtonScroll* downButtonStartMinTens = new ButtonScroll(sf::Vector2i(185,191),sf::Vector2i(205,206),screen,&startMinTens,-1);
	ButtonScroll* downButtonStartMinOnes = new ButtonScroll(sf::Vector2i(210,191),sf::Vector2i(230,206),screen,&startMinOnes,-1);
	ButtonScroll* downButtonEndHourTens = new ButtonScroll(sf::Vector2i(320,191),sf::Vector2i(340,206),screen,&endHourTens,-1);
	ButtonScroll* downButtonEndHourOnes = new ButtonScroll(sf::Vector2i(345,191),sf::Vector2i(365,206),screen,&endHourOnes,-1);
	ButtonScroll* downButtonEndMinTens = new ButtonScroll(sf::Vector2i(385,191),sf::Vector2i(405,206),screen,&endMinTens,-1);
	ButtonScroll* downButtonEndMinOnes = new ButtonScroll(sf::Vector2i(410,191),sf::Vector2i(430,206),screen,&endMinOnes,-1);

	ButtonScroll* upButtonRepeatAmtTens = new ButtonScroll(sf::Vector2i(530,169),sf::Vector2i(550,184),screen,&repeatAmtTens,1);
	ButtonScroll* upButtonRepeatAmtOnes = new ButtonScroll(sf::Vector2i(555,169),sf::Vector2i(575,184),screen,&repeatAmtOnes,1);
	ButtonScroll* downButtonRepeatAmtTens = new ButtonScroll(sf::Vector2i(530,226),sf::Vector2i(550,241),screen,&repeatAmtTens,-1);
	ButtonScroll* downButtonRepeatAmtOnes = new ButtonScroll(sf::Vector2i(555,226),sf::Vector2i(575,241),screen,&repeatAmtOnes,-1);

	ButtonScroll* upButtonRepeatFreq = new ButtonScroll(sf::Vector2i(470,112),sf::Vector2i(490,127),screen,&repeatFreqNum,1);
	ButtonScroll* downButtonRepeatFreq = new ButtonScroll(sf::Vector2i(470,133),sf::Vector2i(490,148),screen,&repeatFreqNum,-1);

	ButtonScroll* upButtonPeopleMaxTens = new ButtonScroll(sf::Vector2i(170,350),sf::Vector2i(200,372),screen,&peopleMaxTens,1);
	ButtonScroll* upButtonPeopleMaxOnes = new ButtonScroll(sf::Vector2i(210,350),sf::Vector2i(240,372),screen,&peopleMaxOnes,1);
	ButtonScroll* upButtonPeopleMinTens = new ButtonScroll(sf::Vector2i(310,350),sf::Vector2i(340,372),screen,&peopleMinTens,1);
	ButtonScroll* upButtonPeopleMinOnes = new ButtonScroll(sf::Vector2i(350,350),sf::Vector2i(380,372),screen,&peopleMinOnes,1);
	ButtonScroll* downButtonPeopleMaxTens = new ButtonScroll(sf::Vector2i(170,447),sf::Vector2i(200,469),screen,&peopleMaxTens,-1);
	ButtonScroll* downButtonPeopleMaxOnes = new ButtonScroll(sf::Vector2i(210,447),sf::Vector2i(240,469),screen,&peopleMaxOnes,-1);
	ButtonScroll* downButtonPeopleMinTens = new ButtonScroll(sf::Vector2i(310,447),sf::Vector2i(340,469),screen,&peopleMinTens,-1);
	ButtonScroll* downButtonPeopleMinOnes = new ButtonScroll(sf::Vector2i(350,447),sf::Vector2i(380,469),screen,&peopleMinOnes,-1);
	
	ButtonSave* saveButton = new ButtonSave(sf::Vector2i(500,500),sf::Vector2i(625,528),screen,currentState,&MenuShiftCreation::save);
	ButtonCancel* cancelButton = new ButtonCancel(sf::Vector2i(365,500),sf::Vector2i(465,528),screen,currentState);

	eventList = new SelectableList<Event>(screen,sf::Vector2f(650,100),sf::Vector2f(200,400),8,1,20);
}

void MenuShiftCreation::update() {
	if (startHourTens==2) {
		if (startHourOnes>3)
			startHourOnes = 3;
		startHourOnes.setMax(3);
	}
	else
		startHourOnes.setMax(9);

	if (endHourTens==2) {
		if (endHourOnes>3)
			endHourOnes=3;
		endHourOnes.setMax(3);
	}
	else
		endHourOnes.setMax(9);
}

void MenuShiftCreation::load() {
	eventList->clearList();
	for (std::vector<Event*>::const_iterator i = Event::events.begin(); i != Event::events.end(); i++)
		eventList->addItem(*i);
	eventList->updateButtons();
}

bool MenuShiftCreation::save() {
	tm date = *Calendar::selectedDate;
	
	time_t startSeconds = 60*startMinOnes + 600*startMinTens + 3600*startHourOnes + 36000*startHourTens + mktime(&date);
	tm start;
	localtime_s(&start,&startSeconds);
	time_t endSeconds = 60*endMinOnes + 600*endMinTens + 3600*endHourOnes + 36000*endHourTens + mktime(&date);
	tm end;
	localtime_s(&end,&endSeconds);
	int maxPeople = 10*peopleMaxTens + peopleMaxOnes;
	int minPeople = 10*peopleMinTens + peopleMinOnes;
	if ((startSeconds>=endSeconds)||(minPeople>maxPeople))
		return false;

	if (eventList->selectedItems.size()==0)
			eventList->selectItem(0);
	Shift* thisShift = new Shift(start,end,maxPeople,minPeople,eventList->selectedItems[0]);

	int repeatAmt = repeatAmtOnes + 10*repeatAmtTens;
	for (int i=1; i<=(repeatAmt); i++) {
		switch (repeatFreqNum) {
		case 0:
			date.tm_mday += 1;
			break;
		case 1:
			date.tm_mday += 7;
			break;
		case 2:
			date.tm_mday += 14;
			break;
		case 3:
			date.tm_mon += 1;
			break;
		}

		time_t repeatedStartSeconds = 60*startMinOnes + 600*startMinTens + 3600*startHourOnes + 36000*startHourTens + mktime(&date);
		tm repeatedStart;
		localtime_s(&repeatedStart,&repeatedStartSeconds);
		time_t repeatedEndSeconds = 60*endMinOnes + 600*endMinTens + 3600*endHourOnes + 36000*endHourTens + mktime(&date);
		tm repeatedEnd;
		localtime_s(&repeatedEnd,&repeatedEndSeconds);

		Shift* repeatedShift = new Shift(repeatedStart,repeatedEnd,maxPeople,minPeople,eventList->selectedItems[0]);
	}
	DisplayShift::selectDate(*Calendar::selectedDate);
	return true;
}

MenuShiftCreation::~MenuShiftCreation(void) {
	delete eventList;
}