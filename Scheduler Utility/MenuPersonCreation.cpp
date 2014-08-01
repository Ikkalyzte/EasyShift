#include "MenuPersonCreation.h"

TextBox* MenuPersonCreation::nameTextBox = new TextBox;
LoopInt MenuPersonCreation::maxShiftsPerDay(9,0,0);
SelectableList<Shift>* MenuPersonCreation::shiftList;

MenuPersonCreation::MenuPersonCreation(void) {

}

void MenuPersonCreation::draw(sf::RenderWindow* window, sf::Font* font) {
	sf::RectangleShape bg(sf::Vector2f(800,500));
	bg.setFillColor(sf::Color(192,255,62));
	bg.setPosition(100,50);
	bg.setOutlineThickness(5);
	bg.setOutlineColor(sf::Color(128,128,30));
	window->draw(bg);

	sf::RectangleShape textBoxBg(sf::Vector2f(150,24));
	textBoxBg.setFillColor(sf::Color(255,255,200));
	textBoxBg.setOutlineColor(sf::Color(100,100,40));
	textBoxBg.setOutlineThickness(5);
	textBoxBg.setPosition(250,110);
	window->draw(textBoxBg);
	sf::RectangleShape saveButtonBox(sf::Vector2f(145,28));
	saveButtonBox.setPosition(530,500);
	saveButtonBox.setFillColor(sf::Color(180,180,0));
	window->draw(saveButtonBox);
	sf::RectangleShape cancelBox(sf::Vector2f(100,28));
	cancelBox.setPosition(390,500);
	cancelBox.setFillColor(sf::Color(180,180,0));
	window->draw(cancelBox);
	sf::RectangleShape numberBox(sf::Vector2f(30,50));
	numberBox.setPosition(640,340);
	numberBox.setFillColor(sf::Color(180,180,0));
	window->draw(numberBox);

	sf::ConvexShape triangle(3);
	triangle.setPoint(0,sf::Vector2f(0,22));
	triangle.setPoint(1,sf::Vector2f(30,22));
	triangle.setPoint(2,sf::Vector2f(15,0));
	triangle.setFillColor(sf::Color(180,180,0));
	triangle.setPosition(640,305);
	window->draw(triangle);
	triangle.setRotation(180);
	triangle.move(30,122);
	window->draw(triangle);

	sf::Text label("Name:",*font,30);
	label.setColor(sf::Color());
	label.setPosition(150,100);
	window->draw(label);
	label.setString("Shifts Unavailable");
	label.move(0,60);
	window->draw(label);
	sf::Text maxMinText("Max shifts per day",*font,20);
	maxMinText.setColor(sf::Color());
	maxMinText.setPosition(550,220);
	window->draw(maxMinText);
	maxMinText.setString("(set 0 for unlimited):");
	maxMinText.move(0,30);
	window->draw(maxMinText);
	sf::Text saveButtonText("Save Person",*font,20);
	saveButtonText.setColor(sf::Color());
	saveButtonText.setPosition(532,500);
	window->draw(saveButtonText);
	sf::Text cancelButtonText("Cancel",*font,20);
	cancelButtonText.setColor(sf::Color());
	cancelButtonText.setPosition(392,500);
	window->draw(cancelButtonText);
	sf::Text varText(maxShiftsPerDay,*font,52);
	varText.setColor(sf::Color());
	varText.setPosition(640,331);
	window->draw(varText);

	nameTextBox->draw(window,font);

	shiftList->draw(window,font);
}

void MenuPersonCreation::initButtons(ButtonHelper* screen, PrgmState* currentState, TextBox** activeTextBox) {
	ButtonSave* saveButton = new ButtonSave(sf::Vector2i(530,500),sf::Vector2i(660,528),screen,currentState,&MenuPersonCreation::save);
	ButtonCancel* cancelButton = new ButtonCancel(sf::Vector2i(390,500),sf::Vector2i(490,528),screen,currentState);
	nameTextBox = new TextBox(sf::Vector2i(250,110),sf::Vector2i(400,134),screen,activeTextBox);
	ButtonScroll* upMaxShiftsPerDay = new ButtonScroll(sf::Vector2i(640,305),sf::Vector2i(670,327),screen,&maxShiftsPerDay,1);
	ButtonScroll* downMaxShiftsPerDay = new ButtonScroll(sf::Vector2i(640,405),sf::Vector2i(670,427),screen,&maxShiftsPerDay,-1);
	shiftList = new SelectableList<Shift>(screen,sf::Vector2f(150,220),sf::Vector2f(350,250),5,int(HUGE_VAL),20);
}

bool MenuPersonCreation::save() {
	if (nameTextBox->inputText.length() < 1)
		return false;
	for (std::vector<Person*>::const_iterator i = Person::persons.begin(); i != Person::persons.end(); i++) {
		if (nameTextBox->inputText == (*i)->name)
			return false;
	}
	Person* person = new Person(nameTextBox->inputText,maxShiftsPerDay);
	for (std::vector<Shift*>::const_iterator i = shiftList->selectedItems.begin(); i != shiftList->selectedItems.end(); ++i)
		person->setUnavailableShift(*i);
	return true;
}

void MenuPersonCreation::load() {
	shiftList->clearList();
	for (std::vector<Shift*>::const_iterator i = Shift::shifts.begin(); i != Shift::shifts.end(); i++)
		shiftList->addItem(*i);
	shiftList->updateButtons();
}

MenuPersonCreation::~MenuPersonCreation(void) {

}
