#include <iostream>
#include <string>
#include "List.h"
using namespace std;
int main()
{
	List <int> a(1);
	a.InsAtLast(2);
	a.InsAtLast(3);
	a.InsAtLast(4);
	a.InsAtLast(5);
	a.InsAtLast(6);
	a.InsAtLast(7);

	List <int> b;
	b = a;

	b.DelZoj();

	//a.Show();

	//a.MakeNull();

	b.ListInverse();

	b.Show();

	//a.DelWithoutObj();

	//a.MakeNull();
	//a.Show();
	/*List <int> b;
	b = a;
	b.ShowInverse();
	a.DelWithoutObj();
	a.Show();*/

	system("pause>0");
	return 0;
}