//Header file of class Team. Stores information about team, and includes operator overload of << to output information about the team, as well
//as the leader of the team and all of its members

#ifndef TeamH
#define TeamH
#include "Leader.h"
#include "TeamMember.h"
#include <vector>
#include <algorithm>

class Team {

	friend std::ostream& operator<<(std::ostream& out, const Team& team);
	//operator overload of <<
	//outputs team information, leader information, and information of all of the members

public:

	Team(std::string n = "", std::string p = "", int size = 0);
	//default constructor
	//Postcondition: name = n; purpose = p; teamSize = size;

	~Team(){}
	//default destructor

	void setTeamName(std::string n);
	//function that sets name of team
	//Postcondition: name = n;

	std::string getTeamName() const;
	//function that returns name of team

	void setPurpose(std::string p);
	//function that sets purpose of team
	//Postcondition: purpose = p;

	std::string getPurpose() const;
	//function that returns purpose of team

	bool checkIfLeader() const;
	//function that checks if team has leader

	bool addTeamMember();
	//function that checks if a team member can be added

	void addTeamMember(TeamMember newGuy);
	//function that adds a team member ater checking if there is room
	//Postcondition: teamMember.pushback(newGuy);

	void setLeader(Leader n);
	//function that sets leader of team
	//Postcondition: teamLeader = n;

	void sortTeamMembers();
	//function that sorts the team members based on ID
	


private:
	bool hasLeader = false;//variable of type bool that stores whether team has leader or not
	std::string name;//variable of type string that stores name of team
	std::string purpose;//variable of type string that stores purpose of team
	Leader teamLeader;//variable of type Leader that stores the leader of team
	std::vector<TeamMember> teamMembers;//vector variable of type TeamMember that stores list of team members of team
	int teamSize;//variable of type int that stores max size of team

};

#endif