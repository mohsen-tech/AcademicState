#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	n = ((2*n+1) + 1) / 2;
	int count = n - 1, k = n;
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		for (int j = 1; j <= 2 * n - 1; j++) {
			if (i > n)
			{
				if ((j <= abs(k - 1)) || (j > 2 * count - 1 + abs(k - 1)))
					cout << " ";
				else cout << "*";
				if (j == 2 * n - 1)
					count--;
			}
			else
			{
				if ((j <= abs(k - 1)) || (j > 2 * i - 1 + abs(k - 1)))
					cout << " ";
				else cout << "*";
			}
		}
		k--;
		cout << endl;
	}
	return 0;
}