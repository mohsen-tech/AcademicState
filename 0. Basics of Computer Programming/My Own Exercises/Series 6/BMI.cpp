#include <iostream>
using namespace std;
int main()
{
	float n, m, BMI;
	cin >> n >> m;
	BMI = n / (m*m);
	cout << fixed;
	cout.precision(2);
	if (BMI < 18.5)
	{
		cout << BMI << "\n" << "Underweight";
	}
	else if (18.5 <= BMI && BMI < 25)
	{
		cout << BMI << "\n" << "Normal";
	}
	else if (25 <= BMI && BMI < 30)
	{
		cout << BMI << "\n" << "Overweight";
	}
	else if (30 <= BMI)
	{
		cout << BMI << "\n" << "Obese";
	}
	return 0;
}