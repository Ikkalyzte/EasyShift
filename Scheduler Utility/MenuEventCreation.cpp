#include "MenuEventCreation.h"
#include <iostream>

TextBox* MenuEventCreation::nameTextBox = new TextBox();
TextBox* MenuEventCreation::locationTextBox = new TextBox();
TextBox* MenuEventCreation::descriptionTextBox = new TextBox();

MenuEventCreation::MenuEventCreation(void) {

}

void MenuEventCreation::draw(sf::RenderWindow* window, sf::Font* font) {
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
	textBoxBg.move(75,60);
	window->draw(textBoxBg);
	textBoxBg.setPosition(150,275);
	textBoxBg.setSize(sf::Vector2f(500,200));
	window->draw(textBoxBg);
	sf::RectangleShape saveButtonBox(sf::Vector2f(125,28));
	saveButtonBox.setPosition(530,500);
	saveButtonBox.setFillColor(sf::Color(180,180,0));
	window->draw(saveButtonBox);
	sf::RectangleShape cancelBox(sf::Vector2f(100,28));
	cancelBox.setPosition(390,500);
	cancelBox.setFillColor(sf::Color(180,180,0));
	window->draw(cancelBox);

	sf::Text label("Name:",*font,30);
	label.setColor(sf::Color());
	label.setPosition(150,100);
	window->draw(label);
	label.setString("Location:");
	label.move(0,60);
	window->draw(label);
	label.setString("Description:");
	label.move(0,60);
	window->draw(label);
	sf::Text saveButtonText("Save Event",*font,20);
	saveButtonText.setColor(sf::Color());
	saveButtonText.setPosition(532,500);
	window->draw(saveButtonText);
	sf::Text cancelButtonText("Cancel",*font,20);
	cancelButtonText.setColor(sf::Color());
	cancelButtonText.setPosition(392,500);
	window->draw(cancelButtonText);

	nameTextBox->draw(window,font);
	locationTextBox->draw(window,font);
	descriptionTextBox->draw(window,font);
}

void MenuEventCreation::initButtons(ButtonHelper* screen,PrgmState* currentState,TextBox** activeTextBox) {
	nameTextBox = new TextBox(sf::Vector2i(250,110),sf::Vector2i(400,134),screen,activeTextBox);
	locationTextBox = new TextBox(sf::Vector2i(325,170),sf::Vector2i(475,194),screen,activeTextBox);
	descriptionTextBox = new TextBox(sf::Vector2i(150,275),sf::Vector2i(650,475),screen,activeTextBox);
	
	ButtonSave* saveButton = new ButtonSave(sf::Vector2i(530,500),sf::Vector2i(625,528),screen,currentState,&MenuEventCreation::save);
	ButtonCancel* cancelButton = new ButtonCancel(sf::Vector2i(390,500),sf::Vector2i(490,528),screen,currentState);
}

bool MenuEventCreation::save() {
	if (nameTextBox->inputText.length()==0)
		return false;
	else {
		for (std::vector<Event*>::const_iterator i = Event::events.begin(); i != Event::events.end(); ++i) {
			if (nameTextBox->inputText == (*i)->name)
				return false;
		}
	}
	Event* thisEvent = new Event(nameTextBox->inputText,locationTextBox->inputText,descriptionTextBox->inputText);
	nameTextBox->clear();
	locationTextBox->clear();
	descriptionTextBox->clear();
	return true;
}

MenuEventCreation::~MenuEventCreation(void) {

}
