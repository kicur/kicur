// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Kostka.h"
#include <ctime>
#include <iostream>
#include "SingletonMapy.h"

using std::cout;
using std::endl;

int main()
{
	Kostka cube;
	cube.executeMove(2);
	/*
	srand(time(0));

	Kostka o1;
	o1.setCube();

	cout << "mod 2" << endl;
	for(int i = 0; i < 3; i++)
	{
	cout << "[" << i << "] = " << mod2[i];
	}
	cout << endl;
	cout << "mod 3" << endl;
	for(int i = 0; i < 4; i++)
	{
	cout << "[" << i << "] = " << mod3[i];
	}
	cout << endl;

	o1.shuffleCube(10); //max 8 ruchów w skoñczonym czasie uk³ada
	cout<<"Kostka przed ulozeniem: "<<endl;
	o1.displayCube();

	cout << endl;

	// ------------------------------------------------ start -----------------------------------------------
	time_t start = clock();
	if(o1.solver())
	cout << "Jebaka ulozyl krzyz" << endl;
	else
	cout << "Cos jednak poszlo nie tak :/" << endl;

	cout << "Kostka po ulozeniu: " << endl;

	cout << "Czas trwania napierdalania: " << clock() - start << endl;
	o1.displayCube();
	// ------------------------------------------------ koniec -----------------------------------------------

	*/
	SingletonMapy sm = SingletonMapy::getInstance();
	SingletonMapy sm2 = SingletonMapy::getInstance();

	return 0;
}



