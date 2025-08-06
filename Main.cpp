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


void inputHitterCSV();

int main() {

	

	vector <Player*> players;

	





		








	system("pause");
	return 0;
}

void inputHitterCSV()
{
	ifstream fin;

	fin.open("hitters.csv");

	string stringInput;
	int statInput;

	//skip file header
	getline(fin, stringInput);

	while(getline(fin, stringInput, ',')) {
		Hitter hitterEntry;

		hitterEntry.setName(stringInput);

		getline(fin, stringInput, ',');
		hitterEntry.setTeam(stringInput);

		fin >> statInput;
		hitterEntry.setGames(statInput);

		fin >> statInput;
		hitterEntry.setSingles(statInput);

		fin >> statInput;
		hitterEntry.setDoubles(statInput);

		fin >> statInput;
		hitterEntry.setTriples(statInput);

		fin >> statInput;
		hitterEntry.setHomeRuns(statInput);

		fin >> statInput;
		hitterEntry.setRuns(statInput);

		fin >> statInput;
		hitterEntry.setRBI(statInput);

		fin >> statInput;
		hitterEntry.setWalks(statInput);

		fin >> statInput;
		hitterEntry.setStrikeOuts(statInput);

		fin >> statInput;
		hitterEntry.setHBP(statInput);

		fin >> statInput;
		hitterEntry.setStolenBases(statInput);

		fin >> statInput;
		hitterEntry.setCaughtStealing(statInput);

		players.push_back(&hitterEntry);
}
