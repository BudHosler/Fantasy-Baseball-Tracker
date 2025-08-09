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

int displayMenu();
void inputHittersCSV(vector<Player*>&); 
void inputPitchersCSV(vector<Player*>&);
void readBinary(vector<Player*>&);
int searchPlayer(vector<Player*>&, string);


int main() {
	vector<Player*> players;
	int menuChoice = 0;

	do {
		menuChoice = displayMenu();

		switch (menuChoice) {
		case 1:
			inputHittersCSV(players);
			cout << "Hitters loaded.\n";
			break;
		case 2:
			inputPitchersCSV(players);
			cout << "Pitchers loaded.\n";
			break;
		case 3: {
			ofstream fout("binaryData.dat", ios::out | ios::binary);
			if (!fout) {
				cout << "Error: cannot open binaryData.dat for writing" << endl;
				break;
			}
			int size = players.size();
			fout.write(reinterpret_cast<char*>(&size), sizeof(size));
			for (int i = 0; i < players.size(); ++i) {
				players[i]->writeBinary(fout);
			}
			break;
		}
		case 4:
			players.clear();
			readBinary(players);
			cout << "Data read from binary file.\n";
			break;
		case 5: {
			string userInput;
			cout << "Enter player name: ";
			cin.ignore(50, '\n');
			getline(cin, userInput);
			int searchIndex = searchPlayer(players, userInput);
			if (searchIndex == -1)
				cout << "Player not found.";
			else
				players[searchIndex]->displayPlayer();
			break;
		}
		case 6:
			cout << "Goodbye!\n";
			break;
		}
	} while (menuChoice != 6); 

	return 0;
}

int displayMenu()
{
	int menuChoice;
	cout << "=== MENU ===" << endl;
	cout << "1. Load hitters from CSV" << endl << "2. Load pitchers from CSV" << endl << "3. Write to binary file" << endl << "4. Read from binary file" << endl << "5. Search for player" << endl << "6. Exit Menu" << endl;
	cout << "Enter your choice: ";
	while (!(cin >> menuChoice) || cin.fail() || menuChoice > 6 || menuChoice < 1) {
		cout << "Invalid entry. Please enter a number 1-6: ";
		cin.clear();
		cin.ignore(100, '\n');
	}
	return menuChoice;
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
	ifstream fin("hitters.csv");
	if (!fin) {
		cout << "Error: could not open hitters.csv\n";
		return;
	}

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

void readBinary(vector<Player*>& player)
{
	fstream fin("binaryData.dat", ios::in | ios::binary);
	if (!fin) {
		cout << "Error: binaryData.dat not found" << endl;
		return;
	}
	int count = 0;
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

int searchPlayer(vector<Player*>& player, string userInput) {
	int size = player.size();
	for (int i = 0; i < size; i++) {
		string playerName = player[i]->getName();
		if (userInput == playerName)
			return i;
	}
	return -1;
}


