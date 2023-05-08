#include<iostream>
using namespace std;
int main()
{
	unsigned long long int x, y, n, s, a, a1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		for (int j = 0; j <= a; j++)
		{
			a1 = a;
			s = 0;
			while (a1)
			{
				s = 10 * s + a1 % 10;
				a1 = a1 / 10;
			}
			if (s == a)
			{
				x = j;
				y = s;
				break;
			}
			else
				a = a + s;
		}
		cout << x << " " << y << endl;
	}
	return 0;
}