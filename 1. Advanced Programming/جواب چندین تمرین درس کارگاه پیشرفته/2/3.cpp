#include <iostream>
#include <math.h>
using namespace std;
// <in.txt> out.txt
void f(const int & a, const int & b, const int & c)
{
	int delta = pow(b, 2) - 4 * a * c;
	int x1 = ((-1 * b) + sqrt(delta)) / (2 * a);
	int x2 = ((-1 * b) - sqrt(delta)) / (2 * a);
	cout << "\nx1 = " << x1 << ", x2 = " << x2 << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cout << "ax^2 + bx + c";
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	f(a, b, c);

	system("pause>0");
	return 0;
}