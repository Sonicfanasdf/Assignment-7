#include "SimpleCalculator.h"
#include<string>
#include<fstream>
using namespace std;

//Default Constructor
//Precondition: NA
//PostCondition: NA
SimpleCalculator::SimpleCalculator()
{
	
}
//Precondition: NA
//Postcondition: Displays Calculator Menu
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
	
	cout << "Type a parenthesized or non parenthesized arithmetic expression with postive integers or doubles:\n\n";
	
	displayCalculation(numbers, cin, answer);
	
	

	
}
//Precondition: A stack of doubles, user input with numbers that are positive, a double answer
//Postcondition: Displays expression result
void SimpleCalculator::displayCalculation(stack<double>& numbers, istream& ins, double& answer)
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

		}
		else if (ins.peek() == '+' || ins.peek() == '-' || ins.peek() == '*' || ins.peek() == '/' || ins.peek() == '^')
		{
			ins >> operation;
			while (!convert.empty() && convert.top() != LEFT_PARENTHESIS && getPrecendence(convert.top()) >= getPrecendence(operation))
			{
				outFile << convert.top() << endl;
				convert.pop();
			}

			convert.push(operation);

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
				cout << "ERROR: Unbalanced Parenthesis\n";
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
			cout << "ERROR: Incorrect Expression Input\n";
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
				cout << "ERROR: Unbalanced Parenthesis\n";
				++errorCtr;
				system("pause");
				system("cls");
			}

			if (storage.size() <= 1 && specialError == 0)
			{
				cout << "ERROR: Incorrect Expression Input\n";
				++errorCtr;
				system("pause");
				system("cls");
			}
			
			
			if (errorCtr >= 1)
			{

			}
			else
			{
				evaluateExpression(numbers);
				answer = numbers.top();

				cout << "\nThe Expression Evaluates to: " << answer << endl;
				system("pause");
				system("cls");
			}
}
//Precondition:A stack of doubles for numbers
//Postcondition: evaluates expression
void SimpleCalculator::evaluateExpression(stack<double>& numbers)
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
			cout << "ERROR: Incorrect input must be postive numbers\n\n";
			system("pause");
			system("cls");
			mainMenu();
			break;
		}
	}


	inFile.close();

}
//Precondition: a char operator
//Postcondition: returns precendence value;
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