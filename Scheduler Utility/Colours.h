#pragma once
#ifndef COLOURS_INCLUDED
#define COLOURS_INCLUDED
#include <SFML/Graphics.hpp>

//This is going to be the colour class. ADRIAN: THIS IS YOUR JOB

/*
Blue colour scheme:
-Pale (calendar bg): #7080D7
-Light (shift display): #4A60D7
-Vivid (buttons): #162EAE
-Dark (highlight): #071871
*/

class Colours
{
public:
	//All possible theme types.
	enum theme {
		black,
		grey,
		white,
		red,
		orange,
		yellow,
		green,
		lightGreen,
		darkGreen,
		blue,
		lightBlue,
		darkBlue,
		violet
	};
	//Set a new theme. Arguments: new theme colour
	static void setCurrentTheme(theme);
private:
	//The current theme (duh)
	static theme currentTheme;
};

#endif