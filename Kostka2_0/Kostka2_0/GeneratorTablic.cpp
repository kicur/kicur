#include "stdafx.h"
#include "GeneratorTablic.h"

int** GeneratorTablic::computeEdgesMap(int length)
{
	cout << "GeneratorTablid:: computeEdgesMap()" << endl;
	int** edgesMap;

	edgesMap = new int*[length];
	for (int i = 0; i < length; i++)
	{
		edgesMap[i] = new int[18];
		kostka.setUFtoUR(i);
		for (int j = 0; j < 18; j++)
		{
			kostka.executeMove(j);
			edgesMap[i][j] = kostka.getUFtoUR();
			kostka.executeMoveInv(j);
		}
	}

	return edgesMap;
}

int** GeneratorTablic::computeCornersMap(int length)
{
	cout << "GeneratorTablid:: computeCornersMap()" << endl;
	int** cornersMap;

	cornersMap = new int*[length];
	for (int i = 0; i < length; i++)
	{
		cornersMap[i] = new int[18];
		kostka.setCornersAsInt(i);
		for (int j = 0; j < 18; j++)
		{
			kostka.executeMove(j);
			cornersMap[i][j] = kostka.getCornersAsInt();
			kostka.executeMoveInv(j);
		}
	}

	return cornersMap;
}

int** GeneratorTablic::computeEdgesOMap(int length)
{
	cout << "GeneratorTablid:: computeEdgesOMap()" << endl;
	int** edgesOMap;

	edgesOMap = new int*[length];
	for (int i = 0; i < length; i++)
	{
		edgesOMap[i] = new int[18];
		kostka.setEdgesOAsInt(i);
		for (int j = 0; j < 18; j++)
		{
			kostka.executeMove(j);
			edgesOMap[i][j] = kostka.getEdgesOAsInt();
			kostka.executeMoveInv(j);
		}
	}

	return edgesOMap;
}

int** GeneratorTablic::computeCornersOMap(int length)
{
	cout << "GeneratorTablid:: computeCornersOMap()" << endl;
	int** cornersOMap;

	cornersOMap = new int*[length];
	for (int i = 0; i < length; i++)
	{
		cornersOMap[i] = new int[18];
		kostka.setCornersOAsInt(i);
		for (int j = 0; j < 18; j++)
		{
			kostka.executeMove(j);
			cornersOMap[i][j] = kostka.getCornersOAsInt();
			kostka.executeMoveInv(j);
		}
	}

	return cornersOMap;
}
