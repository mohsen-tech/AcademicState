#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	float fahrenheit, celsius;

	cout << "\n Pls Enter The Temprature In Celsius: ";
	cin >> celsius;

	fahrenheit = (celsius*9.0) / 5.0 + 32;

	cout << "\n The Temprature In Celsius: " << celsius <<"\n";
	cout << "\n The Temprature In Fahrenheit: " << fahrenheit << "\n";

	return 0;
}