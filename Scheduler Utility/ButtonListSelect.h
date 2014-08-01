#pragma once
#ifndef BUTTONLISTSELECT_INCLUDED
#define BUTTONLISTSELECT_INCLUDED

#include "Button.h"
#include "Shift.h"
#include "SelectableList.h"

template <class I>
class ButtonListSelect:
	public Button
{
public:
	template <class J>
	friend class SelectableList;

	ButtonListSelect(void);
	ButtonListSelect(sf::Vector2i,sf::Vector2i,ButtonHelper*,SelectableList<I>*,int);
	ButtonListSelect(sf::Vector2i,sf::Vector2i,ButtonHelper*,SelectableList<I>*,int,bool);
	void click();
	void setToSelect(int);
	int itemToSelect;
	SelectableList<I>* list;
	~ButtonListSelect(void);
};

#endif