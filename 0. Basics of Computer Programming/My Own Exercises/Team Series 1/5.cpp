#include <iostream>
using namespace std;
int main()
{
	int n;
	double a, sum = 0, max = -999999999, min = 999999999;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		sum = sum + a;
		if (a > max)
		{
			max = a;
		}
		if (a < min)
		{
			min = a;
		}
	}
	cout.precision(3);
	cout << fixed << "Max: " << max << endl << "Min: " << min << endl << "Avg: " << sum / n;
	return 0;
}