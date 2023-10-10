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
	stack<double> numbers;
	stack<char> operators;
	int number;

	cout << "\n\t1> Simple Calculator\n";
	cout << string(100, char(196)) << endl;

	calc.setExpression(inputString("\tType a fully parenthesized arithmetic expression:\n\n", true));

	/*cout << isdigit(calc.getExpression()[1]);

	number = calc.getExpression()[1];

	cout << number;*/

	if (checkParenthesis(calc.getExpression()))
	{
		cout << "fail";
	}
	else
	{
		cout << endl << displayCalculation(numbers, operators, calc.getExpression());
	}
	cout << endl;

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
double SimpleCalculator::displayCalculation(stack<double>& numbers, stack<char>& operators, const string& expression)
{
	const char RIGHT_PARENTHESIS = ')';
	const char DECIMAL = '.';
	double number;
	char operation;

	for (int i = 0; i < expression.size(); i++)
	{
		if (isdigit(expression[i]) || expression[i] == DECIMAL)
		{
			number = expression[i];
			numbers.push(number);
		}
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
		{
			operation = expression[i];
			operators.push(operation);
		}
		else if (expression[i] == RIGHT_PARENTHESIS)
		{
			evaluateExpression(numbers, operators);
		}
	}

	return numbers.top();
}
void SimpleCalculator::evaluateExpression(stack<double>& numbers, stack<char>& operators)
{
	double num1;
	double num2;

	num2 = numbers.top();
	numbers.pop();

	num1 = numbers.top();
	numbers.pop();

	switch (operators.top())
	{
	case '+':
	{
		numbers.push(num1 + num2);
	}
	break;
	case '-':
	{
		numbers.push(num1 - num2);
	}
	break;
	case '*':
	{
		numbers.push(num1 * num2);
	}
	break;
	case '/':
	{
		numbers.push(num1 / num2);
	}
	break;
	}

	operators.pop();
}