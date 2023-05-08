#include <iostream>
using namespace std;
int main()
{
	int n, a, max = -9999999, j;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (a > max)
		{
			max = a;
			j = i;
		}
	}
	cout << max << " " << j;
	return 0;
}