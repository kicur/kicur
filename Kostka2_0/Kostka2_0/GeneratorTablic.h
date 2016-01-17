#include "Kostka.h"

class GeneratorTablic
{
public:
	int** computeEdgesMap(int length);
	int** computeCornersMap(int length);
	int** computeEdgesOMap(int length);
	int** computeCornersOMap(int length);

private:
	Kostka kostka;
};
