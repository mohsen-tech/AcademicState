#include <iostream>
using namespace std;
int main()
{
	int n, a = 1, b = 1, c;
	cin >> n;
	if (n == 1 || n == 2) {
		cout << 1;
	}
	else
	{
		n = n - 2;
		for (int i = n; i > 0; i--)
		{
			c = a + b;
			a = b;
			b = c;
		}
		cout << c;
	}
	return 0;
}