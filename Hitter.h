#pragma once

#include "Player.h"

#include <iostream>

using namespace std;

class Hitter : public Player {
private:
	int games, singles, doubles, triples, homeruns, runs, runsBattedIn, walks, hitByPitch, strikeOuts, stolenBases, caughtStealing, totalBases;
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
	void calculateTotalBases(int);
	void calculatePoints(int, )

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
};
