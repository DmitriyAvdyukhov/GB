#include <iostream>
#include "tic_tac_toy.h"

using namespace std;



using MyVariant = struct
{
	union Union
	{
		int x;
		float f;
		char ch;
	}data;

	int is_int : 1;
	int is_float : 1;
	int is_char : 1;
};


int main(int argc, char* argv[])
{
	
	MyVariant v;
	v.data.ch = 'd';
	v.is_int = 0;
	v.is_float = 0;
	v.is_char = 1;

	cout << v.data.ch << endl;
	cout << v.data.x << endl;
	cout << v.data.f << endl;

	GameStart();
}