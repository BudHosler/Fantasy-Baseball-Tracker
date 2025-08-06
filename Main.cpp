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
void writeBinaryHitter(const int, vector<Player*>&);


int main() {

	int vectorSize;

	vector <Player*> players;

	inputHittersCSV(players);
	inputPitchersCSV(players);
	

	vectorSize = players.size();


	players[4]->displayPlayer(); 





	system("pause");
	return 0;
}

void inputHittersCSV(vector<Player*>& player)
{
	ifstream fin;

	fin.open("hitters.csv");

	string stringInput;

	//skip file header
	getline(fin, stringInput);

	while (getline(fin, stringInput, ',')) {

		Hitter* hitterEntry = new Hitter;

		hitterEntry->setName(stringInput);

		getline(fin, stringInput, ',');
		hitterEntry->setTeam(stringInput);

		getline(fin, stringInput, ',');
		hitterEntry->setGames(stoi(stringInput));

		getline(fin, stringInput, ',');
		hitterEntry->setSingles(stoi(stringInput));

		getline(fin, stringInput, ',');
		hitterEntry->setDoubles(stoi(stringInput));

		getline(fin, stringInput, ',');
		hitterEntry->setTriples(stoi(stringInput));

		getline(fin, stringInput, ',');
		hitterEntry->setHomeRuns(stoi(stringInput));

		getline(fin, stringInput, ',');
		hitterEntry->setRuns(stoi(stringInput));

		getline(fin, stringInput, ',');
		hitterEntry->setRBI(stoi(stringInput));

		getline(fin, stringInput, ',');
		hitterEntry->setWalks(stoi(stringInput));

		getline(fin, stringInput, ',');
		hitterEntry->setStrikeOuts(stoi(stringInput));

		getline(fin, stringInput, ',');
		hitterEntry->setHBP(stoi(stringInput));

		getline(fin, stringInput, ',');
		hitterEntry->setStolenBases(stoi(stringInput));

		getline(fin, stringInput);
		hitterEntry->setCaughtStealing(stoi(stringInput));

		hitterEntry->calculateTotalBases();
		hitterEntry->calculatePoints();

		player.push_back(hitterEntry);
	}
	fin.close();
}


void inputPitchersCSV(vector<Player*>& player) {
	ifstream fin;

	fin.open("pitchers.csv");

	string stringInput;

	//skip file header
	getline(fin, stringInput);

	while (getline(fin, stringInput, ',')) {
		Pitcher* pitcherEntry = new Pitcher;

		pitcherEntry->setName(stringInput);

		getline(fin, stringInput, ',');
		pitcherEntry->setTeam(stringInput);

		getline(fin, stringInput, ',');
		pitcherEntry->setWins(stoi(stringInput));

		getline(fin, stringInput, ',');
		pitcherEntry->setLosses(stoi(stringInput));

		getline(fin, stringInput, ',');
		pitcherEntry->setGames(stoi(stringInput));

		getline(fin, stringInput, ',');
		pitcherEntry->setSaves(stoi(stringInput));

		getline(fin, stringInput, ',');
		pitcherEntry->setHolds(stoi(stringInput));

		getline(fin, stringInput, ',');
		pitcherEntry->setInningsPitched(stoi(stringInput));

		getline(fin, stringInput, ',');
		pitcherEntry->setHitsAllowed(stoi(stringInput));

		getline(fin, stringInput, ',');
		pitcherEntry->setEarnedRuns(stoi(stringInput));

		getline(fin, stringInput, ',');
		pitcherEntry->setWalksIssued(stoi(stringInput));

		getline(fin, stringInput);
		pitcherEntry->setStrikeouts(stoi(stringInput));

		pitcherEntry->calculatePoints();



		player.push_back(pitcherEntry);
	}
	fin.close();
}

void writeBinaryHitter(const int size, vector<Player*>& player)
{
	fstream fout("binaryData.dat", ios::out | ios::binary);

	for (int i = 0; i < size; i++) {
		if (Hitter* hitter = dynamic_cast<Hitter*>(player[i])) {
			char playerType = 'h';
			fout.write(&playerType, sizeof(playerType));

			//note for future: writing the file directly, or does it make more sense to save into temp variable?  Different for strings or ints?
			//write name
			int len = hitter->getName().length();
			fout.write(reinterpret_cast<char*>(&len), sizeof(len));
			fout.write(hitter->getName().c_str(), len);

			//write team
			len = hitter->getTeam().length();
			fout.write(reinterpret_cast<char*>(&len), sizeof(len));
			fout.write(hitter->getTeam().c_str(), len);

			//write games- this one is solid3

			int inputToBinary = hitter->getGames();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));


		}

	
	}
}



