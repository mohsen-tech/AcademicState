#include <iostream>
using namespace std;
// <in.txt> out.txt
void f(int n)
{
	if (n == 0)
		return;
	cout << n % 10;
	f(n / 10);
}
int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	f(n);

	system("pause>0");
	return 0;
}