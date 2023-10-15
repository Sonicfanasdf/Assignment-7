#pragma once
#include<iostream>
#include<stack>
using namespace std;

string inputString(string prompt, bool spaces);
void mainMenu();

class SimpleCalculator
{
private:

	

public:
	SimpleCalculator();
	void calculatorMenu();
	void displayCalculation(stack<double>& numbers, istream& ins, double& answer);
	void evaluateExpression(stack<double>& numbers);
	int getPrecendence(char operation);
};