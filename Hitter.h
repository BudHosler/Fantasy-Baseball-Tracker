#pragma once

#include "Player.h"

#include <iostream>

using namespace std;

class Hitter : public Player {
private:
	int games = 0, singles = 0, doubles = 0, triples = 0, homeruns = 0, runs = 0, runsBattedIn = 0, walks = 0, hitByPitch = 0, strikeOuts = 0, stolenBases = 0, caughtStealing = 0, totalBases = 0;
public:
	void setGames(int);
	void setSingles(int);
	void setDoubles(int);
	void setTriples(int);
	void setHomeRuns(int);
	void setRuns(int);
	void setRBI(int);
	void setWalks(int);
	void setHBP(int);
	void setStrikeOuts(int);
	void setStolenBases(int);
	void setCaughtStealing(int);
	void calculateTotalBases();
	void calculatePoints();

	int getGames() const;
	int getSingles() const;
	int getDoubles() const;
	int getTriples() const;
	int getHomeRuns() const;
	int getRuns() const;
	int getRBI() const;
	int getWalks() const;
	int getHBP() const;
	int getStrikeOuts() const;
	int getStolenBases() const;
	int getCaughtStealing() const;
	int getTotalBases() const;

	void displayPlayer();
};
