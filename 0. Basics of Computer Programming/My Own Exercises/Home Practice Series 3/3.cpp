#include <iostream>
using namespace std;
int main()
{
	int n, m, a[100][100], sum = 0, avg, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
	{
		int max = -999999;
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] > max)
				max = a[i][j];
		}
		cout << "Max Satr " << i << ": " << max << endl;
		sum = sum + max;
	}
	avg = sum / n;
	cout << "Avg Matrix: " << avg << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] < avg)
				cnt++;
	cout << cnt << endl;
	return 0;
}