#include <iostream>
#include <string>
#include <algorithm>
#define N 7
using namespace std;
void LIS(int * X, int * Y, int result[N + 1][N + 1])
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (X[i - 1] == Y[j - 1])
			{
				result[i][j] = 1 + result[i - 1][j - 1];
			}
			else if (result[i - 1][j] > result[i][j - 1])
			{
				result[i][j] = result[i - 1][j];
			}
			else
			{
				result[i][j] = result[i][j - 1];
			}
		}
	}
}
int main()
{
	int X[N] = { 7 , 1 , 8 , 3 , 6 , 10 , 2 },
		Y[N] = { 7 , 1 , 8 , 3 , 6 , 10 , 2 },
		result[N + 1][N + 1] = { 0 };
	sort(Y, Y + N);

	LIS(X, Y, result);
	cout << result[N][N];

	system("pause>0");
	return 0;
}