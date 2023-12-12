//Header file for Date class. Creates a variable called "Date" that stores a date containg the month, day, and year

#ifndef DateH
#define DateH
#include <iostream>
#include <cstdlib>
#include <cctype>
class Date {
	friend std::ostream& operator<<(std::ostream& output, const Date& d);
	//operator overload of <<
	//outputs date in form of mm//dd//yyyy to ostream variable output

	friend std::istream& operator>>(std::istream& input, Date& d);
	//operator overload of >>
	//gets date information from istream variable input in form of mm/dd//yyyy

public:
	
	Date(int m = 0, int d = 0, int yyyy = 0);
	//default constructor
	//Postcondition: month = m; day = d; year = yyyy;

	void setDate(int m, int d, int yyyy);
	//function that sets date 
	//Postcondition: month = m; day = d; year = yyyy;

private:
	int day;//variable of type int that stores day 
	int month;//variable of type int that stores month
	int year;//variable of type int that stores year
	
};

#endif