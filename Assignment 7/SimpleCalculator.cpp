#include "SimpleCalculator.h"
#include<string>
using namespace std;

SimpleCalculator::SimpleCalculator()
{
	expression = "";
}
void SimpleCalculator::setExpression(string newString)
{
	expression = newString;
}
string SimpleCalculator::getExpression() const
{
	return expression;
}
void SimpleCalculator::calculatorMenu()
{
	SimpleCalculator calc;

	cout << "\n\t1> Simple Calculator\n";
	cout << string(100, char(196)) << endl;

	calc.setExpression(inputString("\tType a fully parenthesized arithmetic expression:\n\n", true));

	cout << checkParenthesis(calc.getExpression());

	system("pause");
	system("cls");
}
bool SimpleCalculator::checkParenthesis(const string& expression)
{
	const char LEFT_PARENTHESIS = '(';
	const char RIGHT_PARENTHESIS = ')';
	stack<char> check;
	char current;
	bool fail = false;

	if (expression[0] != LEFT_PARENTHESIS)
	{
		fail = true;
	}

	for (int i = 0; !fail && (i < expression.size()); i++)
	{
		current = expression[i];

		if (current == LEFT_PARENTHESIS)
		{
			check.push(current);
		}
		else if (current == RIGHT_PARENTHESIS && !check.empty())
		{
			check.pop();
		}
		else if (current == RIGHT_PARENTHESIS && check.empty())
		{
			fail = true;
		}
	}

	if (expression[expression.size() - 1] != RIGHT_PARENTHESIS)
	{
		fail = true;
	}
	else if (!check.empty())
	{
		fail = true;
	}

	return fail;
}