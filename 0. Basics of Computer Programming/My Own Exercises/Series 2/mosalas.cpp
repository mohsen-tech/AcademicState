#include <iostream>
using namespace std;
int main()
{
	int rule, altitude;
	cout << "Pls Enter Altitude: ";
	cin >> altitude;
	cout << "Pls Enter Rule: ";
	cin >> rule;
	cout << "Area: " << (rule*altitude) / 2 << "\n";

	return 0;
}