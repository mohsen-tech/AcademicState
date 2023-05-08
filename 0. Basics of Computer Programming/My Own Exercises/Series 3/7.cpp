#include <iostream>
using namespace std;
int main()
{
	int a, j = 1;;
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		j = j*i;
	}
	cout << j;
	return 0;
}