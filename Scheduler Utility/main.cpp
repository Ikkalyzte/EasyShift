#include "ButtonHelper.h"
#include "ButtonMonthChange.h"
#include "Calendar.h"
#include "SidePanel.h"
#include "MenuShiftCreation.h"
#include "MenuEventCreation.h"
#include "MenuPersonCreation.h"
#include "MenuCreation.h"
#include "MenuError.h"
#include "TextBox.h"
#include <iostream>
#define FONT_ERR 1

int main()
{
	//Create Window
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1000, 600), "Scheduler Utility");
    
	
	//Current state
	PrgmState currentState = background;
	
	//Currently typeable textbox
	TextBox* activeTextBox = NULL;

	//Font to use. This is easily changed, but I think this one looks decent.
	sf::Font* font = new sf::Font();
	if (!font->loadFromFile("DroidSansMono.ttf")) {
		std::exit(FONT_ERR);
	}

	//Set current time & date
	time(&Calendar::todayInSec);
	localtime_s(Calendar::today,&Calendar::todayInSec);
	Calendar::today->tm_hour = 0;
	Calendar::today->tm_min = 0;
	Calendar::today->tm_sec = 0;
	*Calendar::firstDay = *Calendar::today;
	Calendar::firstDay->tm_mday = 1;
	mktime(Calendar::firstDay);
	Calendar::selectDate(*Calendar::today);
	SidePanel::selectDate(*Calendar::today);

	//Different possible screens/menus/whateveryouwanttocallthem
	ButtonHelper* mainScreen = new ButtonHelper();
	ButtonHelper* creationScreen = new ButtonHelper();
	ButtonHelper* shiftCreationScreen = new ButtonHelper();
	ButtonHelper* eventCreationScreen = new ButtonHelper();
	ButtonHelper* personCreationScreen = new ButtonHelper();
	ButtonHelper* errorScreen = new ButtonHelper();
	//The currently active screen
	ButtonHelper* activeScreen = mainScreen;

	//Initialise all buttons
	Calendar::initButtons(mainScreen);
	SidePanel::initButtons(mainScreen,&currentState);
	MenuCreation::initButtons(creationScreen,&currentState);
	MenuShiftCreation::initButtons(shiftCreationScreen,&currentState);
	MenuEventCreation::initButtons(eventCreationScreen,&currentState,&activeTextBox);
	MenuPersonCreation::initButtons(personCreationScreen,&currentState,&activeTextBox);
	MenuError::initButtons(errorScreen,&currentState);

	//Blank event
	Event* blankEvent = new Event("(none)","","Not affiliated with an event.");

	/*
	The event loop. This is where the program actually takes place. 
	It repeats every time an event occurs - say, a mouse click.
	*/
	//Keeps track of whether a redraw-necessary event occurred
	bool eventOccurred = true;

    while (window->isOpen()) {
		//Pull events, deal with them
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
				//On window closed. Don't think we have to do anything special here
				case sf::Event::Closed:
					window->close();
					break;
				//On mouse pressed down. This just highlights the button
				case sf::Event::MouseButtonPressed:
					{
					sf::Vector2i coord(event.mouseButton.x,event.mouseButton.y);
					eventOccurred = activeScreen->select(coord);
					break;
					}
				//On click
				case sf::Event::MouseButtonReleased:
					{
					sf::Vector2i coord(event.mouseButton.x,event.mouseButton.y);
					activeScreen->click(coord);
					eventOccurred = true;
					break;
					}
				//On scroll
				case sf::Event::MouseWheelMoved:
					{
					sf::Vector2i coord(event.mouseWheel.x,event.mouseWheel.y);
					activeScreen->scroll(coord,-event.mouseWheel.delta);
					eventOccurred = true;
					break;
					}
				case sf::Event::KeyReleased:
					{
					switch (event.key.code) {
						case sf::Keyboard::Escape:
							--currentState;
							eventOccurred = true;
							break;
					}
					break;
					}
				case sf::Event::TextEntered:
					{
						if (activeTextBox != NULL) {
							activeTextBox->type(event.text);
							eventOccurred = true;
						}
						break;
					}
				default:
					break;
				/*
				More cases for different kinds of events (especially window resize)
				*/
			}
        }
		
		if (eventOccurred) {
			/* 
			Redraw window section.
			*/
			//Clear it
			window->clear();
			//Draw the main (background) screen
			Calendar::draw(window, font);
			SidePanel::draw(window, font);
			DisplayShift::shiftList->draw(window,font);
			//Draw any overlaid menus, change active screen appropriately
			sf::RectangleShape darkness(sf::Vector2f(1000,600));
			darkness.setFillColor(sf::Color(0,0,0,128));
			switch (currentState) {
			case background:
				activeScreen = mainScreen;
				break;
			case creation:
				window->draw(darkness);
				activeScreen = creationScreen;
				MenuCreation::draw(window,font);
				break;
			case shiftCreation:
				window->draw(darkness);
				activeScreen = shiftCreationScreen;
				MenuShiftCreation::update();
				MenuShiftCreation::draw(window,font);
				break;
			case shiftCreationError:
				activeScreen = errorScreen;
				MenuShiftCreation::draw(window,font);
				window->draw(darkness);
				MenuError::draw(window,font);
				break;
			case eventCreation:
				window->draw(darkness);
				activeScreen = eventCreationScreen;
				MenuEventCreation::draw(window,font);
				break;
			case eventCreationError:
				activeScreen = errorScreen;
				MenuEventCreation::draw(window,font);
				window->draw(darkness);
				MenuError::draw(window,font);
				break;
			case personCreation:
				window->draw(darkness);
				activeScreen = personCreationScreen;
				MenuPersonCreation::draw(window,font);
				break;
			case personCreationError:
				activeScreen = errorScreen;
				MenuPersonCreation::draw(window,font);
				window->draw(darkness);
				MenuError::draw(window,font);
				break;
			}
			//Highlight the currently selected button
			activeScreen->highlight(window);
			//Display what has been drawn
			window->display();
		}
		eventOccurred = false;
    }

	//After program execution, delete possible random variables floating around :P
	delete window, font, mainScreen, creationScreen, eventCreationScreen, personCreationScreen, shiftCreationScreen;
	delete DisplayShift::dateShown, DisplayShift::shiftList;
	delete Calendar::today, Calendar::firstDay, Calendar::selectedDate;

	//Success!
	return 0;
}