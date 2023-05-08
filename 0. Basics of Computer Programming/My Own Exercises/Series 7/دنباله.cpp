#include<iostream>
#include<cstring>
using namespace std;
unsigned long long int f(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 2;
	return 2 * f(n / 2) + 3 * f(n - 1) - f(n - 2);
}
int main()
{
	//a(n) = 2a(n / 2) + 3a(n ?1)? a(n ?2)
		//a(0) = 1, a(1) = 2
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}