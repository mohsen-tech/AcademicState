#include<iostream>
using namespace std;
int main() {
	int a, b, l, s;
	cin >> a >> b >> l;
	for (int i = 0; i < l; i++)
	{
		if (i % 2 == 0)
		{
			s = ((i / 2 + 1)*a) + (i / 2 * b);
		}
		else if (i % 2 == 1)
		{
			s = ((i / 2 + 1)*a) + ((i / 2 + 1) * b);
		}
	}
	cout << s;
	return 0;
}