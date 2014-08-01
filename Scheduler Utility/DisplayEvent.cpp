#include "DisplayEvent.h"
tm* DisplayEvent::dateShown = new tm();
SelectableList<Event>* DisplayEvent::eventList = new SelectableList<Event>();

DisplayEvent::DisplayEvent(void) {

}

void DisplayEvent::selectDate(tm dateToSelect) {
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
				if (!((*i)->start.tm_mon==dateShown->tm_mon && (*i)->start.tm_mday==dateShown->tm_mday && (*i)->start.tm_year==dateShown->tm_year)) {
					i == Shift::shifts.end();
					break;
				}
				else {
					shiftList->addItem(*i);
					break;
				}
		}
	}
	shiftList->updateButtons();
}

DisplayEvent::~DisplayEvent(void) {

}
