#include <iostream>
using namespace std;
int main()
{
	int n, a = 0;
	cin >> n;
	while (n)
	{
		a = a + (n % 10);
		n = n / 10;
	}
	cout << a;
	return 0;
}