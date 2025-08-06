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

void inputPitcherCSV(vector<Player*>& player) {
	ifstream fin;

	fin.open("pitchers.csv");

	string stringInput;
	int statInput;

	//skip file header
	getline(fin, stringInput);

	while (getline(fin, stringInput, ',')) {
		Pitcher* pitcherEntry
	}

}
