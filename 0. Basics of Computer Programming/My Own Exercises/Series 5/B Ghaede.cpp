#include <iostream>
using namespace std;
int main()
{
	int n, a[100], b;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (a[0] > a[1])
	{
		for (int i = 1; i < n - 1; i++)
		{
			if (a[i] < a[i + 1])
			{
				b = 0;
				break;
			}
			else
				b = 1;
		}
	}
	else if (a[0] < a[1])
	{
		for (int i = 1; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				b = 0;
				break;
			}
			else
				b = 2;
		}
	}

	if (b == 0)
		cout << "Irregular";
	else if (b == 1)
		cout << "Descending";
	else if (b == 2)
		cout << "Ascending";

	return 0;
}