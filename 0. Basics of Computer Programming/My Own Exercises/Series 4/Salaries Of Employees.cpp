#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a, b, l;
	int x[20];
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> l;
		if (a > b&&b > l)
		{
			x[i] = b;
		}
		else if (l >= b&&b >= a)
		{
			x[i] = b;
		}
		else if (b >= a&&a >= l)
		{
			x[i] = a;
		}
		else if (a >= l&&l >= b)
		{
			x[i] = l;
		}
		else if (l >= a&&a >= b)
		{
			x[i] = a;
		}
		else if (b >= l&&l >= a)
		{
			x[i] = l;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "Case " << i << ": " << x[i - 1] << endl;
	}
	return 0;
}