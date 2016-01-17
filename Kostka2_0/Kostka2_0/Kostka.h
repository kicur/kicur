#ifndef KOSTKA_H
#define KOSTKA_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "KostkaAbstract.h"
#include <iostream>
using namespace std;

class Kostka : public KostkaAbstract
{

protected:
	// Tablica wskaznikow na metody wykonujace ruchy
	void (Kostka::*movesTab[18])(void);
	// Tablica wskaznikow na metody wykonujace inwersje ruchow
	void (Kostka::*movesTabInv[18])(void);

	short int OEP[12]; //permutacje krawêdzi
	short int OEO[12]; //orientacje krawêdzi
	short int OCP[8]; //permutacje naro¿ników
	short int OCO[8]; //orientacje naro¿ników

	short int AEP[12]; //permutacje krawêdzi
	short int AEO[12]; //orientacje krawêdzi
	short int ACP[8]; //permutacje naro¿ników
	short int ACO[8]; //orientacje naro¿ników

public:
	int getCornersOAsInt();
	int getCornersAsInt();
	int getEdgesOAsInt();
	int getEdgesAsInt();

	void setCornersAsInt(int corners);
	void setCornersOAsInt(int cornersO);
	void setEdgesAsInt(int edges);
	void setEdgesOAsInt(int edgesO);

	int getUFtoUR();
	int getFLtoFR();
	int getDFtoDR();

	void setUFtoUR(int UFtoUR);
	void setFLtoFR(int FLtoFR);
	void setDFtoDR(int DFtoDR);


	Kostka();
	//metody operuj¹ce na kostce


	//nowa KOSTKA
	void setCube(void);
	bool checkCube(void);
	void displayCube(void);
	void shuffleCube(unsigned short int noOfMoves);

	void U(void);
	void Ui(void);
	void U2(void);

	void D(void);
	void Di(void);
	void D2(void);

	void F(void);
	void Fi(void);
	void F2(void);

	void B(void);
	void Bi(void);
	void B2(void);

	void R(void);
	void Ri(void);
	void R2(void);

	void L(void);
	void Li(void);
	void L2(void);

	void executeMove(unsigned short int move);
	void executeMoveInv(unsigned short int move);

	short int getOEO(int index) { return OEO[index]; }
	void setOEO(int index, int value) { OEO[index] = value; }
	~Kostka();
};



#endif

