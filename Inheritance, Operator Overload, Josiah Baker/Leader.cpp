//Implementation file of class Leader. Derived from class Person. stores information about leader such as division, date promoted, title, lsat team lead,
//and annual salary. overloaded operator << to output information about leader

#include "Leader.h"

std::ostream& operator<<(std::ostream& output, const Leader& leader) {//operator overload that outputs information about leader
	std::string spacing = "       ";
	output << "Team leader ID:" << std::setw(25) << " " << leader.getID() << std::endl << "Team Leader:" << std::setw(28) << " " << leader.getFirstName() + " " + leader.getLastName() + " - " + leader.title + " - " + leader.division <<
		std::endl << "Birth Date:" << std::setw(29) << " " << leader.getBirthdate() << std::endl << "Date Promoted:" << std::setw(26) << " " << leader.promoted <<
		std::endl <<
		"Last Team Lead:" << std::setw(25) << " " << leader.lastTeamLead << std::endl << "Annual Salary:" << std::setw(27) << "$" << std::fixed << std::setprecision(2) << leader.annualSalary;
	return output;
}

Leader::Leader(std::string id, std::string first, std::string last, Date birthdate, std::string div,
	Date prom, std::string titl, std::string lastTeam, double annualSal) : Person(id, first, last, birthdate) {//default constructor
	division = div;
	promoted = prom;
	title = titl;
	lastTeamLead = lastTeam;
	annualSalary = annualSal;
}
void Leader::setDivision(std::string div) {//sets division of leader
	division = div;
}
std::string Leader::getDivision() const {//returns division of leader
	return division;
}
void Leader::setDatePromoted(Date date) {//sets date promoted of leader
	promoted = date;
}
Date Leader::getDatePromoted() const {//returns date promoted of leader
	return promoted;
}
void Leader::setTitle(std::string titl) {//sets title of leader
	title = titl;
}
std::string Leader::getTitle() const {//returns title of leader
	return title;
}
void Leader::setLastTeamLead(std::string lead) {//sets last team lead of leader
	lastTeamLead = lead;
}
std::string Leader::getLastTeamLead() const {//returns last team lead of leader
	return lastTeamLead;
}
void Leader::setAnnualSalary(double sal) {//sets annual salary of leader
	annualSalary = sal;
}
double Leader::getAnnualSalary() const {//returns annual salary of leader
	return annualSalary;
}