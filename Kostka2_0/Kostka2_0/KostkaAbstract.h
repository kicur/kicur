#ifndef CONSTDEFS_H_
#define CONSTDEFS_H_

#define EDGES 12
#define CORNERS 8
#define MOVES 18

class KostkaAbstract
{
public:
	enum EStickers // symbole naklejek
	{
		U1, U2, U3, U4, U5, U6, U7, U8, U9,
		D1, D2, D3, D4, D5, D6, D7, D8, D9,
		F1, F2, F3, F4, F5, F6, F7, F8, F9,
		L1, L2, L3, L4, L5, L6, L7, L8, L9,
		B1, B2, B3, B4, B5, B6, B7, B8, B9,
		R1, R2, R3, R4, R5, R6, R7, R8, R9
	};
	enum ECornerSymbols { UFR, UFL, UBL, UBR, DFR, DFL, DBL, DBR, NO_CORNER }; // symbole rogow
	enum EEdgeSymbols { UF, UL, UB, UR, FL, BL, BR, FR, DF, DL, DB, DR, NO_EDGE }; // symbole krawedzi
	enum ECenterSymbols { U, D, F, L, B, R, NO_CENTER }; // symbole centrow
	const static int mod2[4];
	const static int mod3[5];
	const static unsigned short int movesInversions[MOVES];

	int silnia(int n)
	{
		int tmp = 1;
		for (int i = 1; i <= n; i++)
		{
			tmp *= i;
		}
		return tmp;
	}
};


#endif /* CONSTDEFS_H_ */
