#include "Pitcher.h"

#include <iostream>
#include <iomanip>

using namespace std;

void Pitcher::setGames(int g)
{
    games = g;
}

void Pitcher::setInningsPitched(int ip)
{
    inningsPitched = ip;
}

void Pitcher::setEarnedRuns(int er)
{
    earnedRuns = er;
}

void Pitcher::setWins(int w)
{
    wins = w;
}

void Pitcher::setLosses(int l)
{
    losses = l;
}

void Pitcher::setSaves(int s)
{
    saves = s;
}

void Pitcher::setStrikeouts(int k)
{
    strikeouts = k;
}

void Pitcher::setHitsAllowed(int h)
{
    hitsAllowed = h;
}

void Pitcher::setWalksIssued(int bb)
{
    walksIssued = bb;
}

void Pitcher::setHolds(int hld)
{
    holds = hld;
}

void Pitcher::calculatePoints()
{
    points = (wins * 5) - (losses * 5) + (saves * 5) + (holds * 2) + (inningsPitched * 3) - hitsAllowed - (earnedRuns * 2) - walksIssued + strikeouts;
}

int Pitcher::getGames() const
{
    return games;
}

int Pitcher::getInningsPitched() const
{
    return inningsPitched;
}

int Pitcher::getEarnedRuns() const
{
    return earnedRuns;
}

int Pitcher::getWins() const
{
    return wins;
}

int Pitcher::getLosses() const
{
    return losses;
}

int Pitcher::getSaves() const
{
    return saves;
}

int Pitcher::getStrikeouts() const
{
    return strikeouts;
}

int Pitcher::getHitsAllowed() const
{
    return hitsAllowed;
}

int Pitcher::getWalksIssued() const
{
    return walksIssued;
}

int Pitcher::getHolds() const
{
    return holds;
}


void Pitcher::displayPlayer()
{
    cout << endl << "============================================" << endl;
    cout << "             PITCHER STATISTICS             " << endl;
    cout << "============================================" << endl;

    const int spaceWidth = 25;

    cout << left;
    cout << setw(spaceWidth) << "Player Name" << ": " << getName() << endl;
    cout << setw(spaceWidth) << "Team" << ": " << getTeam() << endl;
    cout << setw(spaceWidth) << "Fantasy Points" << ": " << getPoints() << endl;
    cout << "--------------------------------------------" << endl;
    cout << setw(spaceWidth) << "Games Played" << ": " << games << endl;
    cout << setw(spaceWidth) << "Innings Pitched" << ": " << inningsPitched << endl;
    cout << setw(spaceWidth) << "Earned Runs" << ": " << earnedRuns << endl;
    cout << setw(spaceWidth) << "Wins" << ": " << wins << endl;
    cout << setw(spaceWidth) << "Losses" << ": " << losses << endl;
    cout << setw(spaceWidth) << "Saves" << ": " << saves << endl;
    cout << setw(spaceWidth) << "Holds" << ": " << holds << endl;
    cout << setw(spaceWidth) << "Strikeouts" << ": " << strikeouts << endl;
    cout << setw(spaceWidth) << "Hits Allowed" << ": " << hitsAllowed << endl;
    cout << setw(spaceWidth) << "Walks Issued" << ": " << walksIssued << endl;
    cout << "============================================" << endl;
}
