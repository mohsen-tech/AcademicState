#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, m, s = 0;
	cin >> n >> m;
	for (int j = 1; j <= n; j++)
	{
		for (int i = -10; i <= m; i++)
		{
			s = s + floor(((pow(i + j, 3))) / (pow(j, 2)));
		}
	}
	cout << s;
	return 0;
}