#include <iostream>
using namespace std;
int main()
{
	int n, m, a[100][100], s, k = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int j = 0; j < m; j++)
	{
		s = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i][j] == 0)
				s++;
		}
		if (s == n)
			k++;
	}
	cout << k;
	return 0;
}