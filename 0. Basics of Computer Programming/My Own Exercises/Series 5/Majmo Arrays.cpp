#include <iostream>
using namespace std;
int main()
{
	int m, a[100][100], sum;
	cin >> m;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int j = 0; j < m; j++)
	{
		sum = 0;
		for (int i = 0; i < 2; i++)
			sum = sum + a[i][j];
		cout << sum << " ";
	}
	return 0;
}