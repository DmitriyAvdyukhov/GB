#include <iostream>
#include <ios>

template<typename T>
void Print(T ar[], int size)
{
	for (int i =0; i<size;++i)
	{
		std::cout<<ar[i]<<" ";
	}
	std::cout<<std::endl;
}


void ChangeValue(int ar[], int size)
{
	for(int i=0; i<size; ++i)
	{
		ar[i]=!(ar[i]);
	}
}

void AddValue(int ar[], int size)
{
	for(int i=0; i<size; ++i)
	{
		ar[i] = 1 + i * 3;
	}
}

template<typename T>
void Shift(T ar[], int size, int shift)
{
	shift %= size;
	 int value_shift = size + shift;
	 value_shift %= size;
	for(int i=0; i < value_shift; ++i)
	{
		T temp = ar[size -1];
		for(int j = size-1; j > 0; --j)
		{
			ar[j]=ar[j-1];
		}
		ar[0]=temp;
	}
}

bool IsBalance(int ar[], int size)
{
	int lsum = 0, rsum = 0;
	int lbound = 0, rbound = size;
	while (lbound != rbound)
	{
		if (lsum > rsum)
		{
			rsum += ar[--rbound];
			std::cout << "rsum " << rsum << std::endl;
		}
		else
		{
			lsum += ar[lbound++];
			std::cout << "lsum " << lsum << std::endl;
		}
	}
	return lsum == rsum;
}

int main(int argc, char *argv[])
{
	//task1 print an array of double
	double ar_d [] = { 1.6, 2.5, 3.4,4.5,5.6,6.7,7.7 };
	Print(ar_d, 7);
	std::cout << std::endl;

	//task2 chenge a value in array
	int ar_ch [] ={ 1, 0, 0, 0, 1, 1, 0, 1, 0, 1 };
	Print(ar_ch, 10);
	ChangeValue(ar_ch, 10);
	Print(ar_ch, 10);
	std::cout << std::endl;

	//task3 add value in clear array
	int ar_v [] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	AddValue(ar_v, 8);
	Print(ar_v, 8);
	std::cout << std::endl;

	//task4 shift a value in array
	int ar_sh [] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	Print(ar_sh, 10);
	Shift(ar_sh, 10, 3);
	Print(ar_sh, 10);
	std::cout << std::endl;

	//task5 check an array fo balance
	int ar []={1,1,1,2,1};
	Print(ar, 5);
	std::cout << std::boolalpha << IsBalance(ar,5) << std::endl;
	
	int ar1 [] = { 2, 1, 1, 2, 1 };
	Print(ar1, 5);
	std::cout << std::boolalpha << IsBalance(ar1, 5) << std::endl;
	
	int ar2 [] = { 10, 1, 2, 3, 4 };
	Print(ar2, 5);
	std::cout << std::boolalpha << IsBalance(ar2, 5) << std::endl;

	return 0;
}