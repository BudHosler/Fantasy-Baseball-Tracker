#pragma once

#include "Player.h"

#include <iostream>

using namespace std;

class Pitcher : public Player {
private:
	int inningsPitched, earnedRuns, wins, losses, saves, strikeouts, hitsAllowed, walksIssued, holds;

public:
    void setInningsPitched(int);
    void setEarnedRuns(int);
    void setWins(int);
    void setLosses(int);
    void setSaves(int);
    void setStrikeouts(int);
    void setHitsAllowed(int);
    void setWalksIssued(int);
    void setHolds(int);

    int getInningsPitched() const;
    int getEarnedRuns() const;
    int getWins() const;
    int getLosses() const;
    int getSaves() const;
    int getStrikeouts() const;
    int getHitsAllowed() const;
    int getWalksIssued() const;
    int getHolds() const;

};