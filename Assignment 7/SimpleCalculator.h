#pragma once
#include<iostream>
#include<stack>
using namespace std;

string inputString(string prompt, bool spaces);

class SimpleCalculator
{
private:

	string expression;

public:
	SimpleCalculator();
	void setExpression(string newString);
	string getExpression() const;
	void calculatorMenu();
	bool checkParenthesis(const string& expression);
};