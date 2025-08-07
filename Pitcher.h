#pragma once

#include "Player.h"

#include <iostream>

using namespace std;

class Pitcher : public Player {
private:
    int games = 0, inningsPitched = 0, earnedRuns = 0, wins = 0, losses = 0, saves = 0, strikeouts = 0, hitsAllowed = 0, walksIssued = 0, holds = 0;

public:
    void setGames(int);
    void setInningsPitched(int);
    void setEarnedRuns(int);
    void setWins(int);
    void setLosses(int);
    void setSaves(int);
    void setStrikeouts(int);
    void setHitsAllowed(int);
    void setWalksIssued(int);
    void setHolds(int);
    void calculatePoints();

    int getGames() const;
    int getInningsPitched() const;
    int getEarnedRuns() const;
    int getWins() const;
    int getLosses() const;
    int getSaves() const;
    int getStrikeouts() const;
    int getHitsAllowed() const;
    int getWalksIssued() const;
    int getHolds() const;
  

    void displayPlayer();

};