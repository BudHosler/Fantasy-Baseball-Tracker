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
void readBinary(int&, vector<Player*>&);
void TESTwriteBinary(vector<Player*>&);
void TESTreadBinary(vector<Player*>&);


int main() {
	int vectorSize = 0;
	vector<Player*> players;

	int choice;
	do {
		cout << "\n=== MENU ===\n";
		cout << "1. Load hitters from CSV\n";
		cout << "2. Load pitchers from CSV\n";
		cout << "3. Write to binary file\n";
		cout << "4. Read from binary file\n";
		cout << "5. Display player by index\n";
		cout << "6. TESTwriteBinary\n";
		cout << "7. TESTreadBinary\n";
		cout << "0. Exit\n";
		cout << "Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			inputHittersCSV(players);
			cout << "Hitters loaded.\n";
			break;

		case 2:
			inputPitchersCSV(players);
			cout << "Pitchers loaded.\n";
			break;

		case 3:
			writeBinary(static_cast<int>(players.size()), players);
			cout << "Data written to binary file.\n";
			break;

		case 4:
			players.clear(); // prevent duplicates
			readBinary(vectorSize, players);
			cout << "Data read from binary file.\n";
			break;

		case 5: {
			int index;
			cout << "Enter player index: ";
			cin >> index;
			if (index >= 0 && index < players.size()) {
				players[index]->displayPlayer();
			}
			else {
				cout << "Invalid index.\n";
			}
			break;
		}

		case 6:
			TESTwriteBinary(players);
			cout << "TESTwriteBinary called.\n";
			break;

		case 7:
			TESTreadBinary(players);
			cout << "TESTreadBinary called.\n";
			break;

		case 0:
			cout << "Goodbye!\n";
			break;

		default:
			cout << "Invalid option.\n";
		}
	} while (choice != 0);

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

	//output vector size
	fout.write(reinterpret_cast<const char*>(&size), sizeof(size));

	char playerType;
	int outputToBinary = 0;

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
			outputToBinary = hitter->getGames();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = hitter->getSingles();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = hitter->getDoubles();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = hitter->getTriples();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = hitter->getHomeRuns();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = hitter->getRuns();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = hitter->getRBI();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = hitter->getWalks();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = hitter->getStrikeOuts();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = hitter->getHBP();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = hitter->getStolenBases();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = hitter->getCaughtStealing();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = hitter->getTotalBases();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));
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
			outputToBinary = pitcher->getWins();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = pitcher->getLosses();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = pitcher->getGames();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = pitcher->getSaves();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = pitcher->getHolds();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = pitcher->getInningsPitched();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = pitcher->getHitsAllowed();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = pitcher->getEarnedRuns();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = pitcher->getWalksIssued();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

			outputToBinary = pitcher->getStrikeouts();
			fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));
		}
	}
}

void readBinary(int& count, vector<Player*>& player)
{
	fstream fin("binaryData.dat", ios::in | ios::binary);

	fin.read(reinterpret_cast<char*>(&count), sizeof(count));

	char playerType;
	int inputFromBinary = 0;
	string inputString;

	for (int i = 0; i < count; ++i) {
		fin.read(&playerType, sizeof(playerType));
		if (playerType == 'h') {

			Hitter* hitterInput = new Hitter;

			int len = 0;
			//read name
			fin.read(reinterpret_cast<char*>(&len), sizeof(len));
			inputString = string(len, '\0');
			fin.read(&inputString[0], len);
			hitterInput->setName(inputString);

			//read team
			fin.read(reinterpret_cast<char*>(&len), sizeof(len));
			inputString = string(len, '\0');
			fin.read(&inputString[0], len);
			hitterInput->setTeam(inputString);


			//read stats
			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			hitterInput->setGames(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			hitterInput->setSingles(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			hitterInput->setDoubles(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			hitterInput->setTriples(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			hitterInput->setHomeRuns(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			hitterInput->setRuns(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			hitterInput->setRBI(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			hitterInput->setWalks(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			hitterInput->setStrikeOuts(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			hitterInput->setHBP(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			hitterInput->setStolenBases(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			hitterInput->setCaughtStealing(inputFromBinary);

			hitterInput->calculateTotalBases();
			hitterInput->calculatePoints();

			player.push_back(hitterInput);
		}
		else {
			Pitcher* pitcherInput = new Pitcher;

			int len = 0;
			//read name
			fin.read(reinterpret_cast<char*>(&len), sizeof(len));
			inputString = string(len, '\0');
			fin.read(&inputString[0], len);
			pitcherInput->setName(inputString);

			//read team
			fin.read(reinterpret_cast<char*>(&len), sizeof(len));
			inputString = string(len, '\0');
			fin.read(&inputString[0], len);
			pitcherInput->setTeam(inputString);

			//read stats
			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			pitcherInput->setWins(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			pitcherInput->setLosses(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			pitcherInput->setGames(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			pitcherInput->setSaves(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			pitcherInput->setHolds(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			pitcherInput->setInningsPitched(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			pitcherInput->setHitsAllowed(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			pitcherInput->setEarnedRuns(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			pitcherInput->setWalksIssued(inputFromBinary);

			fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
			pitcherInput->setStrikeouts(inputFromBinary);

			pitcherInput->calculatePoints();

			player.push_back(pitcherInput);
		}
	}
}

void TESTwriteBinary(vector<Player*>& player)
{
	fstream fout("binaryData.dat", ios::out | ios::binary);


	char playerType;
	int outputToBinary = 0;

	if (Hitter* hitter = dynamic_cast<Hitter*>(player[0])) {
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
		outputToBinary = hitter->getGames();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = hitter->getSingles();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = hitter->getDoubles();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = hitter->getTriples();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = hitter->getHomeRuns();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = hitter->getRuns();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = hitter->getRBI();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = hitter->getWalks();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = hitter->getStrikeOuts();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = hitter->getHBP();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = hitter->getStolenBases();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = hitter->getCaughtStealing();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = hitter->getTotalBases();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));
	}
	else {
		Pitcher* pitcher = dynamic_cast<Pitcher*>(player[0]);

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
		outputToBinary = pitcher->getWins();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = pitcher->getLosses();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = pitcher->getGames();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = pitcher->getSaves();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = pitcher->getHolds();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = pitcher->getInningsPitched();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = pitcher->getHitsAllowed();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = pitcher->getEarnedRuns();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = pitcher->getWalksIssued();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

		outputToBinary = pitcher->getStrikeouts();
		fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));
	}
}

void TESTreadBinary(vector<Player*>& player)
{
		fstream fin("binaryData.dat", ios::in | ios::binary);

	

		char playerType;
		int inputFromBinary = 0;
		string inputString;

			fin.read(&playerType, sizeof(playerType));
			if (playerType == 'h') {

				Hitter* hitterInput = new Hitter;

				int len = 0;
				//read name
				fin.read(reinterpret_cast<char*>(&len), sizeof(len));
				inputString = string(len, '\0');
				fin.read(&inputString[0], len);
				hitterInput->setName(inputString);

				//read team
				fin.read(reinterpret_cast<char*>(&len), sizeof(len));
				inputString = string(len, '\0');
				fin.read(&inputString[0], len);
				hitterInput->setTeam(inputString);


				//read stats
				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				hitterInput->setGames(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				hitterInput->setSingles(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				hitterInput->setDoubles(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				hitterInput->setTriples(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				hitterInput->setHomeRuns(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				hitterInput->setRuns(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				hitterInput->setRBI(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				hitterInput->setWalks(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				hitterInput->setStrikeOuts(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				hitterInput->setHBP(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				hitterInput->setStolenBases(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				hitterInput->setCaughtStealing(inputFromBinary);

				hitterInput->calculateTotalBases();
				hitterInput->calculatePoints();

				player.push_back(hitterInput);
			}
			else {
				Pitcher* pitcherInput = new Pitcher;

				int len = 0;
				//read name
				fin.read(reinterpret_cast<char*>(&len), sizeof(len));
				inputString = string(len, '\0');
				fin.read(&inputString[0], len);
				pitcherInput->setName(inputString);

				//read team
				fin.read(reinterpret_cast<char*>(&len), sizeof(len));
				inputString = string(len, '\0');
				fin.read(&inputString[0], len);
				pitcherInput->setTeam(inputString);

				//read stats
				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				pitcherInput->setWins(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				pitcherInput->setLosses(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				pitcherInput->setGames(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				pitcherInput->setSaves(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				pitcherInput->setHolds(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				pitcherInput->setInningsPitched(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				pitcherInput->setHitsAllowed(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				pitcherInput->setEarnedRuns(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				pitcherInput->setWalksIssued(inputFromBinary);

				fin.read(reinterpret_cast<char*>(&inputFromBinary), sizeof(inputFromBinary));
				pitcherInput->setStrikeouts(inputFromBinary);

				pitcherInput->calculatePoints();

				player.push_back(pitcherInput);
			}
		
}



