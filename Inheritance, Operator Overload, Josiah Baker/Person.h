//Header file for Person class. Stores general information for a person such as full name, worker ID, and birthdate

#ifndef PersonH
#define PersonH
#include "Date.h"
#include <string>

class Person {
	
public:

	Person(std::string id = "", std::string first = "", std::string last = "", Date date = {0,0,0});
	//Default constructor
	//Postcondition: ID = id; firstName = first; lastName = last; birthdate = date;

	~Person(){}
	//Default destructor

	void setID(std::string id);
	//function that sets the ID of person
	//Postcondition: ID = id;

	std::string getID() const;
	//function that returns ID of person

	void setFirstName(std::string first);
	//function that sets first name of person
	//Postcondition: firstName = first;

	std::string getFirstName() const;
	//function that returns first name of person

	void setLastName(std::string last);
	//function that sets last name of person
	//Postcondition: lastName = last;

	std::string getLastName() const;
	//function that returns last name of person

	void setBirthdate(Date date);
	//function that sets birthdate of person
	//Postcondition: birthdate = date;

	Date getBirthdate() const;
	//function that returns birthdate of person


private:

	std::string ID;//variable of type string that stores ID of person
	std::string firstName;//variable of type string that stores first name of person
	std::string lastName;//variable of type string that stores last name of person
	Date birthdate;//variable of type Date that stores birthdate of person

};


#endif