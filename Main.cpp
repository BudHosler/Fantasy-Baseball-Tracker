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
void writeBinary(const int, vector<Player*>&);
void readBinary


int main() {

	int vectorSize;

	vector <Player*> players;

	inputHittersCSV(players);
	inputPitchersCSV(players);
	

	vectorSize = players.size();
	writeBinary(vectorSize, players);


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

void writeBinary(const int size, vector<Player*>& player)
{
	fstream fout("binaryData.dat", ios::out | ios::binary);

	char playerType;
	int inputToBinary = 0;

	for (int i = 0; i < size; i++) {
		if (Hitter* hitter = dynamic_cast<Hitter*>(player[i])) {
			//log class type
			playerType = 'h';
			fout.write(&playerType, sizeof(playerType));

			//write name
			int len = hitter->getName().length();
			fout.write(reinterpret_cast<char*>(&len), sizeof(len));
			fout.write(hitter->getName().c_str(), len);

			//write team
			len = hitter->getTeam().length();
			fout.write(reinterpret_cast<char*>(&len), sizeof(len));
			fout.write(hitter->getTeam().c_str(), len);

			//write stats
			inputToBinary = hitter->getGames();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = hitter->getSingles();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = hitter->getDoubles();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = hitter->getTriples();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = hitter->getHomeRuns();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = hitter->getRuns();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = hitter->getRBI();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = hitter->getWalks();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = hitter->getStrikeOuts();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = hitter->getHBP();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = hitter->getStolenBases();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = hitter->getCaughtStealing();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = hitter->getTotalBases();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = hitter->getPoints();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));
		}
		else {
			Pitcher* pitcher = dynamic_cast<Pitcher*>(player[i]);

			//log class type
			playerType = 'p';
			fout.write(&playerType, sizeof(playerType));

			//write name
			int len = pitcher->getName().length();
			fout.write(reinterpret_cast<char*>(&len), sizeof(len));
			fout.write(pitcher->getName().c_str(), len);

			//write team
			len = pitcher->getTeam().length();
			fout.write(reinterpret_cast<char*>(&len), sizeof(len));
			fout.write(pitcher->getTeam().c_str(), len);

			//write stats
			inputToBinary = pitcher->getWins();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = pitcher->getLosses();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = pitcher->getGames();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = pitcher->getSaves();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = pitcher->getHolds();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = pitcher->getInningsPitched();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = pitcher->getHitsAllowed();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = pitcher->getEarnedRuns();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = pitcher->getWalksIssued();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = pitcher->getStrikeouts();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));

			inputToBinary = pitcher->getPoints();
			fout.write(reinterpret_cast<char*>(&inputToBinary), sizeof(inputToBinary));


		}




	
	}
}



