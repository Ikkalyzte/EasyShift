#pragma once
#ifndef EVENT_INCLUDED
#define EVENT_INCLUDED
#include <string>
#include <vector>

class Event
{
public:
	Event(void);
	//Args: name, location, description
	Event(std::string,std::string,std::string);
	~Event(void);
	std::string name;
	std::string location;
	std::string description;
	//Array of all Events
	static std::vector<Event*> events;
};

#endif