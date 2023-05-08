#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	float length, width;
	cout << "\n Pls Enter Length : ";
	cin >> length;
	cout << "\n Pls Enter Width : ";
	cin >> width;

	cout << "\n Area : " << length*width << "\n";
	cout << "\n Perime : " << (length + width) * 2 << "\n";

	 

	return 0;
}