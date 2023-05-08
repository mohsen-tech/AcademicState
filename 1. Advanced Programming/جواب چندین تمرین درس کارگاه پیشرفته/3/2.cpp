#include <iostream>
#include <string>
using namespace std;
// <in.txt> out.txt
struct Student {
	string name;
	float grades[5], avg;
};
int main()
{
	ios_base::sync_with_stdio(false);

	const int n = 10;
	Student students[n];
	for (int i = 0; i < n; i++)
	{
		cin >> students[i].name;
		float sum = 0;
		for (int j = 0; j < 5; j++)
		{
			cin >> students[i].grades[j];
			sum += students[i].grades[j];
		}
		students[i].avg = sum / 5;
	}
	float max = students[0].avg;
	int maxIndex = 0, maxIndex2;
	for (int i = 1; i < n; i++)
	{
		if (max < students[i].avg)
		{
			max = students[i].avg;
			maxIndex = i;
		}
	}
	max = -999999;
	for (int i = 1; i < n; i++)
	{
		if (max < students[i].avg && maxIndex != i)
		{
			max = students[i].avg;
			maxIndex2 = i;
		}
	}
	cout << students[maxIndex2].name << "\n";

	system("pause>0");
	return 0;
}