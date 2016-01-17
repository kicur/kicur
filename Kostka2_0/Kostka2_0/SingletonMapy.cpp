#include "stdafx.h"
#include "SingletonMapy.h"

int** SingletonMapy::edgesMap = 0;
int** SingletonMapy::edgesOMap = 0;
int** SingletonMapy::cornersMap = 0;
int** SingletonMapy::cornersOMap = 0;

void SingletonMapy::CleanUp()
{
	for (int i = 0; i < CORNERS; i++)
	{
		delete[] cornersMap[i];
		delete[] cornersOMap[i];
	}
	delete[] cornersMap;
	delete[] cornersOMap;


	for (int i = 0; i < EDGES; i++)
	{
		delete[] edgesMap[i];
		delete[] edgesOMap[i];
	}
	delete[] edgesMap;
	delete[] edgesOMap;

}

void SingletonMapy::generateMaps()
{
	cout << "SingletonMapy:: generateMaps()" << endl;
	GeneratorTablic gen;
	edgesMap = gen.computeEdgesMap(24);
	edgesOMap = gen.computeEdgesOMap(pow(2.0, 12.0));

	cornersMap = gen.computeCornersMap(40320);
	cornersOMap = gen.computeCornersOMap(pow(3.0, 8.0));

}
