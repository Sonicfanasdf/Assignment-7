#pragma once
#include<iostream>
#include<stack>
using namespace std;

string inputString(string prompt, bool spaces);
void mainMenu();

class SimpleCalculator
{
private:

	string expression;

public:
	SimpleCalculator();
	void setExpression(string newString);
	string getExpression() const;
	void calculatorMenu();
	//bool checkParenthesis(const string& expression);
	void displayCalculation(stack<double>& numbers, stack<char>& operators,istream& ins, double& answer);
	void evaluateExpression(stack<double>& numbers, stack<char>& operators);
	int getPrecendence(char operation);
};