#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	int i, j;
	for (i = 1; i <= 13; i++)
	{
		for (j = 1; j <= i; j++)
			cout << "*";
		cout << "\n";
		
	}
	for (i = 1; i <=12; i++)
	{
		for (j = 12; j >= i; j--)
			cout << "*";
		cout << "\n";
		
	}
	cout << "\n";
	return 0;
}