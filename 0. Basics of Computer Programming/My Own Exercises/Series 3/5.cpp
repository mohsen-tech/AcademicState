#include <iostream>
using namespace std;
int main()
{
	int n, a = 0, max = -9999999, min = 9999999;
	cin >> n;
	while (n)
	{
		a = n % 10;
		n = n / 10;
		if (a < min)
		{
			min = a;
		}
		if (a > max)
		{
			max = a;
		}
	}
	cout << max << " " << min;
	return 0;
}