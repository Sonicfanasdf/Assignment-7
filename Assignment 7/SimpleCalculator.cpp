#include "SimpleCalculator.h"
#include<string>
#include<fstream>
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
	double answer;

	system("cls");
	cout << "\n\t1> Simple Calculator\n";
	cout << string(100, char(196)) << endl;

	//calc.setExpression(inputString("\tType a fully parenthesized arithmetic expression:\n\n", true));

	/*cout << isdigit(calc.getExpression()[1]);

	number = calc.getExpression()[1];

	cout << number;*/

	/*if (checkParenthesis(calc.getExpression()))
	{
		cout << "fail";
	}*/
	
	cout << "Type a parenthesized or non parenthesized arithmetic expression with postive integers or doubles:\n\n";
	
	displayCalculation(numbers, operators, cin, answer);
	
	

	
}
//bool SimpleCalculator::checkParenthesis(const string& expression)
//{
//	const char LEFT_PARENTHESIS = '(';
//	const char RIGHT_PARENTHESIS = ')';
//	stack<char> check;
//	char current;
//	bool fail = false;
//
//	if (expression[0] != LEFT_PARENTHESIS)
//	{
//		fail = true;
//	}
//
//	for (int i = 0; !fail && (i < expression.size()); i++)
//	{
//		current = expression[i];
//
//		if (current == LEFT_PARENTHESIS)
//		{
//			check.push(current);
//		}
//		else if (current == RIGHT_PARENTHESIS && !check.empty())
//		{
//			check.pop();
//		}
//		else if (current == RIGHT_PARENTHESIS && check.empty())
//		{
//			fail = true;
//		}
//	}
//
//	if (expression[expression.size() - 1] != RIGHT_PARENTHESIS)
//	{
//		fail = true;
//	}
//	else if (!check.empty())
//	{
//		fail = true;
//	}
//
//	return fail;
//}
void SimpleCalculator::displayCalculation(stack<double>& numbers, stack<char>& operators, istream& ins, double& answer)
{
	const char RIGHT_PARENTHESIS = ')';
	const char LEFT_PARENTHESIS = '(';
	const char DECIMAL = '.';
	double number;
	char operation;
	char parenthesis;
	stack<char> convert;
	stack<double> storage;
	ofstream outFile;
	int errorCtr = 0;
	int specialError = 0;
	
	double test;

	outFile.open("Store.txt");

	while (ins && ins.peek() != '\n')
	{

		if (ins.peek() == LEFT_PARENTHESIS)
		{
			ins >> parenthesis;
			convert.push(parenthesis);
		}
		else if (ins.peek() == ' ')
		{
			ins.ignore();
		}
		else if (isdigit(ins.peek()) || ins.peek() == DECIMAL)
		{
			ins >> number;
			storage.push(number);
			outFile << number << endl;

			//cout << "\n" << number << "\n";
		}
		else if (ins.peek() == '+' || ins.peek() == '-' || ins.peek() == '*' || ins.peek() == '/' || ins.peek() == '^')
		{
			ins >> operation;
			while (!convert.empty() && convert.top() != LEFT_PARENTHESIS && getPrecendence(convert.top()) > getPrecendence(operation))
			{
				outFile << convert.top() << endl;
				convert.pop();
			}

			convert.push(operation);

			//cout << "\n" << operation << "\n";
		}
		else if (ins.peek() == RIGHT_PARENTHESIS && !convert.empty())
		{
			ins.ignore();

			while (!convert.empty() && convert.top() != LEFT_PARENTHESIS  )
			{
				operation = convert.top();

				outFile << operation << endl;

				convert.pop();
			}
			if (convert.empty())
			{
				cout << "Unbalanced Parenthesis\n";
				++errorCtr;
				system("pause");
				system("cls");
			}
			else
			{
				convert.pop();
			}
		}
		else
		{
			cout << "Wrong input\n";
			++errorCtr;
			++specialError;
			system("pause");
			system("cls");
			while (ins.peek() != '\n')
			{
				ins.ignore();
			}
			break;
		}
	}
			while (!convert.empty() && convert.top() != LEFT_PARENTHESIS && specialError == 0)
			{
				operation = convert.top();

				outFile << operation << endl;

				convert.pop();
			}

			if (!convert.empty() && specialError == 0)
			{
				cout << "Not balanced\n";
				++errorCtr;
				system("pause");
				system("cls");
			}

			if (storage.size() <= 1 && specialError == 0)
			{
				cout << "Incorrect\n";
				++errorCtr;
				system("pause");
				system("cls");
			}
			
			
			if (errorCtr >= 1)
			{

			}
			else
			{
				evaluateExpression(numbers, operators);
				answer = numbers.top();

				cout << "\nThe Expression Evaluates to: " << answer << endl;
				system("pause");
				system("cls");
			}
				
			
			

			
	//		if (convert.top() == '+' || convert.top() == '-' || convert.top() == '*' || convert.top() == '/' || convert.top() == '^')
	//		{
	//			outFile << convert.top() << endl;
	//			convert.pop();

	//		}
	//		else if (convert.top() != '+' || convert.top() != '-' || convert.top() != '*' || convert.top() != '/' || convert.top() != '^')
	//		{
	//			cout << "\nNot enough operations\n";
	//			system("pause");
	//			system("cls");
	//			mainMenu();
	//		}
	//		if (!convert.empty() && convert.top() == LEFT_PARENTHESIS  )
	//		{
	//			if (convert.empty())
	//			{
	//				cout << "empty";
	//			}
	//			else
	//			{
	//				convert.pop();
	//			}
	//		}
	//		else
	//		{
	//			cout << "\nParenthesis are not balanced\n";
	//			system("pause");
	//			system("cls");
	//			mainMenu();
	//		}

	//		
	//	}
	//	else
	//	{
	//		cout << "\nNot inputed correctly\n";
	//		system("pause");
	//		system("cls");
	//		mainMenu();
	//	}
	//	
	//	
	//	
	//	

	//	
	//}

	//if (!convert.empty())
	//{
	//	cout << "\nParenthesis nots balanced\n";
	//	system("pause");
	//	system("cls");
	//	mainMenu();
	//}

	////inFile >> test;

	//outFile.close();
	////inFile.close();

	////cout << test;

	//evaluateExpression(numbers, operators);

	//answer = numbers.top();

	//cout << answer;

	//cout << endl;


	//system("pause");
	//system("cls");
}
void SimpleCalculator::evaluateExpression(stack<double>& numbers, stack<char>& operators)
{
	double num1;
	double num2;
	double answer;
	double storeNum;
	char storeOp;
	ifstream inFile;

	inFile.open("Store.txt");
	while (!inFile.eof())
	{
		if (isdigit(inFile.peek()))
		{
			inFile >> storeNum;
			numbers.push(storeNum);
		}
		else if (inFile.peek() == '\n')
		{
			inFile.ignore();
		}
		else if (inFile.peek() == '+' && numbers.size() >= 2)
		{
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();


			num1 = numbers.top();
			numbers.pop();


			numbers.push(num1 + num2);

		}
		else if (inFile.peek() == '-' && numbers.size() >= 2)
		{
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();


			num1 = numbers.top();
			numbers.pop();


			numbers.push(num1 - num2);
		}
		else if (inFile.peek() == '*' && numbers.size() >= 2)
		{
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();


			num1 = numbers.top();
			numbers.pop();


			numbers.push(num1 * num2);
		}
		else if (inFile.peek() == '/' && numbers.size() >= 2)
		{
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();


			num1 = numbers.top();
			numbers.pop();


			numbers.push(num1 / num2);
		}
		else if (inFile.peek() == '^' && numbers.size() >= 2)
		{
			inFile >> storeOp;

			num2 = numbers.top();
			numbers.pop();


			num1 = numbers.top();
			numbers.pop();


			numbers.push(pow(num1, num2));
		}
		else if( numbers.size() < 2 && !inFile.eof())
		{
			cout << "Not complete";
			break;
		}
	}


	inFile.close();

		/*if (isdigit(inFile.peek()))
		{
			inFile >> storeNum;
			numbers.push(storeNum);
		}
	
		cout << endl << storeNum;*/
	/*num2 = numbers.top();
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

	operators.pop();*/
}
int SimpleCalculator::getPrecendence(char operation)
{
	switch (operation)
	{
	case '+': return 1;
		break;
	case '-': return 1;
		break;
	case '*': return 2;
		break;
	case '/': return 2;
		break;
	case '^': return 3;
	}
}