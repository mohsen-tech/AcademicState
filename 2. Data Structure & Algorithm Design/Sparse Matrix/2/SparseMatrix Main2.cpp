#include <iostream>
#include "SparseMatrix.h"
using namespace std;
/*void menu()
{
	int d;
	cout << "1.sparse " << endl;
	cout << "2.regular " << endl;
	cin >> d;
	sparsematrix sp1;
	sparsematrix sp2;

	switch (d)
	{
	case 1:
		cout << "first" << endl;
		sp1.input();
		cout << "second" << endl;
		sp2.input();
		break;
	case 2:
		cout << "first" << endl;
		sp1.reginput();
		cout << "second" << endl;
		sp2.reginput();
		break;
	}
	//system("cls");
	int e;
	cout << "1.sparse sum" << endl;
	cout << "2.regular sum" << endl;
	cout << "3.tafrigh" << endl;
	cout << "4.tafrighe mamooli" << endl;
	cout << "5.transpose" << endl;
	cout << "6.regular transpose" << endl;
	cout << "7.show sparse" << endl;
	cout << "8.show regular" << endl;
	cin >> e;
	switch (e)
	{
	case 1:
		sp1.sum();
		break;
	case 2:
		sp1.regsum();
		break;
	case 3:
		sp1.tafrigh();
		break;
	case 4:
		sp1.regtafrigh();
		break;
	case 5:
		sp1.transpose();
		break;
	case 6:
		sp1.regtranspose();
		break;
	case 7:
		sp1.output();
		break;
	case 8:
		sp1.regoutput();
		break;
	}
}*/
int main()
{
	int n = 3, m = 3;
	int a[100][100] = { { 1,2,3 } ,{ 4,0,0 } ,{ 0,0,0 } }, b[100][100] = { { 0, 0, 0 } ,{ 0,0,0 } ,{ 0,0,0 } };

	sparsematrix A;
	A.reginput(a, n, m);

	sparsematrix B;
	B.reginput(b, n, m);

	sparsematrix C;

	C.sum(A, A);

	C.output();
	cout << endl << C.size() << endl;

	cout << C.get(0, 1) << " " << C.get(1, 1) << endl;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			C.set(i, j, temp);
		}
	}

	C.output();
	cout << endl << C.size();

	system("pause>0");
	return 0;
}