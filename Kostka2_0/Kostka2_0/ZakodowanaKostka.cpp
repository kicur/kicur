#include "stdafx.h"
#include "ZakodowanaKostka.h"

ZakodowanaKostka::ZakodowanaKostka()
{

}

ZakodowanaKostka::~ZakodowanaKostka()
{

}

void ZakodowanaKostka::setCube(void)
{
	cout << "ZakodowanaKostka - setCube(void)" << endl;
	corners = 0;
	cornersO = 0;
	edgesO = 0;
	UFtoUR = 0;
	//FLtoFR = ;
	//DFtoDR = ;

}
bool ZakodowanaKostka::checkCube()
{
	if (corners != 0)
		return false;
	if (cornersO != 0)
		return false;
	if (edgesO != 0)
		return false;
	if (UFtoUR != 0)
		return false;
	//if (FLtoFR != ?)
	//	return false;
	//if (DFtoDR != ?)
	//	return false;
}
void ZakodowanaKostka::displayCube(void)
{
	cout << "Narozniki Permutacje: ";
	cout << corners << endl;

	cout << "Orientacje naroznikow: ";
	cout << cornersO << endl;

	cout << "Permutacje Krawedzie: ";
	cout << "UFtoUR: " << UFtoUR << endl;
	cout << "FLtoFR: " << FLtoFR << endl;
	cout << "DFtoDR: " << DFtoDR << endl;

	cout << "Orientacje krawedzi: ";
	cout << edgesO << endl;
}
void ZakodowanaKostka::shuffleCube(unsigned short int noOfMoves)
{
	cout << "kostka zostala pomieszana nastepujacymi ruchami: ";
	for (int i = 0; i < noOfMoves; i++)
	{
		int tmp = rand() % 12;
		cout << tmp << ", ";
		executeMove(tmp);
	}
	cout << endl;
}

void ZakodowanaKostka::executeMove(unsigned short int move)
{
	this->corners = SingletonMapy::cornersMap[corners][move];
	this->cornersO = SingletonMapy::cornersOMap[cornersO][move];

	this->UFtoUR = SingletonMapy::edgesMap[UFtoUR][move];
	this->FLtoFR = SingletonMapy::edgesMap[FLtoFR][move];
	this->DFtoDR = SingletonMapy::edgesMap[DFtoDR][move];
	this->edgesO = SingletonMapy::edgesOMap[edgesO][move];

}
void ZakodowanaKostka::executeMoveInv(unsigned short int move)
{
	this->corners = SingletonMapy::cornersMap[corners][movesInversions[move]];
	this->cornersO = SingletonMapy::cornersOMap[cornersO][movesInversions[move]];

	this->UFtoUR = SingletonMapy::edgesMap[UFtoUR][movesInversions[move]];
	this->FLtoFR = SingletonMapy::edgesMap[FLtoFR][movesInversions[move]];
	this->DFtoDR = SingletonMapy::edgesMap[DFtoDR][movesInversions[move]];
	this->edgesO = SingletonMapy::edgesOMap[edgesO][movesInversions[move]];

}
