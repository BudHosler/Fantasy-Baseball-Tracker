//Gene Hosler
//8-5-2025
//CIS1202

#include "Player.h"
#include "Hitter.h"
#include "Pitcher.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void inputHittersCSV(vector<Player*>&);

void inputPitchersCSV(vector<Player*>&);

int main() {

	vector <Player*> players;

	inputHittersCSV(players);

	inputPitchersCSV(players);




	system("pause");
	return 0;
}

void inputHittersCSV(vector<Player*>& player)
{
	ifstream fin;

	fin.open("hitters.csv");

	string stringInput;
	int statInput;

	//skip file header
	getline(fin, stringInput);

	while (getline(fin, stringInput, ',')) {

		Hitter* hitterEntry = new Hitter;

		hitterEntry->setName(stringInput);

		getline(fin, stringInput, ',');
		hitterEntry->setTeam(stringInput);

		fin >> statInput;
		hitterEntry->setGames(statInput);

		fin >> statInput;
		hitterEntry->setSingles(statInput);

		fin >> statInput;
		hitterEntry->setDoubles(statInput);

		fin >> statInput;
		hitterEntry->setTriples(statInput);

		fin >> statInput;
		hitterEntry->setHomeRuns(statInput);

		fin >> statInput;
		hitterEntry->setRuns(statInput);

		fin >> statInput;
		hitterEntry->setRBI(statInput);

		fin >> statInput;
		hitterEntry->setWalks(statInput);

		fin >> statInput;
		hitterEntry->setStrikeOuts(statInput);

		fin >> statInput;
		hitterEntry->setHBP(statInput);

		fin >> statInput;
		hitterEntry->setStolenBases(statInput);

		fin >> statInput;
		hitterEntry->setCaughtStealing(statInput);

		player.push_back(hitterEntry);
	}
	fin.close();
}

void inputPitchersCSV(vector<Player*>& player) {
	ifstream fin;

	fin.open("pitchers.csv");

	string stringInput;
	int statInput;

	//skip file header
	getline(fin, stringInput);

	while (getline(fin, stringInput, ',')) {
		Pitcher* pitcherEntry = new Pitcher;

		pitcherEntry->setName(stringInput);

		getline(fin, stringInput, ',');
		pitcherEntry->setTeam(stringInput);

		fin >> statInput;
		pitcherEntry->setWins(statInput);

		fin >> statInput;
		pitcherEntry->setLosses(statInput);

		fin >> statInput;
		pitcherEntry->setGames(statInput);

		fin >> statInput;
		pitcherEntry->setSaves(statInput);

		fin >> statInput;
		pitcherEntry->setHolds(statInput);

		fin >> statInput;
		pitcherEntry->setInningsPitched(statInput);

		fin >> statInput;
		pitcherEntry->setHitsAllowed(statInput);

		fin >> statInput;
		pitcherEntry->setEarnedRuns(statInput);

		fin >> statInput;
		pitcherEntry->setWalksIssued(statInput);

		fin >> statInput;
		pitcherEntry->setStrikeouts(statInput);

		player.push_back(pitcherEntry);
	}
	fin.close();
}
