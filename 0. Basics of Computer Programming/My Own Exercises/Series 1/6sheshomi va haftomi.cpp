#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	int a, b;
	cout << "\n Pls Enter Number a: ";
	cin >> a;
	cout << "\n Pls Enter Number b: ";
	cin >> b;
	a = a + b;
	b = a - b;
	a = a - b;
	cout << "\n Swap Of Them Is:  " << "a= " << a << "  b= " << b <<"\n";
	 

	return 0;
}