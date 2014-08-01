#include "SelectableList.h"
#include "ButtonListSelect.h"
#include "Scroll.h"
#include <iostream>

template class SelectableList<Shift>;
template class SelectableList<Person>;
template class SelectableList<Event>;

template <class I>
SelectableList<I>::SelectableList(void) {

}

template <class I>
SelectableList<I>::SelectableList(ButtonHelper* screen, sf::Vector2f position, sf::Vector2f size, int amtToShow, int maxSelected, int fontSize):position(position),size(size),amtDisplayed(amtToShow),maxSelected(maxSelected),fontSize(fontSize),listOffset(0) {
	for (int i=0; i<amtDisplayed; i++) {
		ButtonListSelect<I>* listButton = new ButtonListSelect<I>(sf::Vector2i(position.x,position.y+(i*(fontSize+5))),sf::Vector2i(position.x+size.x,position.y+fontSize+5+(i*(fontSize+5))),screen,this,i,false);
		listButtons.push_back(listButton);
	}
	Scroll* scrollArea = new Scroll(sf::Vector2i(position),sf::Vector2i(position.x+size.x,position.y+size.y),screen,(IScrollable*)this);
}

template <class I>
SelectableList<I>::SelectableList(ButtonHelper* screen, sf::Vector2f position, sf::Vector2f size, int amtToShow, int maxSelected, int fontSize, void (*update)(std::vector<I*>)):position(position),size(size),amtDisplayed(amtToShow),maxSelected(maxSelected),fontSize(fontSize),listOffset(0),update(update) {
	for (int i=0; i<amtDisplayed; i++) {
		ButtonListSelect<I>* listButton = new ButtonListSelect<I>(sf::Vector2i(position.x,position.y+(i*(fontSize+5))),sf::Vector2i(position.x+size.x,position.y+fontSize+5+(i*(fontSize+5))),screen,this,i,false);
		listButtons.push_back(listButton);
	}
	Scroll* scrollArea = new Scroll(sf::Vector2i(position),sf::Vector2i(position.x+size.x,position.y+size.y),screen,(IScrollable*)this);
}

template <class I>
void SelectableList<I>::draw(sf::RenderWindow* window, sf::Font* font) {
	sf::RectangleShape listBox(size);
	listBox.setPosition(position);
	listBox.setFillColor(sf::Color(0,0,0,0));
	listBox.setOutlineThickness(3);
	listBox.setOutlineColor(sf::Color(128,128,64));
	window->draw(listBox);
	
	if (items.size()>0) {
		for (int i=0; i<amtDisplayed; i++) {
			if ((i+listOffset)>(items.size()-1))
				break;
			else {
				sf::Text itemText(createString(items.at(i+listOffset)),*font,fontSize);
				itemText.setPosition(position.x+6,(position.y-2+(i*(fontSize+5))));
				itemText.setColor(sf::Color());
				window->draw(itemText);

				if (selectedItems.size()>0) {
					for (std::vector<I*>::const_iterator l = selectedItems.begin(); l != selectedItems.end(); ++l) {
						if ((*l)==items.at(i+listOffset)) {
							sf::RectangleShape highlight(sf::Vector2f(size.x,fontSize+5));
							highlight.setPosition(position.x,position.y+(i*(fontSize+5)));
							highlight.setFillColor(sf::Color(0,0,255,64));
							window->draw(highlight);
							break;
						}
					}
				}
			}
		}
	}
}

template <class I>
std::string SelectableList<I>::createString(Shift* shift) {
	std::string shiftString = "";
	if (shift->ownerEvent != Event::events[0])
		shiftString += shift->ownerEvent->name + ": ";
	if (shift->start.tm_hour<10)
		shiftString += "0";
	shiftString += std::to_string(shift->start.tm_hour);
	shiftString += ":";
	if (shift->start.tm_min<10)
		shiftString += "0";
	shiftString += std::to_string(shift->start.tm_min);
	shiftString += " - ";
	if (shift->end.tm_hour<10)
		shiftString += "0";
	shiftString += std::to_string(shift->end.tm_hour);
	shiftString += ":";
	if (shift->end.tm_min<10)
		shiftString += "0";
	shiftString += std::to_string(shift->end.tm_min);
	return shiftString;
}

template <class I>
std::string SelectableList<I>::createString(Event* theEvent) {
	return theEvent->name;
}

template <class I>
std::string SelectableList<I>::createString(Person* person) {
	return person->name;
}

template <class I>
void SelectableList<I>::updateButtons() {
	for (int i=0; (i<amtDisplayed)&&(i<(items.size()-listOffset)); i++) {
		if (items.at(i+listOffset)!=NULL) {
			listButtons[i]->setToSelect(i+listOffset);
			listButtons[i]->setActive(true);
		}
		else
			listButtons[i]->setActive(false);
	}
}

template <class I>
void SelectableList<I>::selectItem(int item) {
	for (std::vector<I*>::const_iterator i = selectedItems.begin(); i!=selectedItems.end(); ++i) {
		if ((*i)==items.at(item)) {
			selectedItems.erase(i);
			return;
		}
	}
	if (selectedItems.size()<maxSelected)
		selectedItems.push_back(items.at(item));
	else {
		selectedItems.erase(selectedItems.begin());
		selectedItems.push_back(items.at(item));
	}
	if (update)
		update(selectedItems);
}

template <class I>
void SelectableList<I>::scroll(int amt) {
	std::cout<<"Called scroll";
	if ((amt>0 && (items.size()-listOffset)>amtDisplayed) || (amt<0 && listOffset>0)) {
		listOffset += amt;
		updateButtons();
		std::cout<<"Scrolled "<<amt;
	}
}

template <class I>
void SelectableList<I>::addItem(I* item) {
	items.push_back(item);
}

template <class I>
void SelectableList<I>::clearList() {
	items.clear();
	selectedItems.clear();
}

template <class I>
SelectableList<I>::~SelectableList(void) {
	delete scrollArea;
}
