#include <iostream>
using namespace std;
int main()
{
	int x, a, n, n_yell = 1, k_yell, n_k, pow_x, pow_a, s = 0;
	cin >> a >> x >> n;
	for (int j = 1; j <= n; j++)
		n_yell = n_yell * j;
	for (int i = 0; i <= n; i++)
	{
		k_yell = 1;
		n_k = 1;
		pow_x = 1;
		pow_a = 1;
		for (int j = 1; j <= i; j++)
			k_yell = k_yell * j;

		for (int j = 1; j <= n - i; j++)
			n_k = n_k * j;

		for (int j = 0; j < i; j++)
			pow_x = pow_x * x;

		for (int j = 0; j < n - i; j++)
			pow_a = pow_a * a;

		s = s + (n_yell / (k_yell * n_k)) * pow_x * pow_a;
	}
	cout << s;
	return 0;
}