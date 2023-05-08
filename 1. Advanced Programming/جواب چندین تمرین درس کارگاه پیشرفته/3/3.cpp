#include <iostream>
#include <string>
#include <vector>
using namespace std;
// <in.txt> out.txt
struct Person {
	string name;
	int melliCode, year;
};
int main()
{
	ios_base::sync_with_stdio(false);

	vector <Person> persons;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Person temp;
		cin >> temp.name >> temp.melliCode >> temp.year;
		persons.push_back(temp);
	}
	for (int i = 0; i < persons.size(); i++) // bakhshe aval
	{
		if (90 <= persons[i].year % 100 && persons[i].year % 100 <= 99)
		{
			cout << persons[i].name << "\n";
		}
	}
	for (int i = 0; i < persons.size(); i++) // bakhshe dovom
	{
		if (persons[i].name[0] == 'A' && persons[i].year % 100 == 92)
		{
			cout << persons[i].name << " " << persons[i].melliCode << " " << persons[i].year << "\n";
		}
	}
	for (int i = 0; i < persons.size(); i++) // bakhshe sevom
	{
		if (persons[i].melliCode % 100 == 23)
		{
			cout << persons[i].name << " " << persons[i].melliCode << " " << persons[i].year << "\n";
		}
	}

	system("pause>0");
	return 0;
}