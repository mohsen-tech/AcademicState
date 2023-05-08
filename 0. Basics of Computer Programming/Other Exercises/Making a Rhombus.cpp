#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int n, i, j;
	cout << "Input the length of diamond: ";
	cin >> n;
	for (i = 0;i < n - 1;++i)
	{
		for (j = 0;j < n - 1 - i;++j)
			cout << " ";
		for (j = 0;j < 2 * i + 1;++j)
			cout << "*";
		cout << endl;
	}
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < i;j++)
			cout << " ";
		for (j = 0;j < 2 * (n - i) - 1;++j)
			cout << "*";
		cout << endl;
	}
	_getch();
	return 0;
}