#include <iostream>
#include "SparseMatrix.h"
using namespace std;
int main()
{
	int n = 3, m = 3;
	int a[100][100] = { { 1,0,1 } ,{ 2,1,2 } ,{ 3,2,3 } }, b[100][100] = { { 1,0,0 } ,{ 0,1,0 } ,{ 0,0,1 } };

	SparseMatrix A(a, n, m);

	SparseMatrix B(b, n, m);

	SparseMatrix C;

	//B.Transpose();
	//B.Print();
	//A.SparseMatrix(a, n, m);

	C = A * B;
	C.Transpose();

	C = C - B;
	
	C.Set(0, 0, 9);

	C.Print();
	cout << "\n" << C.getVal();

	cout << "\n\n";
	
	A.Set(0, 3, 2);
	A.Print();

	system("pause>0");
	return 0;
}