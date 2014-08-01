#include "Person.h"

std::vector<Person*> Person::persons;

Person::Person(void) {

}

Person::Person(std::string name,int maxShiftsPerDay):name(name),maxShiftsPerDay(maxShiftsPerDay) {
	persons.push_back(this);
}

//May change this to have the shifts in chronological order
bool Person::setUnavailableShift(Shift* shiftToAdd) {
	for(std::vector<Shift*>::const_iterator i=unavailableShifts.begin(); i!=unavailableShifts.end(); ++i) {
		if (*i == shiftToAdd) {
			return false;
		}
    }
	unavailableShifts.push_back(shiftToAdd);
	return true;
}

bool Person::delUnavailableShift(Shift* shiftToDelete) {
	for(std::vector<Shift*>::const_iterator i=unavailableShifts.begin(); i!=unavailableShifts.end(); ++i) {
		if (*i == shiftToDelete) {
			unavailableShifts.erase(i);
			return true;
		}
    }
	return false;
}

void Person::clearUnavailableShifts() {
	unavailableShifts.clear();
}

Person::~Person(void) {
}
