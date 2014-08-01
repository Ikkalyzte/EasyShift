#include "Shift.h"
#include "Person.h"

std::vector<Shift*> Shift::shifts(0);

Shift::Shift() {

}

Shift::Shift(tm start, tm end, int maxPeople, int minPeople, Event* owner):start(start),end(end),maxPeople(maxPeople),minPeople(minPeople),ownerEvent(owner) {
	for (std::vector<Shift*>::const_iterator i = Shift::shifts.begin(); i != Shift::shifts.end(); ++i) {
		if (this->precedes(*i)) {
			Shift::shifts.insert(i,this);
			return;
		}
	}
	Shift::shifts.push_back(this);
}

void Shift::delShift(Shift* shiftToDelete) {
	for(std::vector<Shift*>::const_iterator i=shifts.begin(); i!=shifts.end(); ++i) {
		if (*i == shiftToDelete) {
			shifts.erase(i);
			break;
		}
    }
}

bool Shift::precedes(Shift* shift) {
	if (mktime(&(this->start)) < mktime(&(shift->start)))
		return true;
	else if (mktime(&(this->start)) == mktime(&(shift->start)))
		return (mktime(&(this->end)) < mktime(&(shift->end))) ? true : false;
	else
		return false;
}

Shift::~Shift(void) {
	Shift::delShift(this);
}
