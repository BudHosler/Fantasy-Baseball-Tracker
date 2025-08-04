#include "Player.h"

#include <iostream>
#include <string>

using namespace std;

void Player::setName(string inputName)
{
	name = inputName;
}

void Player::setTeam(string inputTeam)
{
	team = inputTeam;
}


string Player::getName()
{
	return name;
}

string Player::getTeam()
{
	return team;
}

string Player::getPoints()
{
	return points;
}


