//Header file for TeamMember class. Stores information for a team member. Is derived from Person class. Contains added information
//such as, department, date hired, position, skill level, and performance rating. Allows outputting in form of << 

#ifndef TeamMemberH
#define TeamMemberH
#include "Person.h"
#include <iostream>
#include <iomanip>

class TeamMember : public Person {
	
	friend std::ostream& operator<<(std::ostream& output, const TeamMember& member);
	//operator overload of <<
	//outputs all information about team member

public:

	TeamMember(std::string id = "", std::string first = "", std::string last = "", Date birthdate = { 0,0,0 },
		std::string dep = "", Date hired = { 0,0,0 }, std::string pos = "", std::string skill = "", double performance = 0);
	//default constructor
	//Postcondition: Person(id, first, last, birthdate); department = dep; dateHired = hired; position = pos; skillLevel = skill; lastPerformanceRating = performance;

	~TeamMember(){}
	//default destructor

	void setDepartment(std::string dep);
	//function that sets department of team member
	//Postcondition: department = dep;

	std::string getDepartment() const;
	//function that returns department of team member

	void setDateHired(Date date);
	//function that sets date hired of team member
	//Postcondition: dateHired = date;

	Date getDateHired() const;
	//function that returns date hired of team member

	void setPosition(std::string pos);
	//function that sets position of team member
	//Postcondition: position = pos;

	std::string getPosition() const;
	//function that returns position of team member

	void setSkillLevel(std::string skill);
	//function that sets skill level of team member
	//Postcondition: skillLevel = skill;

	std::string getSkillLevel() const;
	//function that returns skill level of team member

	void setLastPerformanceRating(double rating);
	//function that sets last performance rating of team member
	//Postcondition: lastPerformanceRating = rating;

	double getLastPerformanceRating() const;
	//function that returns last performance rating of team member


private:

	std::string Department;//variable of type string that stores department of team member
	Date dateHired;//variable of type Date that stores date hired of team member
	std::string position;//variable of type string that stores position of team member
	std::string skillLevel;//variable of type string that stores skill level of team member
	double lastPerformanceRating;//variable of type double that stores last performance rating of team member

};

#endif