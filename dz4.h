#pragma once
#include <iostream>

//tas 1
void CheckSum()
{
	int a = 0, b = 0;
	std::cin >> a >> b;
	if ((a + b) >= 10 && (a + b) <= 20)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}
}

//task 2
void CheckDec()
{
	int a, b = 0;
	std::cin >> a >> b;
	if ((a == 10 && b == 10) || (a + b) == 10)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}
}

//task 3 
void PrintOddNumbers()
{
	int number = 0;
	std::cin >> number;
	int i = 0;
	std::cout << "Your odd numbers: ";
	while (i < number)
	{		
		if (i % 2 != 0)
		{
			std::cout << i << " ";
		}
		++i;
	}
	std::cout << std::endl;
}

//task 4
void CheckNaturalNumber()
{
	int x = 0;
	std::cin >> x;
	int result = 0;
	for (int i = 1; i <= x; ++i)
	{
		if (x % i == 0)
		{
			++result;
		}
	}
	if (result == 2)
	{
		std::cout << "this number is natural" << std::endl;
	}
	else
	{
		std::cout << "this number is not  natural" << std::endl;
	}
}

//task 5
bool CheckYear(int x)
{
	if (x % 4 == 0)
	{
		if (x % 100 == 0 && x % 400 != 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

void PrintCheckYear()
{
	int year = 0;
	std::cin >> year;
	if (year > 0 && year <= 3000)
	{
		bool leap = CheckYear(year);
		if (leap)
		{
			std::cout << "this year is leap year" << std::endl;
		}
		else
		{
			std::cout << "this year is not leap year" << std::endl;
		}
	}
	else {
		std::cout << "You input incorrect value" << std::endl;
	}
}
//the end task 5



struct Matrix
{
	Matrix()
	{
		for (int i = 0; i < side; ++i)
		{
			for (int j = 0; j < side; ++j)
			{
				matrix[i][j] = 0;
			}
		}
	}
	const static int side = 7;
	int matrix[side][side];
};

void PrintMatrix(const Matrix& m)
{
	for (int i = 0; i < m.side; ++i)
	{
		for (int j = 0; j < m.side; ++j)
		{
			std::cout << m.matrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void CreateMatrixDiagonal(Matrix& m)
{
	for (int i = 0; i < m.side; ++i)
	{
		m.matrix[i][i] = 1;
	}
}

void PrintDiagonal()
{
	Matrix m;
	PrintMatrix(m);
	CreateMatrixDiagonal(m);
	PrintMatrix(m);
}

