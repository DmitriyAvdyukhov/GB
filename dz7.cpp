#include "mylib.h"
#include <fstream>

using namespace std;
using namespace dz7;

namespace dz7
{
	void Task1_5()
	{
		float* fl = new float[SIZE];
		PrintArray(fl, SIZE);
		AddValueInArray(fl, SIZE);
		PrintArray(fl, SIZE);
		Value v = CountElements(fl, SIZE);
		cout << "Count positeive: "<< v.positeive << " Count negative: " << v.negateive << endl;
		delete[] fl;
	}

	void Task2()
	{
		cout << boolalpha << CHECK_NUMBER(5, 10) << endl;
	}

	void Task3()
	{
		int* arr = new int[SIZE];
		AddValueInIntArray(arr, SIZE);
		PrintArray(arr, SIZE);
		Sort(arr, SIZE);
		PrintArray(arr, SIZE);
	}

	void Task4()
	{
		Employee anna{ "Anna", 24, 4 };
		std::cout << "name: " << anna.name << " age: " << anna.age << " stage: " << anna.stage << std::endl;
		std::cout << "sizeof Emplooee= " << sizeof(anna) << std::endl;
		Employee1* pavel = new Employee1;
		*pavel = {"Pavel", 26, 6};
		std::cout << "name: " << pavel->name << " age: " << pavel->age << " stage: " << pavel->stage << std::endl;
		std::cout << "sizeof Emplooee1= " << sizeof(*pavel) << std::endl;
		ofstream out("employee.txt");
		out << "name: " << pavel->name << "\nage: " << pavel->age << "\nstage: " << pavel->stage << std::endl;
		delete pavel;
	}
}

int main() {

	dz7::Task1_5();
	dz7::Task3();
	dz7::Task4();
	return 0;
}