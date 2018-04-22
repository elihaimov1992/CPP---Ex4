#include <iostream>
#include "CircularInt.hpp"
#include <string>

using namespace std;

CircularInt::CircularInt(int start, int end) {
	this->start = start;
	this->end = end;
	curHour = start;
}

CircularInt::CircularInt(int start, int end, int curHour) {
	this->start = start;
	this->end = end;
	this->curHour = curHour;
}

int CircularInt::getStart() {
	return start;
}

int CircularInt::getEnd() {
	return end;
}

int CircularInt::getCurHour() {
	return curHour;
}

void CircularInt::setCurHour(int hour) {
	curHour = hour;
}

ostream& operator<<(ostream& os, const CircularInt& circ)
{
	os << circ.curHour << endl;
	return os;
}

CircularInt& CircularInt::operator+= (int add) {
	curHour = (curHour + add) % end;
	if (curHour == 0) curHour = end;
	return *this;
}

CircularInt& CircularInt::operator++ (int) {
	curHour = (curHour + 1) % end;
	if (curHour == 0) curHour = end;
	return *this;
}

int CircularInt::operator- () {
	int ans = (end - curHour) % end;
	if (ans == 0) ans = end;
	return ans;
}

CircularInt& operator- (int baseHour, CircularInt& circ) {
	int curHour = circ.getCurHour();
	int end = circ.getEnd();
	int ans = baseHour - curHour;
	ans = ans % end;
	if (ans == 0) ans = end;
	circ.setCurHour(-ans);
	ans = -circ;
	circ.setCurHour(ans);
	return circ;
}

int CircularInt::operator+ (CircularInt& circ) {
	return (curHour + circ.getCurHour()) % end;
}

CircularInt& CircularInt::operator*= (int mult) {
	curHour = (curHour * mult) % end;
	if (curHour == 0) curHour = end;
	return *this;
}

int CircularInt::operator/ (int div) {
	if (curHour % div != 0) {
		string message = "There is no number x in {" + to_string(start) + ","
			+ to_string(end) + "} such that x*" + to_string(div) + "=" + to_string(curHour);
		throw message;
	}
	else {
		int ans = (curHour / div) % end;
		if (ans == 0) ans = end;
		return ans;
	}
}