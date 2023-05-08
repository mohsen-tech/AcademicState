#include <iostream>
#include <fstream>
#define size 100
using namespace std;
struct sort
{
	char name[size];
	int score;
};
int main()
{
	int n = 5;
	sort a[size];
	fstream Output_file("sort.txt", ios::out);
	fstream Input_file("sort.txt", ios::in);

	for (int i = 0; i < n; i++)
		cin >> a[i].name >> a[i].score;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].score >= a[j].score)
				swap(a[i], a[j]);

	if (Output_file.fail())
	{
		cout << "Error";
		return 0;
	}

	for (int i = 0; i < n; i++)
		Output_file << a[i].name << " " << a[i].score << endl;

	for (int i = 0; i < n; i++)
	{
		Input_file >> a[i].name >> a[i].score;
		cout << endl << a[i].name << " " << a[i].score << endl;
	}

	return 0;
}