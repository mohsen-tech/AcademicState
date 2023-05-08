#include <iostream>
#include <string>
using namespace std;
// <in.txt> out.txt
struct Student {
	string name;
	int ID;
	float grade;
};
int main()
{
	ios_base::sync_with_stdio(false);

	const int n = 10;
	Student students[n];
	for (int i = 0; i < n; i++)
	{
		cin >> students[i].name >> students[i].ID >> students[i].grade;
	}
	float max = students[0].grade;
	int maxIndex = 0;
	for (int i = 1; i < n; i++)
	{
		if (max < students[i].grade)
		{
			max = students[i].grade;
			maxIndex = i;
		}
	}
	cout << students[maxIndex].name << " " << students[maxIndex].ID << "\n";

	system("pause>0");
	return 0;
}