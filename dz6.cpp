#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ios>

using namespace std;

template<typename T>
void PrintArray(T ar[], const size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << ar[i] << " ";
	}
	std::cout << std::endl;
}

void AddValueInArray(int ar[], const size_t size)
{
	bool is_first = true;
	for (size_t i = 0; i < size; i++)
	{
		if (is_first)
		{
			ar[i] = 1;
			is_first = false;
		}
		else
		{
			ar[i] = ar[i - 1] * 2;
		}
	}
}

void Task1()
{
	size_t size = 0;
	cin >> size;
	int* ar = new int[size];

	AddValueInArray(ar, size);
	PrintArray(ar, size);

	delete[] ar;
}

int** CreateMatrix()
{
	const size_t size = 4;

	int** matrix = new int*[size];

	for (size_t i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}
	return matrix;
}

void AddValueMatrix(int* matrix[], const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			matrix[i][j] = rand();
		}
	}
}

void PrintMatrix(int* matrix[], const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		PrintArray(matrix[1], size);
	}
}

void DeleteMatrix(int* matrix[], const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		delete [] matrix[i];
	}	
	delete[] matrix;
}

void Task2()
{
	int** matrix = CreateMatrix();
	AddValueMatrix(matrix, 4);
	PrintMatrix(matrix, 4);
	DeleteMatrix(matrix, 4);
	matrix = nullptr;
}

string CreateFile()
{
	cout << "Enter name your file" << endl;
	string name;
	cin >> name;
	ofstream of(name);
	
	return name;
}

void AddValueInFile(const string& name)
{
	ofstream of(name);
	if (of)
	{
		string value;
		cout << "Please enter your value of string" << endl;
		cin >> ws;
		getline(cin, value);
		of << value << endl;
	}
}

void AddConntent(ofstream& out, const string& name_file)
{
	ifstream in(name_file);
	if(in)
	{
		while (in)
		{
			string temp;
			in >> ws;
			getline(in, temp);
			out << temp << endl;
		}
	}
}

void MergeFiles(const string& merge, const string& name1, const string& name2)
{
	ofstream out(merge, ios::app);
	
	if (out)
	{
		AddConntent(out, name1);
		AddConntent(out, name2);
	}

}

void PrintFile(const string& name_file)
{
	ifstream in(name_file);
	if (in)
	{
		while (in)
		{
			string temp;
			in >> ws;
			getline(in, temp);
			if (temp.length())
			{
				cout << temp << endl;
			}
		}
	}
}

bool CheckWord(const string& word, const string& name_file)
{	
	ifstream in(name_file);
	if (in)
	{
		while (in)
		{
			in >> ws;
			string temp;
			getline(in, temp);
			if (temp.find(word) != string::npos)
			{
				return true;
			}
		}
	}
	return false;
}

void Task3_4()
{
	string name_file_1 = CreateFile();
	AddValueInFile(name_file_1);
	PrintFile(name_file_1);

	string name_file_2 = CreateFile();
	AddValueInFile(name_file_2);
	PrintFile(name_file_2);

	string merge = CreateFile();
	MergeFiles(merge, name_file_1, name_file_2);
	PrintFile(merge);	
}

void Task5()
{
	string word;
	cin >> word;
	string name_file;
	cin >> name_file;
	cout << boolalpha << CheckWord(word, name_file) << endl;
}

int main() {

	Task1();
	Task2();
	Task3_4();
	Task5();

	return 0;
}