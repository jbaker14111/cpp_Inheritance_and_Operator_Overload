//Implementation file of class Team. Stores information about team, and includes operator overload of << to output information about the team, as well
//as the leader of the team and all of its members

#include "Team.h"

std::ostream& operator<<(std::ostream& out, const Team& team) {//operator overload of << that outputs information of team, leader, and its members
	std::cout << "Team Name: " << team.name << std::endl << std::endl << "Team Purpose: " << team.purpose << std::endl << std::endl << "Team's Max Size: " <<
		team.teamSize << std::endl << std::endl;
	if (team.hasLeader == true) {
		std::cout << "Leader:" << std::endl << team.teamLeader << std::endl << std::endl;
	}
	else {
		std::cout << "Team does not have a leader yet." << std::endl << std::endl;
	}
	if (team.teamMembers.size() > 0) {
		for (int x = 0; x < team.teamMembers.size(); x++) {
			std::cout << team.teamMembers[x] << std::endl << std::endl;
		}
	}
	else {
		std::cout << "No team members added yet." << std::endl << std::endl;
	}
	return out;
}

Team::Team(std::string n, std::string p, int size) {//default constructor
	name = n;
	purpose = p;
	teamSize = size;
}
void Team::setTeamName(std::string n) {//sets name of team
	name = n;
}
std::string Team::getTeamName() const {//returns name of team
	return name;
}
void Team::setPurpose(std::string p){//sets purpose of team
	purpose = p;
}
std::string Team::getPurpose() const {//returns purpose of team
	return purpose;
}
bool Team::checkIfLeader() const {//returns bool of whether there is a leader for team or not
	return hasLeader;
}
bool Team::addTeamMember() {//returns bool of whethere there is room to add a member or not
	return (teamMembers.size() < teamSize);
}
void Team::addTeamMember(TeamMember newGuy) {//adds a team member to team
	if (addTeamMember()) {
		teamMembers.push_back(newGuy);
		if (teamSize > 1) {
			sortTeamMembers();
		}
	}
}
void Team::setLeader(Leader n) {//sets leader of team
	if (hasLeader == false) {
		hasLeader = true;
		teamLeader = n;
	}
}
struct {//struct that includes function of how to sort teamMembers
	bool operator () (TeamMember a, TeamMember b) const {
		return a.getID() < b.getID();
	}
} customLess;
void Team::sortTeamMembers() {//sorts team members according to ID
	sort(teamMembers.begin(), teamMembers.end(),customLess);
}