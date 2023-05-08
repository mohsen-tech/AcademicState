#include <iostream>
using namespace std;
int main()
{
	int max = -99999999999, a, n, j;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (a > max) {
			max = a;
			j = i;
		}
	}
	cout << max << " " << j;
	return 0;
}