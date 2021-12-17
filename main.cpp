#include <iostream>
#include "tic_tac_toe.h"
#include"dz2.h"

using namespace std;






int main(int argc, char* argv[])
{
	//tic_tac_toe::GameStart();

	//--------------dz2------------
	{
		MyVariant v;
		v.data.ch = 'd';
		v.is_int = 0;
		v.is_float = 0;
		v.is_char = 1;

		cout << v.data.ch << endl;
		cout << v.data.x << endl;
		cout << v.data.f << endl;
	}
	//-------------dz3----------------
	{
		//task 2
		{
			int x = 0;
			//cin >> x;
			const int number = 21;
			cout << (x <= number ? number - x : (x - number) * 2) << endl;
		}
		//task3
		{
			int arr[3][3][3] = 
			{
				{{{1},{2},{3}},{{4},{5},{6}},{{7},{8},{9}}}
				,{{{11},{12},{13}},{{14},{15},{16}},{{17},{18},{19}}}
				,{{{21},{22},{23}},{{24},{25},{26}},{{27},{28},{29}}}
			};
			int (*ptr)[3][3] = arr;
			cout << (*ptr[1][1] + 1) << endl;
			cout << arr[1][1][1] << endl << endl;
		}
		//task 1-4
		{
			extern int a; // объ€вленны в файле tic_tac_toe.cpp
			extern int b;
			extern int c;
			extern int d;
			
			cout << a * (b + (c / static_cast<double>(d))) << endl;
		}

	}
	return 0;
}