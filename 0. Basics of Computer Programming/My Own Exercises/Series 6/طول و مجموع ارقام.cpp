#include <iostream>
using namespace std;
int main()
{
	int a, b, s, sum;
	cin >> s;
	for (int i = 1; i <= s; i++)
	{
		cin >> a >> b;
		sum = 0;
		if (a % 2 == 0)
			a = a + 1;
		if (b % 2 == 0)
			b = b - 1;
		for (int j = a;j <= b;j = j + 2) {
			sum = sum + j;
		}
		cout << "Case " << i << ": " << sum << endl;
	}
	return 0;
}