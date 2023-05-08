#include <iostream>
using namespace std;
int main()
{
	int a, b, c = 25;
	for (a = 1; a <= 25; a++)
	{
		for (b = 1; b <= 25; b++)
		{
			if (b < c - a && b >= a)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}