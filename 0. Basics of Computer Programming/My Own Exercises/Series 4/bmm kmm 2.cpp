#include<iostream>
using namespace std;
int main()
{
	long long int n, m, bmm, kmm;
	cin >> n >> m;
	for (int i = 1, j = 1; i <= n, j <= m; i++, j++)
	{
		if (n%i == 0 && m%j == 0)
		{
			if (i == j)
			{
				bmm = j;
			}
		}
	}
	kmm = n*m / bmm;
	cout << bmm << " " << kmm;
	return 0;
}