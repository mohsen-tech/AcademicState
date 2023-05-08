#include<iostream>
#include<math.h>
using namespace std;
int main() {
	float n, x, yell = 1, s = 1;
	cin >> x >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		yell = yell*i;
		s = s + ((pow(x, i)) / yell);
	}

	cout.precision(3);
	cout << fixed << s;
	return 0;
}