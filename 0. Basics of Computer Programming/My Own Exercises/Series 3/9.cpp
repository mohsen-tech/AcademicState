#include <iostream>
using namespace std;
int main()
{
	int a, b, j = 0;;
	cin >> a >> b;

	for (int i = a;i <= b;i++) {
		if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11 || i == 13)
		{
			cout << i << " ";
			j++;
		}
		else if (i / 1 != 1 && i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0 && i % 11 != 0 && i % 13 != 0)
		{
			cout << i << " ";
			j++;

		}
	}
	if (j == 0)
	{
		cout << 0;
	}
	return 0;
}