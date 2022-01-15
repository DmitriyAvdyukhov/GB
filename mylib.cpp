#include "mylib.h"


namespace dz7
{	
	void PrintArray(const float ar[], const size_t size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			std::cout << ar[i] << " ";
		}
		std::cout << std::endl;
	}

	void AddValueInArray(float arr[], const size_t size)
	{
		const float first = -10000.;
		const float last = 10000.;
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = (float)(rand()) / RAND_MAX * (first - last) + last;
		}
	}

	Value CountElements(const float arr[], const size_t size)
	{
		Value value;
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] > 0)
			{
				++value.positeive;
			}
			else
			{
				++value.negateive;
			}
		}
		return value;
	}
	void AddValueInIntArray(int arr[], const size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			int value;
			std::cin >> value;
			arr[i] = value;
		}
	}
	void SwapInt(int& x, int& y)
	{
		if (x > y)
		{
			int c = x;
			x = y;
			y = c;
		}
	}
	void Sort(int arr[], const size_t size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = 0; j < size - 1; ++j)
			{
				if (arr[j] > arr[j + 1])
				{
					SWAP_INT(arr[j], arr[j + 1]);					
				}
			}
		}
	}
}