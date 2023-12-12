//Implementation file for TeamMember class. Stores information for a team member. Is derived from Person class. Contains added information
//such as, department, date hired, position, skill level, and performance rating. Allows outputting in form of << 

#include "TeamMember.h"




std::ostream& operator<<(std::ostream& output, const TeamMember& member) {//operator overload that outputs information of team member
	std::string spacing = "       ";
	output << "Team Member ID:" << std::setw(25) << " " << member.getID() << std::endl << "Team Member Name:" << std::setw(23) << " " << member.getFirstName() + " " + member.getLastName() <<
		std::endl << "Birth Date:"  << std::setw(29) << " " << member.getBirthdate() << std::endl << "Date Hired:" << std::setw(29) << " " << member.dateHired <<
		std::endl << "Department:"  << std::setw(29) << " " << member.Department << std::endl << "Position:" << std::setw(31) << " " << member.position << std::endl <<
		"Skill Level:"   << std::setw(28) << " " << member.skillLevel << std::endl << "Last Performance Rating:" << std::setw(16) << " " << member.lastPerformanceRating;
	return output;
}

TeamMember::TeamMember(std::string id, std::string first, std::string last, Date birthdate, std::string dep, Date hired, std::string pos, std::string skill, double performance) : Person(id, first, last, birthdate)
//default constructor
{
	Department = dep;
	dateHired = hired;
	position = pos;
	skillLevel = skill;
	lastPerformanceRating = performance;
}
void TeamMember::setDepartment(std::string dep) {//sets department of team member
	Department = dep;
}
std::string TeamMember::getDepartment() const {//returns department of team member
	return Department;
}
void TeamMember::setDateHired(Date date) {//sets date hired of team member
	dateHired = date;
}
Date TeamMember::getDateHired() const {//returns date hired of team member
	return dateHired;
}
void TeamMember::setPosition(std::string pos) {//sets position of team member
	position = pos;
}
std::string TeamMember::getPosition() const {//returns position of team member
	return position;
}
void TeamMember::setSkillLevel(std::string skill) {//sets skill level of team member
	skillLevel = skill;
}
std::string TeamMember::getSkillLevel() const {//returns skill level of team member
	return skillLevel;
}
void TeamMember::setLastPerformanceRating(double rating) {//sets last performance rating of team member
	lastPerformanceRating = rating;
}
double TeamMember::getLastPerformanceRating() const {//returns last performance rating of team member
	return lastPerformanceRating;
}