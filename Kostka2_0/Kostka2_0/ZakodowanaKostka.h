#ifndef ZAKODOWANAKOSTKA_H
#define ZAKODOWANAKOSTKA_H
#include <iostream>
#include "SingletonMapy.h"
#include "KostkaAbstract.h"


class ZakodowanaKostka : public KostkaAbstract
{

public:
	//nowa KOSTKA
	ZakodowanaKostka();
	~ZakodowanaKostka();

	void setCube(void);
	bool checkCube(); //check if all cube is solved
	void displayCube(void);
	void shuffleCube(unsigned short int noOfMoves);

	void executeMove(unsigned short int move);
	void executeMoveInv(unsigned short int move);


protected:

	// Stan kosci zakodowanej w intach
	int corners;
	int cornersO;
	int UFtoUR;
	int FLtoFR;
	int DFtoDR;
	int edgesO;

};

#endif
