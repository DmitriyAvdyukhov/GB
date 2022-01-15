#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <tuple>

#define SIZE 10
#define CHECK_NUMBER(a, b) ((a >= 0)&&(a < b))

namespace dz7
{
	template<typename T>
	void PrintArray(T ar[], const size_t size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			std::cout << ar[i] << " ";
		}
		std::cout << std::endl;
	}

	struct Value
	{
		int positeive = 0;
		int negateive = 0;
	};

	struct Employee
	{
		char name[SIZE];
		int age = 0;
		double stage = 0.;
	}; 

#pragma pack(push, 2)
	struct Employee1
	{
		char name[SIZE];
		int age = 0;
		double stage = 0.;
	};
#pragma pack(pop)	
	
	void PrintArray(const float ar[], const size_t size);

	void AddValueInArray(float arr[], const size_t size);

	Value CountElements(const float arr[], const size_t size);

	void AddValueInIntArray(int arr[], const size_t size);	

	void SwapInt(int& x, int& y);

#define SWAP_INT(a, b) dz7::SwapInt(a, b)

	void Sort(int arr[], const size_t size);
	
}
