#include<iostream>
using namespace std;
int main()
{
	int n, m, s = 0;
	cin >> n >> m;
	for (int j = 1; j <= n; j++)
	{
		for (int i = -10; i <= m; i++)
		{
			s = s + ((i + j)*(i + j)*(i + j)) / (j*j);
		}
	}
	cout << s;
	return 0;
}