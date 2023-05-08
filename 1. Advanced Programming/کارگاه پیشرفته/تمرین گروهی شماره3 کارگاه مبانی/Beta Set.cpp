#include <iostream>
#include <string>
using namespace std;
//----------------------------------------------------------------------------------------
class Set
{
public:
	Set()
	{
		a[0] = {};
	}
	//----------------------------------------------------------------------------------------
	Set(string name)
	{
		SetName(name);
	}
	//----------------------------------------------------------------------------------------
	void SetName(string name)
	{
		Name = name;
	}
	//----------------------------------------------------------------------------------------
	void Add() // Ezafe Krdn Ozv
	{
		int n;
		cerr << "Enter n Number To Add To List" << "(" << Name << ") : ";
		cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			cerr << i + 1 << ": ";
			cin >> a[size++];
		}
		Correct();
	}
	//----------------------------------------------------------------------------------------
	void Rmv() // Hazf Krdn Ozv
	{
		int x, sw = 0;
		cerr << "Enter Number To Remove From List" << "(" << Name << ") : ";
		cin >> x;
		for (size_t i = 0; i < size; i++)
		{
			if (a[i] == x)
			{
				sw = 1;
				for (size_t j = i; j < size; j++)
				{
					a[j] = a[j + 1];
				}
				size--;
			}
		}
		if (sw == 1)
			cerr << "Found Number And Remove\n";
		else
			cerr << "Not Found Number And Cant Remove\n";
	}
	//----------------------------------------------------------------------------------------
	void Search() // Control Krdn Vojod Ya Adam Vojod Ozv
	{
		int x, sw = 0;
		cerr << "Enter Number To Search It" << "(" << Name << ") : ";
		cin >> x;
		for (size_t i = 0; i < size; i++)
		{
			if (a[i] == x)
				sw = 1;
		}
		if (sw == 1)
			cerr << "Found Number\n";
		else
			cerr << "Not Found Number\n";
	}
	//----------------------------------------------------------------------------------------
	void Print() // Namayesh
	{
		cerr << Name << " = { ";
		for (size_t i = 0; i < size; i++)
		{
			if (i == size - 1)
				cerr << a[i];
			else
				cerr << a[i] << " , ";
		}
		cerr << " }\n";
	}
	//----------------------------------------------------------------------------------------
	void Correct() // Ijad MajmoE Bedon Tekrar Ozv
	{
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				if (a[i] == a[j])
				{
					for (size_t k = j; k < size; k++)
					{
						a[k] = a[k + 1];
					}
					size--;
					i = 0, j = 0;
				}
			}
		}
	}
	//----------------------------------------------------------------------------------------
	Set operator +(const Set & set) // Ejtema
	{
		static Set Result;

		int j = 0;
		for (size_t i = 0; i < size; i++)
		{
			Result.a[j++] = a[i];
		}
		for (size_t i = 0; i < set.size; i++)
		{
			Result.a[j++] = set.a[i];
		}
		Result.size = j;
		Result.Correct();

		cerr << "Summation Of " << Name << " & " << set.Name << " Is:\n";
		//Result.Print();

		return Result;
	}
	//----------------------------------------------------------------------------------------
	Set Subscription(const Set & set, Set & Result) // Eshterak
	{
		int k = 0;
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < set.size; j++)
			{
				if (a[i] == set.a[j])
				{
					Result.a[k++] = a[i];
				}
			}
		}
		Result.size = k;
		Result.Correct();

		cerr << "Subscription Of " << Name << " & " << set.Name << " Is:\n";
		Result.Print();

		return Result;
	}
	//----------------------------------------------------------------------------------------
	void Sort() // Morattab Sazi
	{
		int choose;
		cerr << "Choose One: \n1. UpWard Sorting\n2. DownWard Sorting\nEnter" << "(" << Name << ") : ";
		cin >> choose;
		if (choose == 1)
		{
			for (size_t i = 0; i < size; i++)
			{
				for (size_t j = i + 1; j < size; j++)
				{
					if (a[i] >= a[j])
					{
						swap(a[i], a[j]);
					}
				}
			}
			cerr << "UpWard Sorting Of " << Name << " Is:\n";
			Print();
		}
		else if (choose == 2)
		{
			for (size_t i = 0; i < size; i++)
			{
				for (size_t j = i + 1; j < size; j++)
				{
					if (a[i] <= a[j])
					{
						swap(a[i], a[j]);
					}
				}
			}
			cerr << "DownWard Sorting Of " << Name << " Is:\n";
			Print();
		}
		else
			cerr << ":-|\n";
	}
	//----------------------------------------------------------------------------------------
private:
	string Name;
	int a[100];
	int size = 0;
};
//----------------------------------------------------------------------------------------
void Ejtema()
{
	string Name;

	cerr << "Enter Name For Your List: ";
	cin >> Name;
	Set a(Name);
	a.Add();

	cerr << "Enter Name For Your List: ";
	cin >> Name;
	Set b(Name);
	b.Add();

	cerr << "Enter Name For Your List: ";
	cin >> Name;
	Set c(Name);
	c = a + b;
	c.SetName(Name);
	c.Print();
}
//----------------------------------------------------------------------------------------
void Eshterak()
{
	string Name;

	cerr << "Enter Name For Your List: ";
	cin >> Name;
	Set a(Name);
	a.Add();

	cerr << "Enter Name For Your List: ";
	cin >> Name;
	Set b(Name);
	b.Add();

	cerr << "Enter Name For Your List: ";
	cin >> Name;
	Set c(Name);
	c = a.Subscription(b, c);
}
//----------------------------------------------------------------------------------------
int main()
{
	string Name;

	cerr << "Enter Name For Your List: ";
	cin >> Name;
	Set s(Name);

	s.Add();
	s.Rmv();
	s.Search();
	s.Sort();
	s.Print();

	system("pause>0");
	return 0;
}