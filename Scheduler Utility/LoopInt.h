#pragma once
#ifndef LOOPINT_INCLUDED
#define LOOPINT_INCLUDED

#include "IScrollable.h"
#include <string>
#include <SFML\Graphics.hpp>

class LoopInt:
	public IScrollable
{
public:
	LoopInt(void);
	//Max val
	LoopInt(int);
	//Max val, min val
	LoopInt(int,int);
	//Max val, min val, starting val
	LoopInt(int,int,int);
	~LoopInt(void);
	void scroll(int);
	bool setMax(int);
	bool setMin(int);
	int getMax();
	int getMin();
	operator int();
	operator std::string();
	operator sf::String();
	LoopInt& operator++();
	LoopInt& operator--();
	LoopInt& operator=(int);
private:
	int val;
	int max;
	int min;
};

#endif