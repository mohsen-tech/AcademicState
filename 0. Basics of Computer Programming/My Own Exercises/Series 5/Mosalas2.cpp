#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
			if (j == 0)
				cout << "*";
			else if (j == i)
				cout << "*";
			else
				cout << " ";

		cout << endl;
	}
	for (int i = n; i <= 2 * n; i++)
	{
		for (int j = i; j <= 2 * n; j++)
			if (j == i)
				cout << "*";
			else if (j == 2 * n)
				cout << "*";
			else
				cout << " ";
		cout << endl;
	}
	return 0;
}