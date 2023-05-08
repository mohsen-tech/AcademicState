#include <iostream>
using namespace std;
int main()
{
	float danshjo, dars, vahed, sum = 0, vaheda = 0, nomre, avg;
	cin >> danshjo >> dars;
	for (int i = 1; i <= dars; i++)
	{
		cin >> vahed >> nomre;
		sum = sum + vahed*nomre;
		vaheda = vaheda + vahed;
	}
	avg = sum / vaheda;
	cout << avg;
	return 0;
}