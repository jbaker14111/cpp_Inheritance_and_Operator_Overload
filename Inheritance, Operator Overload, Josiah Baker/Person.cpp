//Implementation file for Person class. Stores general information for a person such as full name, worker ID, and birthdate

#include "Person.h"

Person::Person(std::string id, std::string first, std::string last, Date date) {//default constructor
	ID = id;
	firstName = first;
	lastName = last;
	birthdate = date;
}

void Person::setID(std::string id) {//sets ID of person
	ID = id;
}
std::string Person::getID() const {//returns ID of person
	return ID;
}
void Person::setFirstName(std::string first) {//sets first name of person
	firstName = first;
}
std::string Person::getFirstName() const {//returns first name of person
	return firstName;
}
void Person::setLastName(std::string last) {//sets lsat name of person
	lastName = last;
}
std::string Person::getLastName() const {//returns last name of person
	return lastName;
}
void Person::setBirthdate(Date date) {//sets birthdate of person
	birthdate = date;
}
Date Person::getBirthdate() const {//returns birthdate of person
	return birthdate;
}