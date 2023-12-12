//Implementation file for Date class. Creates a variable called "Date" that stores a date containg the month, day, and year

#include "Date.h"

Date::Date(int m, int d, int yyyy) {//default constructor
	if (m < 0) {
		month = 0;
	}
	else {
		month = m;
	}
	if (d < 0) {
		day = 0;
	}
	else {
		day = d;
	}
	if (yyyy < 0) {
		year = 0;
	}
	else {
		year = yyyy;
	}
}

void Date::setDate(int m, int d, int yyyy) {//function that sets the date after checking if each variable is more than 0
	if (m < 0) {
		month = 0;
	}
	else {
		month = m;
	}
	if (d < 0){
		day = 0;
	}
	else {
		day = d;
	}
	if (yyyy < 0) {
		year = 0;
	}
	else {
		year = yyyy;
	}
}

std::ostream& operator<<(std::ostream& output, const Date& d) {//operator overload of <<. outputs date in form of mm/dd/yyyy
	output << d.month << "/" << d.day << "/" << d.year;
	return output;
}
std::istream& operator>>(std::istream& input, Date& d) {//operator overload of >>. gets input for date in form of mm//dd/yyyy
	char empty;
	int day, month, year;
	input >> month >> empty >> day >> empty >> year;
	d.setDate(month, day, year);
	return input;
}