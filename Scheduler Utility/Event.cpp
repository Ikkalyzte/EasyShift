#include "Event.h"

std::vector<Event*> Event::events;

Event::Event(void) {

}

Event::Event(std::string name, std::string location, std::string description):
	name(name),location(location),description(description) {
		events.push_back(this);
}

Event::~Event(void)
{
}
