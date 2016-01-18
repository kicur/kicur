#include "stdafx.h"
#include "Solver.h"


Solver::Solver()
{
	
}

bool Solver::startSolving()
{
	for (int i = 0; i < 9; i++)
	{
		if (solveCubeInCertainNumberOfMoves(i, -1, -1))
		{
			std::cout << "Udalo sie ulozyc etap: " << 0 << " w " << i << " ruchach!" << std::endl;
			std::cout << "Rozwiazanie to: " << std::endl;
			for (size_t i = 0; i < solution.size(); i++)
				std::cout << solution[i] << ", ";
			std::cout << std::endl;
			return true;
		}
		std::cout << "Nie udalo sie ulozyc etapu: " << 0 << " w " << i << " ruchach!" << std::endl;
	}
	return false;
}

bool Solver::solveCubeInCertainNumberOfMoves(unsigned short int noOfMoves, unsigned short int prevMove, unsigned short int prevMove2)
{
	if (noOfMoves == 0)
	{
		return checkCube();
	}
	else if (noOfMoves > 0)
	{
		for (int j = 0; j < 18; j++)
		{

			if (mapSymetricMoves[j][prevMove]) // if semetric continue // this if else ensure moves like UDU, UDU', U'D2U itd.
				continue;
			else							   //if not check if opposite
			{
				if (mapOppositeMoves[j][prevMove])
				{
					if ((prevMove2 >-1) && (mapSymetricMoves[j][prevMove2]))
						continue;
				}
			}

			//check for situation like RLU | LRU
			if (prevMove2 > -1)
			{
				if (mapOppositeMoves[prevMove2][prevMove])
				{
					if (mapCombineSymetricMoves[(prevMove2 + prevMove)][j])
					{
						mapCombineSymetricMoves[(prevMove2 + prevMove)][j] = 0;
						continue;
					}
					else
					{
						mapCombineSymetricMoves[(prevMove2 + prevMove)][j] = 1;
					}
				}
			}
			executeMove(j);
			solution.push_back(j); //add move to solution vector

			if (solveCubeInCertainNumberOfMoves(noOfMoves - 1, j, j - 1))
				return true;
			executeMoveInv(j);
			solution.pop_back(); //delete last move from solution vector
		}
	}
	return false;
}


Solver::~Solver()
{
}
