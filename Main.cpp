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

int main() {

	ifstream fin;

	fin.open("hitters.csv");

	vector <Player*> players;
	string stringInput;
	int statInput;

	//skip file header
	getline(fin, stringInput);
	
	if(getline(fin, stringInput, ',')) {
		Hitter hitterEntry;
		hitterEntry.setName(stringInput);
		getline(fin, stringInput, ',');


		

	}






	system("pause");
	return 0;
}