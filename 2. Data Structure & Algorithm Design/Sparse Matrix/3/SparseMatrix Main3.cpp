#include <iostream>
#include "SparseMatrix.h"
using namespace std;
int main()
{
	int n = 3, m = 3;
	int a[100][100] = { { 1,2,3 } ,{ 4,0,0 } ,{ 0,0,0 } }, b[100][100] = { { -9, 0, 0 } ,{ 0,8,0 } ,{ 0,0,0 } };

	Sparse A;
	A.ChangeToSparse(a, n, m);

	Sparse B;
	B.ChangeToSparse(b, n, m);

	Sparse C;

	C = A + B;

	C.Print();

	cout << "\n\n";

	C.Set(0, 0, 3);

	C.Set(2, 2, 13);

	C.Set(1, 1, 5);

	C.Set(2, 0, -33);

	C.Print();

	cout << "\n\n";

	C.Transpose();

	C.Print();

	system("pause>0");
	return 0;
}