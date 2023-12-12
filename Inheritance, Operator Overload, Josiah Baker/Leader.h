//Header file of class Leader. Derived from class Person. stores information about leader such as division, date promoted, title, lsat team lead,
//and annual salary. overloaded operator << to output information about leader

#ifndef LeaderH
#define LeaderH
#include "Person.h"
#include <iomanip>

class Leader : public Person {

	friend std::ostream& operator<<(std::ostream& output, const Leader& leader);
	//operator overload of << 
	//Outputs all information about leader to output

public:

	Leader(std::string id = "", std::string first = "", std::string last = "", Date birthdate = { 0,0,0 }, std::string div = "",
		Date prom = { 0,0,0 }, std::string titl = "", std::string lastTeam = "", double annualSal = 0);
	//default constructor
	//Postcondition: Person(id, first, last, birthdate); division = div; promoted = prom; title = titl; lastTeamLead = lastTeam; annualSalary = annualSal;

	~Leader() {}
	//default destructor

	void setDivision(std::string div);
	//function that sets division of leader
	//Postcondition: division = div;

	std::string getDivision() const;
	//function that returns division of leader

	void setDatePromoted(Date date);
	//function that sets date promoted of leader
	//Postcondition: promoted = date;

	Date getDatePromoted() const;
	//function that returns date promoted of leader

	void setTitle(std::string titl);
	//function that sets title of leader
	//Postcondition: title = titl;

	std::string getTitle() const;
	//function that returns title of leader

	void setLastTeamLead(std::string lead);
	//function that sets last team lead of leader
	//Postcondition: lastTeamLead = lead;

	std::string getLastTeamLead() const;
	//function that returns last team lead of leader

	void setAnnualSalary(double sal);
	//function that sets annual salary of leader
	//Postcondition: annualSalary = sal;

	double getAnnualSalary() const;
	//function that returns annual salary of leader

private:

	std::string division;//variable of type string that stores division of leader
	Date promoted;//variable of type Date that stores date promoted of leader
	std::string title;//variable of type string that stores title of leader
	std::string lastTeamLead;//variable of type string that stores last team lead of leader
	double annualSalary;//variable of type double that stores annual salary of leader
};

#endif