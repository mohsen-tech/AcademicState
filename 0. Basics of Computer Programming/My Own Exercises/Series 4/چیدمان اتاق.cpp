#include<iostream>
using namespace std;
int main()
{
	unsigned long long s, a[1000];
	int n, k = 0;
	cin >> n;
	if (n > 0)
	{
		for (int i = 0;n > 0; i++)
		{
			s = 1;
			for (int j = 1; j <= n; j++)
			{
				s = s*j;
			}
			a[i] = s;
			k++;
			cin >> n;
		}
		for (int i = 0; i <= k - 1; i++)
		{
			cout << a[i] << "\n";
		}
	}
	return 0;
}