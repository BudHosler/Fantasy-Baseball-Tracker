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


string Player::getName() const
{
	return name;
}

string Player::getTeam() const
{
	return team;
}

int Player::getPoints() const
{
	return points;
}


