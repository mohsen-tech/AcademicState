#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	float h, Y0, Vy, Vx, delta, t1, t2;
	cin >> Vx >> Vy >> Y0 >> h;
	cout.precision(2);
	cout << fixed;
	delta = Vy * Vy + 20 * (Y0 - h);
	if (delta == 0)
	{
		cout << (Vy / 10) * Vx;
	}
	else if (delta < 0)
	{
		cout << "impossible";
	}
	else if (delta > 0)
	{
		t1 = ((Vy - sqrt(delta)) / 10) * Vx;
		t2 = ((Vy + sqrt(delta)) / 10) * Vx;
		if (t1 < 0 && t2 < 0)
			cout << "impossible";
		else if (t1 > 0 && t2 > 0)
			cout << t1 << endl << t2;
		else if (t1 > 0)
			cout << t1;
		else if (t2 > 0)
			cout << t2;
	}
	return 0;
}