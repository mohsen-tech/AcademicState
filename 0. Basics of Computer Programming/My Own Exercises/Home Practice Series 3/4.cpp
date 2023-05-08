#include <iostream>
using namespace std;
int Sqrt(int n)
{
	int a;
	for (int i = 0; i <= n && i*i <= n; i++)
		a = i;
	return a;
}
int main()
{
	int n;
	cin >> n;
	cout << Sqrt(n);
	return 0;
}