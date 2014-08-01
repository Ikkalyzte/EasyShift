#include "ButtonListSelect.h"

template class ButtonListSelect<Shift>;
template class ButtonListSelect<Person>;
template class ButtonListSelect<Event>;

template <class I>
ButtonListSelect<I>::ButtonListSelect(void) {

}

template <class I>
ButtonListSelect<I>::ButtonListSelect(sf::Vector2i tl, sf::Vector2i br, ButtonHelper* activeScreen, SelectableList<I>* list, int itemToSelect)
	:Button(tl,br,activeScreen),list(list),itemToSelect(itemToSelect) {
}

template <class I>
ButtonListSelect<I>::ButtonListSelect(sf::Vector2i tl, sf::Vector2i br, ButtonHelper* activeScreen, SelectableList<I>* list, int itemToSelect, bool active)
	:Button(tl,br,activeScreen,active),list(list),itemToSelect(itemToSelect) {
}

template <class I>
void ButtonListSelect<I>::click() {
	if (itemToSelect>-1)
		list->selectItem(itemToSelect);
}

template <class I>
void ButtonListSelect<I>::setToSelect(int toSelect) {
	itemToSelect = toSelect;
}

template <class I>
ButtonListSelect<I>::~ButtonListSelect(void) {

}
