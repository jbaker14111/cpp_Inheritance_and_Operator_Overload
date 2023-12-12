// <Lab 7 - Inheritance and Operator Overloading Assignment - Josiah Baker> -- creates a team with a leader and team members based on user input
//CSIS 112-<D01>
/*REFERENCES

Great Learning Team. (2021, February 26). 
Sort function in C++ | C++ Algorithm Sort. Great Learning Blog: Free Resources What Matters to Shape Your Career! 
https://www.mygreatlearning.com/blog/sort-function-in-cpp/#sort-using-a-function-object
‌

*/
/*
This program utilizes the classes Person, Date, TeamMember, Leader, and Team to create a team based on user input that stores a team's name, purpose,
and team size. It asks the user to add a leader, team member, or list information about the team, including information about the leader and each
individual team member. The user can then choose to quit the program
*/

#include <iostream>
#include "Team.h"
#include <iomanip>
#include <string>


using namespace std;

//FUNCION PROTOTYPES

Date getDate(string prompt, string errorMessage);//function to get Date data type from user input. First displays prompt, then gets input, and has error handling
												 //where it will display the error message if there is an error in input

string getString(string prompt);//function to return a string data type. First displays prompt, then gets input

int getInt(string prompt, string errorMessage, int min);//function that gets integer data type. First displays prompt, then gets input, and has error handling
														//if input is not a number or not above mininum, error message is shown

double getDouble(string prompt, string errorMessage, double min);//function that gets double data type. First displays prompt, then gets input, and has error
																 //handling. if input is not a number or not above the minimum, error message is shown

double getDouble(string prompt, string errorMessage, double min, double max);//function that gets double data type. First displays prompt, then gets input, and
																 //has error handling. if input is not a number or not within range, error message is shown

char mainMenu();//displays main menu and gets user input of A, T, L, or Q. Includes error handling


int main() {//gets information for the team, then displays main menu, and either adds leader, adds team member, lists team information, or quits program
			//based on user input
	cout << "Lab 7 - Inheritance and Operator Overloading Assignment - Josiah Baker" << endl << endl << endl;
	string teamName = getString("Enter a name for your team: ");
	cout << endl << endl << endl << endl;
	string teamPurpose = getString("Enter the purpose of your team: ");
	cout << endl << endl << endl << endl;
	int sizeOfTeam = getInt("Enter size of team: ", "A number was not entered. Please try again.", 0);
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	Team newTeam(teamName, teamPurpose, sizeOfTeam);
	system("cls");
	cout << "Lab 7 - Inheritance and Operator Overloading Assignment - Josiah Baker" << endl << endl << endl;
	bool running = true;
	while (running) {
		char choice = mainMenu();
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (choice) {
			//A T L Q
		case 'A':
			system("cls");
			cout << "Lab 7 - Inheritance and Operator Overloading Assignment - Josiah Baker" << endl << endl << endl;
			if (newTeam.checkIfLeader() == true) {
				cout << "Team already has a leader." << endl << endl;
				system("pause");
			}
			else {
				//get leader information from user and store it
				Leader leader;
				leader.setID(getString("Enter ID: "));
				cout << endl << endl;
				leader.setFirstName(getString("Enter first name: "));
				cout << endl << endl;
				leader.setLastName(getString("Enter last name: "));
				cout << endl << endl;
				leader.setBirthdate(getDate("Enter birthdate(mm/dd/yyyy): ", "The input was incorrect. Please try again."));
				cout << endl << endl;
				leader.setDivision(getString("enter division: "));
				cout << endl << endl;
				leader.setTitle(getString("Enter title: "));
				cout << endl << endl;
				leader.setLastTeamLead(getString("Enter last team lead: "));
				cout << endl << endl;
				leader.setAnnualSalary(getDouble("Enter salary: ", "A number was not entered. Please try again.", 0));
				cout << endl << endl;
				leader.setDatePromoted(getDate("Enter date of last promotion: ", "The input was incorrect. Please try again."));
				cout << endl << endl;
				newTeam.setLeader(leader);
			}

			system("cls");
			cout << "Lab 7 - Inheritance and Operator Overloading Assignment - Josiah Baker" << endl << endl << endl;
			break;
		case 'T':
			system("cls");
			cout << "Lab 7 - Inheritance and Operator Overloading Assignment - Josiah Baker" << endl << endl << endl;
			if (newTeam.addTeamMember() == false) {
				cout << "Team is full. Cannot add more members." << endl << endl;
				system("pause");
			}
			else {
				//gets team member information from user and store it
				TeamMember newTeamMember;
				newTeamMember.setID(getString("Enter ID: "));
				cout << endl << endl;
				newTeamMember.setFirstName(getString("Enter first name: "));
				cout << endl << endl;
				newTeamMember.setLastName(getString("Enter last name: "));
				cout << endl << endl;
				newTeamMember.setBirthdate(getDate("Enter birthdate(mm/dd/yyyy): ", "The input was incorrect. Please try again."));
				cout << endl << endl;
				newTeamMember.setDepartment(getString("Enter Department: "));
				cout << endl << endl;
				newTeamMember.setPosition(getString("Enter Position(Programmer, Writer, Artist, DBA, etc.): "));
				cout << endl << endl;
				newTeamMember.setSkillLevel(getString("Enter Skill Level(Entry Level, Skilled, Expert, etc.): "));
				cout << endl << endl;
				newTeamMember.setLastPerformanceRating(getDouble("Enter last performance rating(1.0-5.0): ", "The input was not a number. Please try again.", 1.0, 5.0));
				cout << endl << endl;
				newTeamMember.setDateHired(getDate("Enter date hired: ", "The input was incorrect. Please try again."));
				newTeam.addTeamMember(newTeamMember);
			}
			system("cls");
			cout << "Lab 7 - Inheritance and Operator Overloading Assignment - Josiah Baker" << endl << endl << endl;
			break;
		case 'L':
			system("cls");
			cout << "Lab 7 - Inheritance and Operator Overloading Assignment - Josiah Baker" << endl << endl << endl;
			cout << newTeam << endl << endl;
			system("pause");
			system("cls");
			cout << "Lab 7 - Inheritance and Operator Overloading Assignment - Josiah Baker" << endl << endl << endl;
			break;

		case 'Q':
			cout << endl << endl << "PRGRAM STOPPING..." << endl << endl;
			system("pause");
			running = false;
			break;
		}
	}
	return 0;

}

	Date getDate(string prompt, string errorMessage) {//function to get Date data type from user input. First displays prompt, then gets input, and has error
													  //handling where it will display the error message if there is an error in input
		Date date;
		cout << prompt;
		cin >> date;
		if (cin.fail()) {
			cout << endl << endl << errorMessage << endl << endl;
			system("pause");
			cout << endl << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return getDate(prompt, errorMessage);
		}

		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return date;
		}
	}
string getString(string prompt) {//function to return a string data type. First displays prompt, then gets input
	cout << prompt;
	string newString;
	getline(cin, newString);
	return newString;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}
int getInt(string prompt, string errorMessage, int min) {//function that gets integer data type. First displays prompt, then gets input, and has error handling
														//if input is not a number or not above mininum, error message is shown
	cout << prompt;
	int newInt;
	cin >> newInt;
	if (cin.fail()) {
		cout << endl << endl << errorMessage << endl << endl;
		system("pause");
		cout << endl << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return getInt(prompt, errorMessage, min);
	}
	else if (newInt < min) {
		cout << endl << endl << "input must be higher than " << min << ". Please try again." << endl << endl;
		system("pause");
		cout << endl << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return getInt(prompt, errorMessage, min);
	}
	else return newInt;
}
double getDouble(string prompt, string errorMessage, double min) {//function that gets double data type. First displays prompt, then gets input, and has error
																 //handling. if input is not a number or not above the minimum, error message is shown
	cout << prompt;
	double newDouble;
	
	cin >> newDouble;
	if (cin.fail()) {
		cout << endl << endl << errorMessage << endl << endl;
		system("pause");
		cout << endl << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return getDouble(prompt, errorMessage, min);
	}
	else if (newDouble < min) {
		cout << endl << endl << "input was less than" << min << ". Please try again." << endl << endl;
		system("pause");
		cout << endl << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return getDouble(prompt, errorMessage, min);
	}
	else return newDouble;
}
double getDouble(string prompt, string errorMessage, double min, double max) {//function that gets double data type. First displays prompt, then gets input, and
																 //has error handling. if input is not a number or not within range, error message is shown
	cout << prompt;
	double newDouble;

	cin >> newDouble;
	if (cin.fail()) {
		cout << endl << endl << errorMessage << endl << endl;
		system("pause");
		cout << endl << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return getDouble(prompt, errorMessage, min, max);
	}
	else if (newDouble < min || newDouble > max) {
		cout << endl << endl << "input was less than " << min << ", ore more than " << max << ".Please try again." << endl << endl;
		system("pause");
		cout << endl << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return getDouble(prompt, errorMessage, min,max);
	}
	else return newDouble;
}
char mainMenu() {//displays main menu and gets user input of A, T, L, or Q. Includes error handling
	cout << setw(5) << " " << "Main Menu" << endl << endl;
	cout << "A -- Add Leader" << endl << "T -- Add Team Member" << endl << "L -- List Team Information" << endl << "Q -- Quit" << endl << endl << "Selection: ";
	char choice;
	cin >> choice;
	choice = toupper(choice);
	if (choice == 'A' || choice == 'T' || choice == 'L' || choice == 'Q') {
		return choice;
	}
	else {
		cout << endl << endl << "Input was not one of the choices. Please try again." << endl << endl;
		system("pause");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("cls");
		cout << "Lab 7 - Inheritance and Operator Overloading Assignment - Josiah Baker" << endl << endl << endl;
		return mainMenu();
	}
}