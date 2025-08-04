#pragma once

#include <iostream>
#include <string>

using namespace std;

class Player {
private:
	string name, team;
	int points;

public:
	void setName(string);
	void setTeam(string);
	virtual void calculatePoints() = 0;

	string getName() const;
	string getTeam() const;
	int getPoints() const;
};


