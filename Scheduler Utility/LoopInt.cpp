#include "LoopInt.h"


LoopInt::LoopInt(void) {

}

LoopInt::LoopInt(int max):max(max),min(0),val(0) {
	
}

LoopInt::LoopInt(int max, int min):max(max),min(min),val(min) {

}

LoopInt::LoopInt(int max, int min, int start):max(max),min(min),val(start) {

}

void LoopInt::scroll(int amt) {
	if (amt == 0)
		return;
	else if (amt == 1)
		++(*this);
	else if (amt == -1)
		--(*this);
	else if (amt > 0) {
		for (int i=0;i<amt;++i)
			++(*this);
	}
	else if (amt < 0){
		for (int i=0;i>amt;--i)
			--(*this);
	}
}

bool LoopInt::setMax(int newMax) {
	if (newMax <= min)
		return false;
	else
		max = newMax;
	return true;
}

bool LoopInt::setMin(int newMin) {
	if (newMin >= max)
		return false;
	else
		min = newMin;
	return true;
}

int LoopInt::getMax() {
	return max;
}

int LoopInt::getMin() {
	return min;
}

LoopInt::operator int() {
	return val;
}

LoopInt::operator std::string() {
	return std::to_string(val);
}
LoopInt::operator sf::String() {
	return std::to_string(val);
}

LoopInt& LoopInt::operator++() {
	if (val==max)
		val=min;
	else
		val++;
	return *this;
}

LoopInt& LoopInt::operator--() {
	if (val==min)
		val=max;
	else
		val--;
	return *this;
}

LoopInt& LoopInt::operator=(int newVal) {
	if (!(newVal >= min && newVal <= max))
		return *this;
	else
		val = newVal;
	return *this;
}

LoopInt::~LoopInt(void) {

}
