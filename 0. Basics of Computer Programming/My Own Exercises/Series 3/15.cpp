#include <iostream>
using namespace std;
int main()
{
	int n, pow;
	cin >> n;
	int a = 2;
	pow = 1;

	for (int i = 1; i <= n; i++)
	{
		pow *= a;
		if (pow >= n)
		{
			break;
		}
	}
	cout << pow;
	return 0;
}