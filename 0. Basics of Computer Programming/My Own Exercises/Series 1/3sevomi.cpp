#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	double a;
	int i;
	cout << "\n Pls Enter a Mosbat Number: ";
	cin >> a;
	i = a;
	if (a >= 0)
	{
		cout << "\n Joze Sahih Of Your Number: " << i << "\n";
	}
	else if (a < 0)
	{
		cout << "\n Khob Shod Goftm Mosbat -_-" << "\n Vali Javabesh Mishe: " << i - 1 << "\n";
	}
	cout << endl;

	return 0;
}