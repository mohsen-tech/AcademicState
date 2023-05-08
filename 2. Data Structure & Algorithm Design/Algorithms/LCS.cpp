#include <iostream>
#include <string>
#define N 7
#define M 10
using namespace std;
void LCS(int * X, int * Y, int result[N + 1][M + 1], int path[N + 1][M + 1])
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (X[i - 1] == Y[j - 1])
			{
				result[i][j] = 1 + result[i - 1][j - 1];
				path[i][j] = 3;
			}
			else if (result[i - 1][j] > result[i][j - 1])
			{
				result[i][j] = result[i - 1][j];
				path[i][j] = 1;
			}
			else if (result[i - 1][j] < result[i][j - 1])
			{
				result[i][j] = result[i][j - 1];
				path[i][j] = -1;
			}
			else
			{
				result[i][j] = result[i][j - 1];
				path[i][j] = 2;
			}
		}
	}
}
string reverse(string str)
{
	int i = 0, j = str.size() - 1;
	while (i < j)
		swap(str[i++], str[j--]);
	return str;
}
void findAllAnswer(int i, int j, int path[N + 1][M + 1], int * X, int * Y, string ans)
{
	if (i <= 0 || j <= 0)
	{
		ans = reverse(ans);
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
		return;
	}
	if (path[i][j] == 3)
	{
		char ch = X[i - 1] + '0';
		findAllAnswer(i - 1, j - 1, path, X, Y, ans + ch);
	}
	else if (path[i][j] == 1)
	{
		findAllAnswer(i - 1, j, path, X, Y, ans);
	}
	else if (path[i][j] == -1)
	{
		findAllAnswer(i, j - 1, path, X, Y, ans);
	}
	else if (path[i][j] == 2)
	{
		findAllAnswer(i - 1, j, path, X, Y, ans);
		findAllAnswer(i, j - 1, path, X, Y, ans);
	}
}
int main()
{
	int X[N] = { 1 , 0 , 1 , 0 , 0 , 1 , 1 },
		Y[M] = { 0 , 0 , 1 , 1 , 1 , 0 , 0 , 1 , 1 , 1 },
		result[N + 1][M + 1] = { 0 },
		path[N + 1][M + 1] = { 0 };

	LCS(X, Y, result, path);
	findAllAnswer(N, M, path, X, Y, "");

	system("pause>0");
	return 0;
}