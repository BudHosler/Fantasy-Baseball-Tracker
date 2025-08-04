#pragma once

#include <iostream>
#include <string>

using namespace std;

class Player {
private:
	string name;
	int team, points;

public:
	void setName(string);
	void setTeam(string);
	void setPoints(int);

	string getName();
	string getTeam();
	string getPoints();
};


