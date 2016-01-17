#include "stdafx.h"
#include "Kostka.h"
#include <iostream>
#include <fstream>
#include <string>


using std::cout;
using std::endl;
using std::ifstream;

//const declarations
int lRek = 7;

Kostka::Kostka()
{
	// Ustawiam wskazniki do metod zgodnie z kolejnoscia w switchu
	cout << "Kostka() begin" << endl;
	movesTab[0] = &Kostka::U;
	movesTab[1] = &Kostka::Ui;
	movesTab[2] = &Kostka::D;
	movesTab[3] = &Kostka::Di;
	movesTab[4] = &Kostka::R;
	movesTab[5] = &Kostka::Ri;
	movesTab[6] = &Kostka::L;
	movesTab[7] = &Kostka::Li;
	movesTab[8] = &Kostka::F;
	movesTab[9] = &Kostka::Fi;
	movesTab[10] = &Kostka::B;
	movesTab[11] = &Kostka::Bi;
	movesTab[12] = &Kostka::U2;
	movesTab[13] = &Kostka::D2;
	movesTab[14] = &Kostka::R2;
	movesTab[15] = &Kostka::L2;
	movesTab[16] = &Kostka::F2;
	movesTab[17] = &Kostka::B2;

	movesTabInv[0] = &Kostka::Ui;
	movesTabInv[1] = &Kostka::U;
	movesTabInv[2] = &Kostka::Di;
	movesTabInv[3] = &Kostka::D;
	movesTabInv[4] = &Kostka::Ri;
	movesTabInv[5] = &Kostka::R;
	movesTabInv[6] = &Kostka::Li;
	movesTabInv[7] = &Kostka::L;
	movesTabInv[8] = &Kostka::Fi;
	movesTabInv[9] = &Kostka::F;
	movesTabInv[10] = &Kostka::Bi;
	movesTabInv[11] = &Kostka::B;
	movesTabInv[12] = &Kostka::U2;
	movesTabInv[13] = &Kostka::D2;
	movesTabInv[14] = &Kostka::R2;
	movesTabInv[15] = &Kostka::L2;
	movesTabInv[16] = &Kostka::F2;
	movesTabInv[17] = &Kostka::B2;
	cout << "Kostka() end" << endl;
}
Kostka::~Kostka()
{
}


void Kostka::setCube(void)
{
	cout << "setCube(void)" << endl;
	for (int i = 0; i < 12; i++)
	{
		if (i < 8)
		{
			OCP[i] = i; //permutacje naro¿niki
			OCO[i] = 0; //orientacje

			ACP[i] = i;
			ACO[i] = 0;
		}

		OEP[i] = i; // permutacje krawêdzie
		OEO[i] = 0; //orientacje krawêdzi

		AEP[i] = i;
		AEO[i] = 0;

	}
}
bool Kostka::checkCube(void)
{
	// edges
	for (int i = 0; i < 12; i++)
	{
		if (this->OEP[i] != this->AEP[i])
		{
			return false;
		}
		if (this->OEO[i] != this->AEO[i])
		{
			return false;
		}
	}
	// corners
	for (int i = 0; i < 8; i++)
	{
		if (this->OCP[i] != this->ACP[i])
		{
			return false;
		}
		if (this->OCO[i] != this->ACO[i])
		{
			return false;
		}
	}

	return true;
}


void Kostka::displayCube(void)
{
	cout << "Narozniki Permutacje: ";
	for (int i = 0; i < 8; i++)
	{
		cout << ACP[i] << " ";
	}
	cout << endl;

	cout << "Orientacje naroznikow: ";
	for (int i = 0; i < 8; i++)
	{
		cout << ACO[i] << " ";
	}
	cout << endl;

	cout << "Permutacje Krawedzie: ";
	for (int i = 0; i < 12; i++)
	{
		cout << AEP[i] << " ";
	}
	cout << endl;

	cout << "Orientacje krawedzi: ";
	for (int i = 0; i < 12; i++)
	{
		cout << AEO[i] << " ";
	}
	cout << endl;
}
int tmp = 0;
void Kostka::U(void)
{
	//permutacje naro¿niki
	tmp = ACP[0];
	ACP[0] = ACP[3];
	ACP[3] = ACP[2];
	ACP[2] = ACP[1];
	ACP[1] = tmp;
	//orientacje naro¿ników 

	//ACO[0] = mod3[ACO[0]];//(ACO[0])(ACO[0] /*+ 0*/) % 3;
	//ACO[1] = mod3[ACO[1]];//(ACO[1] /*+ 0*/) % 3;
	//ACO[2] = mod3[ACO[2]];//(ACO[2] /*+ 0*/) % 3;
	//ACO[3] = mod3[ACO[3]];//(ACO[3] /*+ 0*/) % 3;

	tmp = ACO[0];
	ACO[0] = ACO[3];
	ACO[3] = ACO[2];
	ACO[2] = ACO[1];
	ACO[1] = tmp;

	//permutacje krawêdzie
	tmp = AEP[0];
	AEP[0] = AEP[3];
	AEP[3] = AEP[2];
	AEP[2] = AEP[1];
	AEP[1] = tmp;
	//orientacje krawêdzi

	//AEO[0] = mod2(AEO[0]);//(AEO[0] /*+ 0*/) % 2;
	//AEO[1] = mod2(AEO[1]);//(AEO[1] /*+ 0*/) % 2;
	//AEO[2] = mod2(AEO[2]);//(AEO[2] /*+ 0*/) % 2;
	//AEO[3] = mod2(AEO[3]);//(AEO[3] /*+ 0*/) % 2;

	tmp = AEO[0];
	AEO[0] = AEO[3];
	AEO[3] = AEO[2];
	AEO[2] = AEO[1];
	AEO[1] = tmp;
}

void Kostka::Ui(void)
{
	//permutacje naro¿niki
	tmp = ACP[0];
	ACP[0] = ACP[1];
	ACP[1] = ACP[2];
	ACP[2] = ACP[3];
	ACP[3] = tmp;

	//orientacje naro¿ników 
	//ACO[0] = mod3(ACO[0]);//(ACO[0] /*+ 0*/) % 3;
	//ACO[1] = mod3(ACO[1]);//(ACO[1] /*+ 0*/) % 3;
	//ACO[2] = mod3(ACO[2]);//(ACO[2] /*+ 0*/) % 3;
	//ACO[3] = mod3(ACO[3]);//(ACO[3] /*+ 0*/) % 3;

	tmp = ACO[0];
	ACO[0] = ACO[1];
	ACO[1] = ACO[2];
	ACO[2] = ACO[3];
	ACO[3] = tmp;

	//permutacje krawêdzie
	tmp = AEP[0];
	AEP[0] = AEP[1];
	AEP[1] = AEP[2];
	AEP[2] = AEP[3];
	AEP[3] = tmp;

	//orientacje krawêdzi
	//AEO[0] = mod2(AEO[0]);//(AEO[0] /*+ 0*/) % 2;
	//AEO[1] = mod2(AEO[1]);//(AEO[1] /*+ 0*/) % 2;
	//AEO[2] = mod2(AEO[2]);//(AEO[2] /*+ 0*/) % 2;
	//AEO[3] = mod2(AEO[3]);//(AEO[3] /*+ 0*/) % 2;

	tmp = AEO[0];
	AEO[0] = AEO[1];
	AEO[1] = AEO[2];
	AEO[2] = AEO[3];
	AEO[3] = tmp;
}
void Kostka::D(void)
{
	//permutacje naro¿niki
	tmp = ACP[4];
	ACP[4] = ACP[5];
	ACP[5] = ACP[6];
	ACP[6] = ACP[7];
	ACP[7] = tmp;

	//orientacje naro¿ników
	//ACO[4] = mod3(ACO[4]);//(ACO[4] /*+ 0*/) % 3;
	//ACO[5] = mod3(ACO[5]);//(ACO[5] /*+ 0*/) % 3;
	//ACO[6] = mod3(ACO[6]);//(ACO[6] /*+ 0*/) % 3;
	//ACO[7] = mod3(ACO[7]);//(ACO[7] /*+ 0*/) % 3;

	tmp = ACO[4];
	ACO[4] = ACO[5];
	ACO[5] = ACO[6];
	ACO[6] = ACO[7];
	ACO[7] = tmp;

	//permutacje krawêdzie
	tmp = AEP[4];
	AEP[4] = AEP[5];
	AEP[5] = AEP[6];
	AEP[6] = AEP[7];
	AEP[7] = tmp;

	//orientacje krawêdzi
	//AEO[4] = mod2(AEO[4]);//(AEO[4] /*+ 0*/) % 2;
	//AEO[5] = mod2(AEO[5]);//(AEO[5] /*+ 0*/) % 2;
	//AEO[6] = mod2(AEO[6]);//(AEO[6] /*+ 0*/) % 2;
	//AEO[7] = mod2(AEO[7]);//(AEO[7] /*+ 0*/) % 2;

	tmp = AEO[4];
	AEO[4] = AEO[5];
	AEO[5] = AEO[6];
	AEO[6] = AEO[7];
	AEO[7] = tmp;
}
void Kostka::Di(void)
{
	//permutacje naro¿niki
	tmp = ACP[4];
	ACP[4] = ACP[7];
	ACP[7] = ACP[6];
	ACP[6] = ACP[5];
	ACP[5] = tmp;

	//orientacje naro¿ników
	//ACO[4] = mod3(ACO[4]);// (ACO[4] /*+ 0*/) % 3;
	//ACO[7] = mod3(ACO[7]);//(ACO[7] /*+ 0*/) % 3;
	//ACO[6] = mod3(ACO[6]);//(ACO[6] /*+ 0*/) % 3;
	//ACO[5] = mod3(ACO[5]);//(ACO[5] /*+ 0*/) % 3;

	tmp = ACO[4];
	ACO[4] = ACO[7];
	ACO[7] = ACO[6];
	ACO[6] = ACO[5];
	ACO[5] = tmp;

	//permutacje krawêdzie
	tmp = AEP[4];
	AEP[4] = AEP[7];
	AEP[7] = AEP[6];
	AEP[6] = AEP[5];
	AEP[5] = tmp;

	//orientacje krawêdzi
	//AEO[4] = mod2(AEO[4]);//(AEO[4] /*+ 0*/) % 2;
	//AEO[7] = mod2(AEO[7]);//(AEO[7] /*+ 0*/) % 2;
	//AEO[6] = mod2(AEO[6]);//(AEO[6] /*+ 0*/) % 2;
	//AEO[5] = mod2(AEO[5]);//(AEO[5] /*+ 0*/) % 2;

	tmp = AEO[4];
	AEO[4] = AEO[7];
	AEO[7] = AEO[6];
	AEO[6] = AEO[5];
	AEO[5] = tmp;
}
void Kostka::F(void)
{
	//permutacje naro¿niki 
	tmp = ACP[0];
	ACP[0] = ACP[1];
	ACP[1] = ACP[5];
	ACP[5] = ACP[4];
	ACP[4] = tmp;

	//orientacje naro¿ników 
	ACO[0] = mod3[(ACO[0] + 1)];
	ACO[1] = mod3[(ACO[1] + 2)];
	ACO[4] = mod3[(ACO[4] + 2)];
	ACO[5] = mod3[(ACO[5] + 1)];

	tmp = ACO[0];
	ACO[0] = ACO[1];
	ACO[1] = ACO[5];
	ACO[5] = ACO[4];
	ACO[4] = tmp;

	//permutacje krawêdzie
	tmp = AEP[0];
	AEP[0] = AEP[8];
	AEP[8] = AEP[4];
	AEP[4] = AEP[10];
	AEP[10] = tmp;

	//orientacje krawêdzi 
	AEO[0] = mod2[AEO[0] + 1];//(AEO[0] + 1) % 2;
	AEO[8] = mod2[AEO[8] + 1];//(AEO[8] + 1) % 2;
	AEO[4] = mod2[AEO[4] + 1];//(AEO[4] + 1) % 2;
	AEO[10] = mod2[AEO[10] + 1];//(AEO[10] + 1) % 2;

	tmp = AEO[0];
	AEO[0] = AEO[8];
	AEO[8] = AEO[4];
	AEO[4] = AEO[10];
	AEO[10] = tmp;

}
void Kostka::Fi(void)
{
	//permutacje naro¿niki 
	tmp = ACP[0];
	ACP[0] = ACP[4];
	ACP[4] = ACP[5];
	ACP[5] = ACP[1];
	ACP[1] = tmp;

	//orientacje naro¿ników 
	ACO[0] = mod3[ACO[0] + 1];
	ACO[1] = mod3[ACO[1] + 2];
	ACO[4] = mod3[ACO[4] + 2];
	ACO[5] = mod3[ACO[5] + 1];

	tmp = ACO[0];
	ACO[0] = ACO[4];
	ACO[4] = ACO[5];
	ACO[5] = ACO[1];
	ACO[1] = tmp;

	//permutacje krawêdzi
	tmp = AEP[0];
	AEP[0] = AEP[10];
	AEP[10] = AEP[4];
	AEP[4] = AEP[8];
	AEP[8] = tmp;

	//orientacje krawêdzi 
	AEO[0] = mod2[AEO[0] + 1];//(AEO[0] + 1) % 2;
	AEO[8] = mod2[AEO[8] + 1];//(AEO[8] + 1) % 2;
	AEO[4] = mod2[AEO[4] + 1];//(AEO[4] + 1) % 2;
	AEO[10] = mod2[AEO[10] + 1];//(AEO[10] + 1) % 2;

	tmp = AEO[0];
	AEO[0] = AEO[10];
	AEO[10] = AEO[4];
	AEO[4] = AEO[8];
	AEO[8] = tmp;
}
void Kostka::B(void)
{
	//permutacje naro¿niki 2, 3, 6, 7
	tmp = ACP[2];
	ACP[2] = ACP[3];
	ACP[3] = ACP[7];
	ACP[7] = ACP[6];
	ACP[6] = tmp;

	//orientacje naro¿ników 
	ACO[2] = mod3[ACO[2] + 1];
	ACO[3] = mod3[ACO[3] + 2];
	ACO[7] = mod3[ACO[7] + 1];
	ACO[6] = mod3[ACO[6] + 2];

	tmp = ACO[2];
	ACO[2] = ACO[3];
	ACO[3] = ACO[7];
	ACO[7] = ACO[6];
	ACO[6] = tmp;

	//permutacje krawêdzi 2, 6, 9, 11
	tmp = AEP[2];
	AEP[2] = AEP[11];
	AEP[11] = AEP[6];
	AEP[6] = AEP[9];
	AEP[9] = tmp;

	//orientacje krawêdzi 
	AEO[2] = mod2[AEO[2] + 1];//(AEO[2] + 1) % 2;
	AEO[11] = mod2[AEO[11] + 1];//(AEO[11] + 1) % 2;
	AEO[6] = mod2[AEO[6] + 1];//(AEO[6] + 1) % 2;
	AEO[9] = mod2[AEO[9] + 1];//(AEO[9] + 1) % 2;

	tmp = AEO[2];
	AEO[2] = AEO[11];
	AEO[11] = AEO[6];
	AEO[6] = AEO[9];
	AEO[9] = tmp;
}
void Kostka::Bi(void)
{
	//permutacje naro¿niki 2, 3, 6, 7
	tmp = ACP[3];
	ACP[3] = ACP[2];
	ACP[2] = ACP[6];
	ACP[6] = ACP[7];
	ACP[7] = tmp;

	//orientacje naro¿ników 
	ACO[2] = mod3[ACO[2] + 1];
	ACO[3] = mod3[ACO[3] + 2];
	ACO[7] = mod3[ACO[7] + 1];
	ACO[6] = mod3[ACO[6] + 2];

	tmp = ACO[3];
	ACO[3] = ACO[2];
	ACO[2] = ACO[6];
	ACO[6] = ACO[7];
	ACO[7] = tmp;

	//permutacje krawêdzi 2, 6, 9, 11
	tmp = AEP[2];
	AEP[2] = AEP[9];
	AEP[9] = AEP[6];
	AEP[6] = AEP[11];
	AEP[11] = tmp;

	//orientacje krawêdzi 
	AEO[2] = mod2[AEO[2] + 1];//(AEO[2] + 1) % 2;
	AEO[11] = mod2[AEO[11] + 1];//(AEO[11] + 1) % 2;
	AEO[6] = mod2[AEO[6] + 1];//(AEO[6] + 1) % 2;
	AEO[9] = mod2[AEO[9] + 1];//(AEO[9] + 1) % 2;

	tmp = AEO[2];
	AEO[2] = AEO[9];
	AEO[9] = AEO[6];
	AEO[6] = AEO[11];
	AEO[11] = tmp;
}
void Kostka::R(void)
{
	//permutacje naro¿niki 0, 3, 4, 7
	tmp = ACP[0];
	ACP[0] = ACP[4];
	ACP[4] = ACP[7];
	ACP[7] = ACP[3];
	ACP[3] = tmp;

	//orientacje naro¿ników 
	ACO[0] = mod3[ACO[0] + 2];
	ACO[4] = mod3[ACO[4] + 1];
	ACO[7] = mod3[ACO[7] + 2];
	ACO[3] = mod3[ACO[3] + 1];

	tmp = ACO[0];
	ACO[0] = ACO[4];
	ACO[4] = ACO[7];
	ACO[7] = ACO[3];
	ACO[3] = tmp;

	//permutacje krawêdzi 3, 11, 7, 10
	tmp = AEP[3];
	AEP[3] = AEP[10];
	AEP[10] = AEP[7];
	AEP[7] = AEP[11];
	AEP[11] = tmp;

	//orientacje krawêdzi 
	AEO[3] = mod2[AEO[3] + 1];//mod2[AEO[3] + 1];//(AEO[3] /*+ 1*/) % 2;
	AEO[10] = mod2[AEO[10] + 1];//mod2[AEO[10] + 1];//(AEO[10] /*+ 1*/) % 2;
	AEO[7] = mod2[AEO[7] + 1];//mod2[AEO[7] + 1];//(AEO[7] /*+ 1*/) % 2;
	AEO[11] = mod2[AEO[11] + 1];//mod2[AEO[11] + 1];//(AEO[11] /*+ 1*/) % 2;

	tmp = AEO[3];
	AEO[3] = AEO[10];
	AEO[10] = AEO[7];
	AEO[7] = AEO[11];
	AEO[11] = tmp;
}
void Kostka::Ri(void)
{
	//permutacje naro¿niki 0, 3, 4, 7
	tmp = ACP[0];
	ACP[0] = ACP[3];
	ACP[3] = ACP[7];
	ACP[7] = ACP[4];
	ACP[4] = tmp;

	//orientacje naro¿ników 
	ACO[0] = mod3[ACO[0] + 2];
	ACO[3] = mod3[ACO[3] + 1];
	ACO[7] = mod3[ACO[7] + 2];
	ACO[4] = mod3[ACO[4] + 1];

	tmp = ACO[0];
	ACO[0] = ACO[3];
	ACO[3] = ACO[7];
	ACO[7] = ACO[4];
	ACO[4] = tmp;

	//permutacje krawêdzi 3, 11, 7, 10
	tmp = AEP[3];
	AEP[3] = AEP[11];
	AEP[11] = AEP[7];
	AEP[7] = AEP[10];
	AEP[10] = tmp;

	//orientacje krawêdzi 
	AEO[3] = mod2[AEO[3] + 1];//(AEO[3] /*+ 1*/) % 2;
	AEO[11] = mod2[AEO[11] + 1];//(AEO[11] /*+ 1*/) % 2;
	AEO[7] = mod2[AEO[7] + 1];//(AEO[7] /*+ 1*/) % 2;
	AEO[10] = mod2[AEO[10] + 1];//(AEO[10] /*+ 1*/) % 2;

	tmp = AEO[3];
	AEO[3] = AEO[11];
	AEO[11] = AEO[7];
	AEO[7] = AEO[10];
	AEO[10] = tmp;
}
void Kostka::L(void)
{
	//permutacje naro¿niki 1, 2, 5, 6
	tmp = ACP[1];
	ACP[1] = ACP[2];
	ACP[2] = ACP[6];
	ACP[6] = ACP[5];
	ACP[5] = tmp;

	//orientacje naro¿ników 
	ACO[1] = mod3[ACO[1] + 1];
	ACO[2] = mod3[ACO[2] + 2];
	ACO[6] = mod3[ACO[6] + 1];
	ACO[5] = mod3[ACO[5] + 2];

	tmp = ACO[1];
	ACO[1] = ACO[2];
	ACO[2] = ACO[6];
	ACO[6] = ACO[5];
	ACO[5] = tmp;

	//permutacje krawêdzi 1, 5, 8, 9
	tmp = AEP[1];
	AEP[1] = AEP[9];
	AEP[9] = AEP[5];
	AEP[5] = AEP[8];
	AEP[8] = tmp;

	//orientacje krawêdzi 
	AEO[1] = mod2[AEO[1] + 1];//(AEO[1] /*+ 1*/) % 2;
	AEO[9] = mod2[AEO[9] + 1];//(AEO[9] /*+ 1*/) % 2;
	AEO[5] = mod2[AEO[5] + 1];//(AEO[5] /*+ 1*/) % 2;
	AEO[8] = mod2[AEO[8] + 1];//(AEO[8] /*+ 1*/) % 2;

	tmp = AEO[1];
	AEO[1] = AEO[9];
	AEO[9] = AEO[5];
	AEO[5] = AEO[8];
	AEO[8] = tmp;
}
void Kostka::Li(void)
{
	//permutacje naro¿niki 1, 2, 5, 6
	tmp = ACP[1];
	ACP[1] = ACP[5];
	ACP[5] = ACP[6];
	ACP[6] = ACP[2];
	ACP[2] = tmp;

	//orientacje naro¿ników 
	ACO[1] = mod3[ACO[1] + 1];
	ACO[5] = mod3[ACO[5] + 2];
	ACO[6] = mod3[ACO[6] + 1];
	ACO[2] = mod3[ACO[2] + 2];

	tmp = ACO[1];
	ACO[1] = ACO[5];
	ACO[5] = ACO[6];
	ACO[6] = ACO[2];
	ACO[2] = tmp;

	//permutacje krawêdzi 1, 5, 8, 9
	tmp = AEP[1];
	AEP[1] = AEP[8];
	AEP[8] = AEP[5];
	AEP[5] = AEP[9];
	AEP[9] = tmp;

	//orientacje krawêdzi 
	AEO[1] = mod2[AEO[1] + 1];//(AEO[1] /*+ 1*/) % 2;
	AEO[8] = mod2[AEO[8] + 1];//(AEO[8] /*+ 1*/) % 2;
	AEO[5] = mod2[AEO[5] + 1];//(AEO[5] /*+ 1*/) % 2;
	AEO[9] = mod2[AEO[9] + 1];//(AEO[9] /*+ 1*/) % 2;

	tmp = AEO[1];
	AEO[1] = AEO[8];
	AEO[8] = AEO[5];
	AEO[5] = AEO[9];
	AEO[9] = tmp;
}
void Kostka::U2(void)
{
	//permutacje naro¿niki
	tmp = ACP[0];
	ACP[0] = ACP[2];
	ACP[2] = tmp;
	tmp = ACP[1];
	ACP[1] = ACP[3];
	ACP[3] = tmp;
	//orientacje naro¿ników 

	//ACO[0] = mod3[ACO[0]];//(ACO[0])(ACO[0] /*+ 0*/) % 3;
	//ACO[1] = mod3[ACO[1]];//(ACO[1] /*+ 0*/) % 3;
	//ACO[2] = mod3[ACO[2]];//(ACO[2] /*+ 0*/) % 3;
	//ACO[3] = mod3[ACO[3]];//(ACO[3] /*+ 0*/) % 3;

	tmp = ACO[0];
	ACO[0] = ACO[2];
	ACO[2] = tmp;
	tmp = ACO[1];
	ACO[1] = ACO[3];
	ACO[3] = tmp;

	//permutacje krawêdzie
	tmp = AEP[0];
	AEP[0] = AEP[2];
	AEP[2] = tmp;
	tmp = AEP[1];
	AEP[1] = AEP[3];
	AEP[3] = tmp;
	//orientacje krawêdzi

	//AEO[0] = mod2(AEO[0]);//(AEO[0] /*+ 0*/) % 2;
	//AEO[1] = mod2(AEO[1]);//(AEO[1] /*+ 0*/) % 2;
	//AEO[2] = mod2(AEO[2]);//(AEO[2] /*+ 0*/) % 2;
	//AEO[3] = mod2(AEO[3]);//(AEO[3] /*+ 0*/) % 2;

	tmp = AEO[0];
	AEO[0] = AEO[2];
	AEO[2] = tmp;
	tmp = AEO[1];
	AEO[1] = AEO[3];
	AEO[3] = tmp;
}
void Kostka::D2(void)
{
	//permutacje naro¿niki
	tmp = ACP[4];
	ACP[4] = ACP[6];
	ACP[6] = tmp;
	tmp = ACP[5];
	ACP[5] = ACP[7];
	ACP[7] = tmp;
	//orientacje naro¿ników 

	//ACO[0] = mod3[ACO[0]];//(ACO[0])(ACO[0] /*+ 0*/) % 3;
	//ACO[1] = mod3[ACO[1]];//(ACO[1] /*+ 0*/) % 3;
	//ACO[2] = mod3[ACO[2]];//(ACO[2] /*+ 0*/) % 3;
	//ACO[3] = mod3[ACO[3]];//(ACO[3] /*+ 0*/) % 3;

	tmp = ACO[4];
	ACO[4] = ACO[6];
	ACO[6] = tmp;
	tmp = ACO[5];
	ACO[5] = ACO[7];
	ACO[7] = tmp;

	//permutacje krawêdzie
	tmp = AEP[4];
	AEP[4] = AEP[6];
	AEP[6] = tmp;
	tmp = AEP[5];
	AEP[5] = AEP[7];
	AEP[7] = tmp;
	//orientacje krawêdzi

	//AEO[0] = mod2(AEO[0]);//(AEO[0] /*+ 0*/) % 2;
	//AEO[1] = mod2(AEO[1]);//(AEO[1] /*+ 0*/) % 2;
	//AEO[2] = mod2(AEO[2]);//(AEO[2] /*+ 0*/) % 2;
	//AEO[3] = mod2(AEO[3]);//(AEO[3] /*+ 0*/) % 2;

	tmp = AEO[4];
	AEO[4] = AEO[6];
	AEO[6] = tmp;
	tmp = AEO[5];
	AEO[5] = AEO[7];
	AEO[7] = tmp;
}
void Kostka::F2(void)
{
	//permutacje naro¿niki
	tmp = ACP[0];
	ACP[0] = ACP[5];
	ACP[5] = tmp;
	tmp = ACP[1];
	ACP[1] = ACP[4];
	ACP[4] = tmp;
	//orientacje naro¿ników 

	//ACO[0] = mod3[ACO[0]];//(ACO[0])(ACO[0] /*+ 0*/) % 3;
	//ACO[1] = mod3[ACO[1]];//(ACO[1] /*+ 0*/) % 3;
	//ACO[2] = mod3[ACO[2]];//(ACO[2] /*+ 0*/) % 3;
	//ACO[3] = mod3[ACO[3]];//(ACO[3] /*+ 0*/) % 3;

	tmp = ACO[0];
	ACO[0] = ACO[5];
	ACO[5] = tmp;
	tmp = ACO[1];
	ACO[1] = ACO[4];
	ACO[4] = tmp;

	//permutacje krawêdzie
	tmp = AEP[0];
	AEP[0] = AEP[4];
	AEP[4] = tmp;
	tmp = AEP[8];
	AEP[8] = AEP[10];
	AEP[10] = tmp;
	//orientacje krawêdzi

	//AEO[0] = mod2(AEO[0]);//(AEO[0] /*+ 0*/) % 2;
	//AEO[1] = mod2(AEO[1]);//(AEO[1] /*+ 0*/) % 2;
	//AEO[2] = mod2(AEO[2]);//(AEO[2] /*+ 0*/) % 2;
	//AEO[3] = mod2(AEO[3]);//(AEO[3] /*+ 0*/) % 2;

	tmp = AEO[0];
	AEO[0] = AEO[4];
	AEO[4] = tmp;
	tmp = AEO[8];
	AEO[8] = AEO[10];
	AEO[10] = tmp;
}
void Kostka::B2(void)
{
	//permutacje naro¿niki
	tmp = ACP[2];
	ACP[2] = ACP[7];
	ACP[7] = tmp;
	tmp = ACP[3];
	ACP[3] = ACP[6];
	ACP[6] = tmp;
	//orientacje naro¿ników 

	//ACO[0] = mod3[ACO[0]];//(ACO[0])(ACO[0] /*+ 0*/) % 3;
	//ACO[1] = mod3[ACO[1]];//(ACO[1] /*+ 0*/) % 3;
	//ACO[2] = mod3[ACO[2]];//(ACO[2] /*+ 0*/) % 3;
	//ACO[3] = mod3[ACO[3]];//(ACO[3] /*+ 0*/) % 3;

	tmp = ACO[2];
	ACO[2] = ACO[7];
	ACO[7] = tmp;
	tmp = ACO[3];
	ACO[3] = ACO[6];
	ACO[6] = tmp;

	//permutacje krawêdzie
	tmp = AEP[2];
	AEP[2] = AEP[6];
	AEP[6] = tmp;
	tmp = AEP[9];
	AEP[9] = AEP[11];
	AEP[11] = tmp;
	//orientacje krawêdzi

	//AEO[0] = mod2(AEO[0]);//(AEO[0] /*+ 0*/) % 2;
	//AEO[1] = mod2(AEO[1]);//(AEO[1] /*+ 0*/) % 2;
	//AEO[2] = mod2(AEO[2]);//(AEO[2] /*+ 0*/) % 2;
	//AEO[3] = mod2(AEO[3]);//(AEO[3] /*+ 0*/) % 2;

	tmp = AEO[2];
	AEO[2] = AEO[6];
	AEO[6] = tmp;
	tmp = AEO[9];
	AEO[9] = AEO[11];
	AEO[11] = tmp;
}
void Kostka::R2(void)
{
	//permutacje naro¿niki
	tmp = ACP[0];
	ACP[0] = ACP[7];
	ACP[7] = tmp;
	tmp = ACP[3];
	ACP[3] = ACP[4];
	ACP[4] = tmp;
	//orientacje naro¿ników 

	//ACO[0] = mod3[ACO[0]];//(ACO[0])(ACO[0] /*+ 0*/) % 3;
	//ACO[1] = mod3[ACO[1]];//(ACO[1] /*+ 0*/) % 3;
	//ACO[2] = mod3[ACO[2]];//(ACO[2] /*+ 0*/) % 3;
	//ACO[3] = mod3[ACO[3]];//(ACO[3] /*+ 0*/) % 3;

	tmp = ACO[0];
	ACO[0] = ACO[7];
	ACO[7] = tmp;
	tmp = ACO[3];
	ACO[3] = ACO[4];
	ACO[4] = tmp;

	//permutacje krawêdzie
	tmp = AEP[3];
	AEP[3] = AEP[7];
	AEP[7] = tmp;
	tmp = AEP[10];
	AEP[10] = AEP[11];
	AEP[11] = tmp;
	//orientacje krawêdzi

	//AEO[0] = mod2(AEO[0]);//(AEO[0] /*+ 0*/) % 2;
	//AEO[1] = mod2(AEO[1]);//(AEO[1] /*+ 0*/) % 2;
	//AEO[2] = mod2(AEO[2]);//(AEO[2] /*+ 0*/) % 2;
	//AEO[3] = mod2(AEO[3]);//(AEO[3] /*+ 0*/) % 2;

	tmp = AEO[3];
	AEO[3] = AEO[7];
	AEO[7] = tmp;
	tmp = AEO[10];
	AEO[10] = AEO[11];
	AEO[11] = tmp;
}
void Kostka::L2(void)
{
	//permutacje naro¿niki
	tmp = ACP[1];
	ACP[1] = ACP[6];
	ACP[6] = tmp;
	tmp = ACP[2];
	ACP[2] = ACP[5];
	ACP[5] = tmp;
	//orientacje naro¿ników 

	//ACO[0] = mod3[ACO[0]];//(ACO[0])(ACO[0] /*+ 0*/) % 3;
	//ACO[1] = mod3[ACO[1]];//(ACO[1] /*+ 0*/) % 3;
	//ACO[2] = mod3[ACO[2]];//(ACO[2] /*+ 0*/) % 3;
	//ACO[3] = mod3[ACO[3]];//(ACO[3] /*+ 0*/) % 3;

	tmp = ACO[1];
	ACO[1] = ACO[6];
	ACO[6] = tmp;
	tmp = ACO[2];
	ACO[2] = ACO[5];
	ACO[5] = tmp;

	//permutacje krawêdzie
	tmp = AEP[1];
	AEP[1] = AEP[5];
	AEP[5] = tmp;
	tmp = AEP[9];
	AEP[9] = AEP[8];
	AEP[8] = tmp;
	//orientacje krawêdzi

	//AEO[0] = mod2(AEO[0]);//(AEO[0] /*+ 0*/) % 2;
	//AEO[1] = mod2(AEO[1]);//(AEO[1] /*+ 0*/) % 2;
	//AEO[2] = mod2(AEO[2]);//(AEO[2] /*+ 0*/) % 2;
	//AEO[3] = mod2(AEO[3]);//(AEO[3] /*+ 0*/) % 2;

	tmp = AEO[1];
	AEO[1] = AEO[5];
	AEO[5] = tmp;
	tmp = AEO[9];
	AEO[9] = AEO[8];
	AEO[8] = tmp;
}


void Kostka::shuffleCube(unsigned short int noOfMoves)
{
	for (int i = 0; i < noOfMoves; i++)
	{
		int tmp = rand() % 12;
		cout << "liczba to: " << tmp << endl;
		executeMove(tmp);

	}
}


int Kostka::getCornersAsInt()
{
	int sum = 0;
	for (int i = CORNERS - 1; i > 0; i--)
	{
		int cornersLeft = 0; // ile rogow na lewo od aktualnego ma od niego wieksza wartosc
		for (int j = i - 1; j >= 0; j--)
		{
			if (ACP[j] > ACP[i])
				cornersLeft++;
		}
		//sum = (sum + cornersLeft) * i;
		sum += cornersLeft * silnia(i);
	}
	return sum;
}
int Kostka::getCornersOAsInt()
{
	int sum = 0;
	for (int i = 0; i < CORNERS; i++)
	{
		sum += ACO[i] * (int)pow(3.0, CORNERS - 1 - i);
	}
	return sum;
}
int Kostka::getEdgesAsInt()
{
	int sum = 0;
	for (int i = EDGES - 1; i > 0; i--)
	{
		int edgesLeft = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (AEP[j] > AEP[i])
				edgesLeft++;
		}
		sum += edgesLeft * silnia(i);
	}
	return sum;
}
int Kostka::getEdgesOAsInt()
{
	int sum = 0;
	for (int i = 0; i < EDGES; i++)
	{
		if (AEO[i] > 1)
			continue;
		sum += AEO[i] * (int)pow(2.0, EDGES - 1 - i);
	}
	return sum;
}

void Kostka::setCornersAsInt(int corners)
{
	char* tmp = new char[CORNERS];
	for (int i = 0; i < CORNERS; i++)
	{
		tmp[i] = i;
	}
	int reszta;
	int calk;
	for (int i = CORNERS - 1; i >= 0; i--)
	{
		reszta = corners % silnia(i);
		calk = corners / silnia(i);
		int k = 0;
		for (int j = CORNERS - 1; j >= 0; j--)
		{
			if (tmp[j] < 0)
				continue;
			k++;
			if (k > calk)
			{
				ACP[i] = tmp[j];
				tmp[j] = -1;
				break;
			}
		}
		corners = reszta;
	}
	delete[] tmp;
}
void Kostka::setCornersOAsInt(int cornersO)
{
	for (int i = 0; i < CORNERS; i++)
	{
		ACO[CORNERS - 1 - i] = cornersO % 3;
		cornersO /= 3;
	}
}
void Kostka::setEdgesAsInt(int edges)
{
	char* tmp = new char[EDGES];
	for (int i = 0; i < EDGES; i++)
	{
		tmp[i] = i;
	}
	int reszta;
	int calk;
	for (int i = EDGES - 1; i >= 0; i--)
	{
		reszta = edges % silnia(i);
		calk = edges / silnia(i);
		int k = 0;
		for (int j = EDGES - 1; j >= 0; j--)
		{
			if (tmp[j] < 0)
				continue;
			k++;
			if (k > calk)
			{
				AEP[i] = tmp[j];
				tmp[j] = -1;
				break;
			}
		}
		edges = reszta;
	}
}
void Kostka::setEdgesOAsInt(int edgesO)
{
	for (int i = 0; i < EDGES; i++)
	{
		AEO[EDGES - 1 - i] = edgesO % 2;
		edgesO /= 2;
	}
}

int Kostka::getUFtoUR()
{
	int sum = 0;
	for (int i = (int)UF; i <= (int)UR; i++)
	{
		for (int j = (int)UF; j <= (int)DR; j++)
		{
			if (AEP[j] == i)
				sum += j * (int)pow(12.0, (double)i);
		}
	}
	return sum;
}
int Kostka::getFLtoFR()
{
	int sum = 0;
	for (int i = (int)FL; i <= (int)FR; i++)
	{
		for (int j = (int)UF; j <= (int)DR; j++)
		{
			if (AEP[j] == i)
				sum += j * (int)pow(12.0, (double)(i - 4));
		}
	}
	return sum;
}
int Kostka::getDFtoDR()
{
	int sum = 0;
	for (int i = (int)DF; i <= (int)DR; i++)
	{
		for (int j = (int)UF; j <= (int)DR; j++)
		{
			if (AEP[j] == i)
				sum += j * (int)pow(12.0, (double)(i - 8));
		}
	}
	return sum;
}

void Kostka::setUFtoUR(int UFtoUR)
{
	for (int i = (int)UF; i <= DR; i++)
	{
		AEP[i] = EDGES;
	}
	for (int i = (int)UF; i <= (int)UR; i++)
	{
		AEP[UFtoUR % 12] = i;
		UFtoUR /= 12;
	}
}
void Kostka::setFLtoFR(int FLtoFR)
{
	for (int i = (int)UF; i <= DR; i++)
	{
		AEP[i] = EDGES;
	}
	for (int i = (int)FL; i <= (int)FR; i++)
	{
		AEP[FLtoFR % 12] = i;
		FLtoFR /= 12;
	}
}
void Kostka::setDFtoDR(int DFtoDR)
{
	for (int i = (int)UF; i <= DR; i++)
	{
		AEP[i] = EDGES;
	}
	for (int i = (int)DF; i <= (int)DR; i++)
	{
		AEP[DFtoDR % 12] = i;
		DFtoDR /= 12;
	}
}

void Kostka::executeMove(unsigned short int move)
{
	(this->*movesTab[move])();
}
void Kostka::executeMoveInv(unsigned short int move)
{
	(this->*movesTabInv[move])();

}

