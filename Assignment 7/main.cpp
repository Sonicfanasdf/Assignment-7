#include<iostream>
#include<string>
#include"input.h"
#include"SimpleCalculator.h"
using namespace std;

void mainMenu();

int main()
{
	mainMenu();

	return 0;
}

void mainMenu()
{
	SimpleCalculator calculator;

	do
	{ 
	cout << "\n\t CMPR131 Chapter 7: Applications using Stacks\n";
	cout << "\t" << string(70, char(205)) << endl;
	cout << "\t  1> Simple Calculator (problem 9, pg 391)\n";
	cout << "\t  2> Translation of arithmetic expression (problem 10, pg 391)\n";
	cout << "\t  3> n-Queens Problem (problem 11, pg 391-292)\n";
	cout << "\t" << string(70, char(196)) << endl;
	cout << "\t  0> Exit\n";
	cout << "\t" << string(70, char(205)) << endl;

	switch (inputInteger("\t  Option: ", 0, 3))
	{
	case 0:
	{
		exit(1);
	}
	break;
	case 1:
	{
		system("cls");
		calculator.calculatorMenu();
	}
	break;
	case 2:
	{
	
	}
	break;
	case 3:
	{
		
	}
	}
	} while (true);
}