#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long int a, b;
	int x[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a > b)
		{
			x[i] = 1;
		}
		else if (b > a)
		{
			x[i] = -1;
		}
		else if (a == b)
		{
			x[i] = 0;
		}

	}
	for (int i = 0; i < n; i++)
	{
		if (x[i] == 1)
		{
			cout << ">" << "\n";
		}
		else if (x[i] == -1)
		{
			cout << "<" << "\n";
		}
		else if (x[i] == 0)
		{
			cout << "=" << "\n";
		}
	}
	return 0;
}