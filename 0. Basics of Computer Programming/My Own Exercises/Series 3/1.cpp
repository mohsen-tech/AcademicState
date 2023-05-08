#include <iostream>
using namespace std;
int main()
{
	int a, n, j = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (a % 2 == 0)
		{

			j = j + 1;
		}
	}
	cout << j;

	return 0;
}