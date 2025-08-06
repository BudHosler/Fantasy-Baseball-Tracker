#include "Hitter.h"

#include <iostream>

using namespace std;

void Hitter::setGames(int g)
{
    games = g;
}

void Hitter::setSingles(int s)
{
    singles = s;
}

void Hitter::setDoubles(int d)
{
    doubles = d;
}

void Hitter::setTriples(int t)
{
    triples = t;
}

void Hitter::setHomeRuns(int h)
{
    homeruns = h;
}

void Hitter::setRuns(int r)
{
    runs = r;
}

void Hitter::setRBI(int rbi)
{
    runsBattedIn = rbi;
}

void Hitter::setWalks(int w)
{
    walks = w;
}

void Hitter::setHBP(int hbp)
{
    hitByPitch = hbp;
}

void Hitter::setStrikeOuts(int so)
{
    strikeOuts = so;
}

void Hitter::setStolenBases(int sb)
{
    stolenBases = sb;
}

void Hitter::setCaughtStealing(int cs)
{
    caughtStealing = cs;
}

void Hitter::calculatePoints()
{
    points = totalBases + walks + runs + runsBattedIn - strikeOuts + (stolenBases * 2) - caughtStealing + hitByPitch;
}

void Hitter::calculateTotalBases()
{
    totalBases = singles + (doubles*2) + (triples*3) + (homeruns*4);
}

int Hitter::getGames() const {
    return games;
}

int Hitter::getSingles() const {
    return singles;
}

int Hitter::getDoubles() const {
    return doubles;
}

int Hitter::getTriples() const {
    return triples;
}

int Hitter::getHomeRuns() const {
    return homeruns;
}

int Hitter::getRuns() const {
    return runs;
}

int Hitter::getRBI() const {
    return runsBattedIn;
}

int Hitter::getWalks() const {
    return walks;
}

int Hitter::getHBP() const {
    return hitByPitch;
}

int Hitter::getStrikeOuts() const {
    return strikeOuts;
}

int Hitter::getStolenBases() const {
    return stolenBases;
}

int Hitter::getCaughtStealing() const {
    return caughtStealing;
}

int Hitter::getTotalBases() const {
    return totalBases;
}


