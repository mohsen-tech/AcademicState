#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
int Size = 0;
//----------------------------------------------------------------------------------------
class Set
{
public:
	Set()
	{
		size = 0;
		a = new int[size];
		Name = "";
	}
	~Set()
	{
		delete[] a;
	}
	//----------------------------------------------------------------------------------------
	void SetName(string name)
	{
		Name = name;
	}
	string getName() const
	{
		return Name;
	}
	//----------------------------------------------------------------------------------------
	void Add()
	{
		int n;
		cerr << "Enter n Number To Add To List" << "(" << Name << ") : ";
		cin >> n;
		int * temp = new int[size + n];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = a[i];
		}
		delete[] a;
		for (size_t i = 0; i < n; i++)
		{
			cerr << i + 1 << ": ";
			cin >> temp[size++];
		}
		a = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			a[i] = temp[i];
		}
		delete[] temp;
		Correct();
	}
	//----------------------------------------------------------------------------------------
	void Rmv()
	{
		int * temp = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = a[i];
		}
		delete[] a;
		int x, sw = 0;
		cerr << "Enter Number To Remove From List" << "(" << Name << ") : ";
		cin >> x;
		for (size_t i = 0; i < size; i++)
		{
			if (temp[i] == x)
			{
				sw = 1;
				for (size_t j = i; j < size; j++)
				{
					temp[j] = temp[j + 1];
				}
				size--;
			}
		}
		a = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			a[i] = temp[i];
		}
		delete[] temp;
		if (sw == 1)
			cerr << "Found Number And Remove\n";
		else
			cerr << "Not Found Number And Cant Remove\n";
	}
	//----------------------------------------------------------------------------------------
	void Search()
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
	void Print()
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
	void Correct()
	{
		int * temp = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = a[i];
		}
		delete[] a;
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				if (temp[i] == temp[j])
				{
					for (size_t k = j; k < size; k++)
					{
						temp[k] = temp[k + 1];
					}
					size--;
					i = 0, j = 0;
				}
			}
		}
		a = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			a[i] = temp[i];
		}
		delete[] temp;
	}
	//----------------------------------------------------------------------------------------
	Set operator +(const Set & set)
	{
		Set * Result = new Set;
		int length = size + set.size;
		delete[] Result->a;
		Result->a = new int[length];
		int j = 0;
		for (size_t i = 0; i < size; i++)
		{
			Result->a[j++] = a[i];
		}
		for (size_t i = 0; i < set.size; i++)
		{
			Result->a[j++] = set.a[i];
		}
		Result->size = j;
		Result->Correct();
		cerr << "Summation Of " << Name << " & " << set.Name << " Is:\n";
		return *Result;
	}
	//----------------------------------------------------------------------------------------
	const Set & operator=(const Set & right)
	{
		if (size != right.size)
		{
			delete[] a;
			size = right.size;
			a = new int[size];
		}
		for (size_t i = 0; i < size; i++)
			a[i] = right.a[i];
		return *this;
	}
	//----------------------------------------------------------------------------------------
	void Subscription(const Set & setA, const Set & setB)
	{
		int k = 0;
		delete[]a;
		int * temp = new int[setA.size + setB.size];
		for (size_t i = 0; i < setA.size; i++)
		{
			for (size_t j = 0; j < setB.size; j++)
			{
				if (setA.a[i] == setB.a[j])
				{
					temp[k++] = setA.a[i];
				}
			}
		}
		a = new int[k];

		for (size_t i = 0; i < k; i++)
		{
			a[i] = temp[i];
		}
		delete[] temp;
		size = k;
		Correct();
		cerr << "Subscription Of " << setA.Name << " & " << setB.Name << " Is:\n";
	}
	//----------------------------------------------------------------------------------------
	void Sort()
	{
		int choose;
		cerr << "Choose One: \n1. UpWard Sorting\n2. DownWard Sorting\nEnter" << "(" << Name << ") : ";
		cin >> choose;
		if (choose == 1)
		{
			for (size_t i = 0; i < size; i++)
				for (size_t j = i + 1; j < size; j++)
					if (a[i] >= a[j])
						swap(a[i], a[j]);
			cerr << "UpWard Sorting Of " << Name << " Is:\n";
			Print();
		}
		else if (choose == 2)
		{
			for (size_t i = 0; i < size; i++)
				for (size_t j = i + 1; j < size; j++)
					if (a[i] <= a[j])
						swap(a[i], a[j]);
			cerr << "DownWard Sorting Of " << Name << " Is:\n";
			Print();
		}
		else
			cerr << ":-|\n";
	}
	//----------------------------------------------------------------------------------------
private:
	string Name;
	int * a;
	int size;
};
Set set[100];
//----------------------------------------------------------------------------------------
void CreateSubset()
{
	string Name;
	cerr << "Subset Name: ";
	cin >> Name;
	bool sw = true;
	for (size_t i = 0; i < 100 && sw; i++)
		if (set[i].getName() == Name)
			sw = false;
	if (sw)
	{
		set[Size].SetName(Name);
		set[Size++].Add();
	}
	else cerr << "Cant Create <Name Is Recurrent>\n";
}
//----------------------------------------------------------------------------------------
void AddMember()
{
	string Name;
	cerr << "Enter Subset Name: ";
	cin >> Name;
	int Index = -1;
	for (size_t i = 0; i < Size && Index == -1; i++)
		if (set[i].getName() == Name)
			Index = i;
	if (Index != -1)
	{
		set[Index].Add();
	}
	else cerr << "Cant Add <Name Not Found>\n";
}
//----------------------------------------------------------------------------------------
void RemoveMember()
{
	string Name;
	cerr << "Enter Subset Name: ";
	cin >> Name;
	int Index = -1;
	for (size_t i = 0; i < Size && Index == -1; i++)
		if (set[i].getName() == Name)
			Index = i;
	if (Index != -1)
	{
		set[Index].Rmv();
	}
	else cerr << "Cant Remove <Name Not Found>\n";
}
//----------------------------------------------------------------------------------------
void SearchMember()
{
	string Name;
	cerr << "Enter Subset Name: ";
	cin >> Name;
	int Index = -1;
	for (size_t i = 0; i < Size && Index == -1; i++)
		if (set[i].getName() == Name)
			Index = i;
	if (Index != -1)
	{
		set[Index].Search();
	}
	else cerr << "Cant Search <Name Not Found>\n";
}
//----------------------------------------------------------------------------------------
void CalculateSummation()
{
	cerr << "Sample --> A + B = C\n\n";
	string NameA, NameB, NameC;
	cerr << "Enter Subset NameA: ";
	cin >> NameA;
	cerr << "Enter Subset NameB: ";
	cin >> NameB;
	cerr << "Enter Subset NameC: ";
	cin >> NameC;
	int IndexA = -1, IndexB = -1, IndexC = -1;

	for (size_t i = 0; i < Size && IndexA == -1; i++)
		if (set[i].getName() == NameA)
			IndexA = i;
	for (size_t i = 0; i < Size && IndexB == -1; i++)
		if (set[i].getName() == NameB)
			IndexB = i;
	for (size_t i = 0; i < Size && IndexC == -1; i++)
		if (set[i].getName() == NameC)
			IndexC = i;
	if (IndexA != -1 && IndexB != -1 && IndexC != -1)
	{
		set[IndexC] = set[IndexA] + set[IndexB];
		set[IndexC].Print();
	}
	else cerr << "Cant Calculate Summation <Name Not Found>\n";
}
//----------------------------------------------------------------------------------------
void CalculateSubscription()
{
	cerr << "Sample --> A - B = C\n\n";
	string NameA, NameB, NameC;
	cerr << "Enter Subset NameA: ";
	cin >> NameA;
	cerr << "Enter Subset NameB: ";
	cin >> NameB;
	cerr << "Enter Subset NameC: ";
	cin >> NameC;
	int IndexA = -1, IndexB = -1, IndexC = -1;
	for (size_t i = 0; i < Size && IndexA == -1; i++)
		if (set[i].getName() == NameA)
			IndexA = i;
	for (size_t i = 0; i < Size && IndexB == -1; i++)
		if (set[i].getName() == NameB)
			IndexB = i;
	for (size_t i = 0; i < Size && IndexC == -1; i++)
		if (set[i].getName() == NameC)
			IndexC = i;
	if (IndexA != -1 && IndexB != -1 && IndexC != -1)
	{
		set[IndexC].Subscription(set[IndexA], set[IndexB]);
		set[IndexC].Print();
	}
	else cerr << "Cant Calculate Subscription <Name Not Found>\n";
}
//----------------------------------------------------------------------------------------
void SortSubset()
{
	string Name;
	cerr << "Enter Subset Name: ";
	cin >> Name;
	int Index = -1;
	for (size_t i = 0; i < Size && Index == -1; i++)
		if (set[i].getName() == Name)
			Index = i;
	if (Index != -1)
	{
		set[Index].Sort();
	}
	else cerr << "Cant Sort <Name Not Found>\n";
}
//----------------------------------------------------------------------------------------
void ShowSubset()
{
	string Name;
	cerr << "Enter Subset Name: ";
	cin >> Name;
	int Index = -1;
	for (size_t i = 0; i < Size && Index == -1; i++)
		if (set[i].getName() == Name)
			Index = i;
	if (Index != -1)
	{
		set[Index].Print();
	}
	else cerr << "Cant Show <Name Not Found>\n";
}
//----------------------------------------------------------------------------------------
void Run()
{
	while (!false)
	{
		int choose;
		cerr << "1.Create New Subset\n\n";
		cerr << "2.Set New Member\n\n";
		cerr << "3.Remove Member From Subset\n\n";
		cerr << "4.Search Member In Subset\n\n";
		cerr << "5.Calculate Summation\n\n";
		cerr << "6.Calculate Subscription\n\n";
		cerr << "7.Sort Subset\n\n";
		cerr << "8.Show Subset\n\n";
		cerr << "9.Exit\n\n";
		cerr << "Choose One: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			system("cls");
			CreateSubset();
			_getch();
			system("cls");
			break;
		case 2:
			system("cls");
			AddMember();
			_getch();
			system("cls");
			break;
		case 3:
			system("cls");
			RemoveMember();
			_getch();
			system("cls");
			break;
		case 4:
			system("cls");
			SearchMember();
			_getch();
			system("cls");
			break;
		case 5:
			system("cls");
			CalculateSummation();
			_getch();
			system("cls");
			break;
		case 6:
			system("cls");
			CalculateSubscription();
			_getch();
			system("cls");
			break;
		case 7:
			system("cls");
			SortSubset();
			_getch();
			system("cls");
			break;
		case 8:
			system("cls");
			ShowSubset();
			_getch();
			system("cls");
			break;
		case 9:
			system("cls");
			exit(0);
			break;
		default:
			return;
			break;
		}
	}
}
//----------------------------------------------------------------------------------------
int main()
{
	Run();
	system("pause>0");
	return 0;
}