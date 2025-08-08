#include "Hitter.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

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

void Hitter::displayPlayer()
{
    cout << endl << "============================================" << endl;
    cout << "             HITTER STATISTICS              " << endl;
    cout << "============================================" << endl;

    const int spaceWidth = 25;

    cout << left;
    cout << setw(spaceWidth) << "Player Name" << ": " << getName() << endl;
    cout << setw(spaceWidth) << "Team" << ": " << getTeam() << endl;
    cout << setw(spaceWidth) << "Fantasy Points" << ": " << getPoints() << endl;
    cout << "--------------------------------------------" << endl;
    cout << setw(spaceWidth) << "Games Played" << ": " << games << endl;
    cout << setw(spaceWidth) << "Singles" << ": " << singles << endl;
    cout << setw(spaceWidth) << "Doubles" << ": " << doubles << endl;
    cout << setw(spaceWidth) << "Triples" << ": " << triples << endl;
    cout << setw(spaceWidth) << "Home Runs" << ": " << homeruns << endl;
    cout << setw(spaceWidth) << "Total Bases" << ": " << totalBases << endl;
    cout << setw(spaceWidth) << "Runs Scored" << ": " << runs << endl;
    cout << setw(spaceWidth) << "Runs Batted In (RBI)" << ": " << runsBattedIn << endl;
    cout << setw(spaceWidth) << "Walks" << ": " << walks << endl;
    cout << setw(spaceWidth) << "Hit By Pitch (HBP)" << ": " << hitByPitch << endl;
    cout << setw(spaceWidth) << "Strike Outs" << ": " << strikeOuts << endl;
    cout << setw(spaceWidth) << "Stolen Bases" << ": " << stolenBases << endl;
    cout << setw(spaceWidth) << "Caught Stealing" << ": " << caughtStealing << endl;
    cout << "============================================" << endl;
}

void Hitter::writeBinary(ostream& fout)
{
    char playerType = 'h';
    fout.write(&playerType, sizeof(playerType));

    //write name
    int len = getName().length();
    fout.write(reinterpret_cast<char*>(&len), sizeof(len));
    fout.write(getName().c_str(), len);

    //write team
    len = getTeam().length();
    fout.write(reinterpret_cast<char*>(&len), sizeof(len));
    fout.write(getTeam().c_str(), len);

    //write stats
    int outputToBinary = getGames();
    fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

    outputToBinary = getSingles();
    fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

    outputToBinary = getDoubles();
    fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

    outputToBinary = getTriples();
    fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

    outputToBinary = getHomeRuns();
    fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

    outputToBinary = getRuns();
    fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

    outputToBinary = getRBI();
    fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

    outputToBinary = getWalks();
    fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

    outputToBinary = getStrikeOuts();
    fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

    outputToBinary = getHBP();
    fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

    outputToBinary = getStolenBases();
    fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));

    outputToBinary = getCaughtStealing();
    fout.write(reinterpret_cast<char*>(&outputToBinary), sizeof(outputToBinary));
}





