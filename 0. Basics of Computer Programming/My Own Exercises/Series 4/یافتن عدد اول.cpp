#include<iostream>
using namespace std;
int main()
{
	int n, n1, n2 = 0, b = 0;
	cin >> n;
	n1 = n;
	while (n1)
	{
		b = b + n1 % 10;
		n1 = n1 / 10;
	}
	for (int i = n + 1;i <= 10 * n;i++)
	{
		n1 = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i%j == 0)
			{
				n1++;
			}
		}
		if (n1 <= 1)
		{
			n2++;
			if (n2 == b)
			{
				cout << i;
				break;
			}
		}
	}
	return 0;
}