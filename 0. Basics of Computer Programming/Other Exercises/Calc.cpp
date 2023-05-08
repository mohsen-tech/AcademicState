#include<iostream>
using namespace std;
float Plus(float a, float b)
{
	return a + b;
}
float Minus(float a, float b)
{
	return a - b;
}
float Multi(float a, float b)
{
	return a * b;
}
float Dive(float a, float b)
{
	return a / b;
}
int main()
{
	float a, b;
	char s;
	cout << "Choose One('*' , '/' , '+' , '-'): ";
	cin >> s;
	cout << "Enter 2Number: ";
	cin >> a >> b;
	if (s == '*')
		cout << Multi(a, b) << endl;
	else if (s == '/')
		cout << Dive(a, b) << endl;
	else if (s == '+')
		cout << Plus(a, b) << endl;
	else if (s == '-')
		cout << Minus(a, b) << endl;
}