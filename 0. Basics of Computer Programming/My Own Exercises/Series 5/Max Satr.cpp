#include <iostream>
using namespace std;
int main()
{
	int n, m, a[100][100], sum, max = -9999999, s;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum = sum + a[i][j];
		}
		if (sum >= max)
		{
			max = sum;
			s = i;
		}
	}
	for (int j = 0; j < m; j++)
		cout << a[s][j] << " ";
	return 0;
}