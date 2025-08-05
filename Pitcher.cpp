#include "Pitcher.h"

#include <iostream>

using namespace std;

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
