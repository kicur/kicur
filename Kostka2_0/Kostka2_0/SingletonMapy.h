#include <iostream>
#include "GeneratorTablic.h"

using namespace std;
struct SingletonMapy
{
public:
	static SingletonMapy getInstance()
	{
		cout << "SingletonMapy:: get<Instance()" << endl;
		static SingletonMapy instance;
		return instance;
	}
	static void CleanUp();

	static int** edgesMap;
	static int** edgesOMap;
	static int** cornersMap;
	static int** cornersOMap;

private:
	SingletonMapy()
	{
		cout << "SingletonMapy:: SingletonMapy()" << endl;
		generateMaps();
	}

	static void generateMaps();

};
