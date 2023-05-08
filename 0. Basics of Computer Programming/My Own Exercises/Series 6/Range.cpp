#include <iostream>
using namespace std;
int main()
{
	int a, b, n, s;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		s = 0;
		if (a % 2 == 0)
			a = a + 1;
		if (b % 2 == 0)
			b = b - 1;
		for (int j = a;j <= b;j = j + 2)
			s = s + j;
		cout << "Case " << i << ": " << s << "\n";
	}
	return 0;
}