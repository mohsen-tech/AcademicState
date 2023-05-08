#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n, a[100][100], Asli = 0, FarE = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
		Asli = Asli + a[i][i];

	for (int i = 0; i < n; i++)
		FarE = FarE + a[i][n - 1 - i];

	cout << Asli - FarE;
	return 0;
}