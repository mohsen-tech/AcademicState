#include <iostream>
using namespace std;

int main()
{
	int a[100];
	cout << "Pls Enter n: ";
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Pls Enter Number " << i << ": ";
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[j] >= a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i+1] << "\t";
	}
	cout << "\n";
	return 0;
}