#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#define arr2d vector<vector<double>>
#define N 1000000
using namespace std;
// <in.txt> out.txt
const string OUTPUT_FILE1 = "RandomNumbers.txt";
//----------------------------------------------------------------------------------------------------------------------------------------------------
bool isEmpty(ifstream & file)
{
	return file.peek() == ifstream::traits_type::eof();
}
void getNumbers(arr2d & matrixA, arr2d & matrixB, const int & len) // get numbers from file
{
	ifstream file(OUTPUT_FILE1);

	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			file >> matrixA[i][j];

	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			file >> matrixB[i][j];

	file.close();
}
void createRandomNumbers() // put numbers to file
{
	ofstream file("RandomNumbers.txt");
	for (int i = 0; i < N; i++)
	{
		double temp = (rand() % 1000) + (double)rand() / RAND_MAX;
		file << temp << "\n";
	}
	file.close();
}
double ** matrixAllocate(const int & mSize)
{
	double ** matrix = new double *[mSize];
	for (int i = 0; i < mSize; i++)
		matrix[i] = new double[mSize];
	return matrix;
}
void matrixFree(double ** matrix, const int & mSize)
{
	for (int i = 0; i < mSize; i++)
		free(matrix[i]);
	free(matrix);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void add(const arr2d & matrixA, const arr2d & matrixB, arr2d & matrixC, const int & mSize) // add two matrices
{
	for (int i = 0; i < mSize; i++)
		for (int j = 0; j < mSize; j++)
			matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
}
double ** add(double ** matrixA, double ** matrixB, const int & mSize, int deallocate)
{
	double ** matrixC = matrixAllocate(mSize);
	for (int i = 0; i < mSize; i++)
		for (int j = 0; j < mSize; j++)
			matrixC[i][j] = matrixA[i][j] + matrixB[i][j];

	if (deallocate & 1)
		matrixFree(matrixA, mSize);
	if (deallocate & 2)
		matrixFree(matrixB, mSize);

	return matrixC;
}
void sub(const arr2d & matrixA, const arr2d & matrixB, arr2d & matrixC, const int & mSize) // subtract two matrices
{
	for (int i = 0; i < mSize; i++)
		for (int j = 0; j < mSize; j++)
			matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
}
void mul(const arr2d & matrixA, const arr2d & matrixB, arr2d & matrixC, const int & mSize) // multiply two matrices
{
	for (int i = 0; i < mSize; i++)
	{
		for (int j = 0; j < mSize; j++)
		{
			matrixC[i][j] = 0;
			for (int k = 0; k < mSize; k++)
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
		}
	}
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void STRASSENalgorithmR(const arr2d & matrixA, const arr2d & matrixB, arr2d & matrixC, int mSize)
{
	// base case
	if (mSize == 1)
	{
		matrixC[0][0] = matrixA[0][0] * matrixB[0][0];
		return;
	}
	else
	{
		int new_size = mSize / 2;
		vector<double> z(new_size);
		arr2d
			a11(new_size, z), a12(new_size, z), a21(new_size, z), a22(new_size, z),
			b11(new_size, z), b12(new_size, z), b21(new_size, z), b22(new_size, z),
			c11(new_size, z), c12(new_size, z), c21(new_size, z), c22(new_size, z),
			p1(new_size, z), p2(new_size, z), p3(new_size, z), p4(new_size, z),
			p5(new_size, z), p6(new_size, z), p7(new_size, z),
			aResult(new_size, z), bResult(new_size, z);

		int i, j;
		// dividing the matrices into sub-matrices:
		for (i = 0; i < new_size; i++)
		{
			for (j = 0; j < new_size; j++)
			{
				a11[i][j] = matrixA[i][j];
				a12[i][j] = matrixA[i][j + new_size];
				a21[i][j] = matrixA[i + new_size][j];
				a22[i][j] = matrixA[i + new_size][j + new_size];

				b11[i][j] = matrixB[i][j];
				b12[i][j] = matrixB[i][j + new_size];
				b21[i][j] = matrixB[i + new_size][j];
				b22[i][j] = matrixB[i + new_size][j + new_size];
			}
		}
		// calculating p1 to p7:
		add(a11, a22, aResult, new_size); // a11 + a22
		add(b11, b22, bResult, new_size); // b11 + b22
		STRASSENalgorithmR(aResult, bResult, p1, new_size);
		// p1 = (a11+a22) * (b11+b22)

		add(a21, a22, aResult, new_size); // a21 + a22
		STRASSENalgorithmR(aResult, b11, p2, new_size);
		// p2 = (a21+a22) * (b11)

		sub(b12, b22, bResult, new_size); // b12 - b22
		STRASSENalgorithmR(a11, bResult, p3, new_size);
		// p3 = (a11) * (b12 - b22)

		sub(b21, b11, bResult, new_size); // b21 - b11
		STRASSENalgorithmR(a22, bResult, p4, new_size);
		// p4 = (a22) * (b21 - b11)

		add(a11, a12, aResult, new_size); // a11 + a12
		STRASSENalgorithmR(aResult, b22, p5, new_size);
		// p5 = (a11+a12) * (b22)

		sub(a21, a11, aResult, new_size); // a21 - a11
		add(b11, b12, bResult, new_size);
		// b11 + b12
		STRASSENalgorithmR(aResult, bResult, p6, new_size);
		// p6 = (a21-a11) * (b11+b12)

		sub(a12, a22, aResult, new_size); // a12 - a22
		add(b21, b22, bResult, new_size);
		// b21 + b22
		STRASSENalgorithmR(aResult, bResult, p7, new_size);
		// p7 = (a12-a22) * (b21+b22)

		// calculating c21, c21, c11 e c22:
		add(p3, p5, c12, new_size); // c12 = p3 + p5
		add(p2, p4, c21, new_size); // c21 = p2 + p4

		add(p1, p4, aResult, new_size); // p1 + p4
		add(aResult, p7, bResult, new_size); // p1 + p4 + p7
		sub(bResult, p5, c11, new_size); // c11 = p1 + p4 - p5 + p7

		add(p1, p3, aResult, new_size); // p1 + p3
		add(aResult, p6, bResult, new_size); // p1 + p3 + p6
		sub(bResult, p2, c22, new_size); // c22 = p1 + p3 - p2 + p6

		// grouping the results obtained in a single matrix:								 
		for (i = 0; i < new_size; i++)
		{
			for (j = 0; j < new_size; j++)
			{
				matrixC[i][j] = c11[i][j];
				matrixC[i][j + new_size] = c12[i][j];
				matrixC[i + new_size][j] = c21[i][j];
				matrixC[i + new_size][j + new_size] = c22[i][j];
			}
		}
	}
}
void STRASSENalgorithm(const arr2d & matrixA, const arr2d & matrixB, arr2d & matrixC, const int & mSize)
{
	STRASSENalgorithmR(matrixA, matrixB, matrixC, mSize);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------

double ** divideAndConquer(double ** matrixA, double ** matrixB, const int & mSize, int deallocate)
{
	double ** matrixC = matrixAllocate(mSize);
	if (mSize == 1)
	{
		matrixC[0][0] = matrixA[0][0] * matrixB[0][0];
	}
	else
	{
		int row2 = mSize / 2;
		double ** a11 = matrixAllocate(row2);
		double ** a12 = matrixAllocate(row2);
		double ** a21 = matrixAllocate(row2);
		double ** a22 = matrixAllocate(row2);
		double ** b11 = matrixAllocate(row2);
		double ** b12 = matrixAllocate(row2);
		double ** b21 = matrixAllocate(row2);
		double ** b22 = matrixAllocate(row2);
		for (int i = 0; i < row2; i++)
		{
			for (int j = 0; j < row2; j++)
			{
				a11[i][j] = matrixA[i][j];
				a12[i][j] = matrixA[i][j + row2];
				a21[i][j] = matrixA[i + row2][j];
				a22[i][j] = matrixA[i + row2][j + row2];
				b11[i][j] = matrixB[i][j];
				b12[i][j] = matrixB[i][j + row2];
				b21[i][j] = matrixB[i + row2][j];
				b22[i][j] = matrixB[i + row2][j + row2];
			}
		}
		double ** c11 = add(divideAndConquer(a11, b11, row2, 0), divideAndConquer(a12, b21, row2, 0), row2, 1 + 2);
		double ** c12 = add(divideAndConquer(a11, b12, row2, 1), divideAndConquer(a12, b22, row2, 1), row2, 1 + 2);
		double ** c21 = add(divideAndConquer(a21, b11, row2, 2), divideAndConquer(a22, b21, row2, 2), row2, 1 + 2);
		double ** c22 = add(divideAndConquer(a21, b12, row2, 1 + 2), divideAndConquer(a22, b22, row2, 1 + 2), row2, 1 + 2);
		for (int i = 0; i < row2; i++)
		{
			for (int j = 0; j < row2; j++)
			{
				matrixC[i][j] = c11[i][j];
				matrixC[i][j + row2] = c12[i][j];
				matrixC[i + row2][j] = c21[i][j];
				matrixC[i + row2][j + row2] = c22[i][j];
			}
		}
		matrixFree(c11, row2);
		matrixFree(c12, row2);
		matrixFree(c21, row2);
		matrixFree(c22, row2);
	}
	if (deallocate & 1)
		matrixFree(matrixA, mSize);
	if (deallocate & 2)
		matrixFree(matrixB, mSize);
	return matrixC;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	cout << fixed << setprecision(10);
	ifstream ifile(OUTPUT_FILE1);
	if (isEmpty(ifile)) // run first time & init numbers to file
	{
		ifile.close();
		createRandomNumbers();
	}
	else
	{
		clock_t tStart;
		cout << "matrixSize (n * n)  |  Naive matrix multiplication (sec)  |  Divide and Conquer (sec) | Strassen’s (sec)\n";
		for (unsigned int matrixSize = 2; matrixSize < 129; matrixSize *= 2)
		{
			/*if (matrixSize < 1 || matrixSize > 256)
			{
			cout << endl << "ERROR: n must be between 1 and 256 (including 1 and 256)" << endl;
			exit(0);
			}*/
			/*else*/ if (ceil(log2(matrixSize)) != floor(log2(matrixSize)))
			{
				cout << endl << "ERROR: n must be a power of 2" << endl;
				exit(0);
			}
			arr2d matrixA(matrixSize, vector<double>(matrixSize, 0)), matrixB(matrixSize, vector<double>(matrixSize, 0)), matrixC(matrixSize, vector<double>(matrixSize, 0)), temp;
			getNumbers(matrixA, matrixB, matrixSize);

			cout << "\n" << matrixSize << " \t\t\t";

			temp = matrixC;
			tStart = clock();
			mul(matrixA, matrixB, temp, matrixSize);
			cout << (double)(clock() - tStart) / CLOCKS_PER_SEC << "\t\t\t";
			//----------------------------------------------------------------------------------------------------------------------------------------------------
			double ** A = matrixAllocate(matrixSize);
			double ** B = matrixAllocate(matrixSize);
			for (int i = 0; i < matrixSize; i++)
			{
				for (int j = 0; j < matrixSize; j++)
				{
					A[i][j] = matrixA[i][j];
					B[i][j] = matrixB[i][j];
				}
			}
			tStart = clock();
			double ** C = divideAndConquer(A, B, matrixSize, 0);
			cout << (double)(clock() - tStart) / CLOCKS_PER_SEC << "\t\t\t";
			matrixFree(C, matrixSize);
			//----------------------------------------------------------------------------------------------------------------------------------------------------
			temp = matrixC;
			tStart = clock();
			//strassen(matrixA, matrixB, temp, matrixSize);
			STRASSENalgorithm(matrixA, matrixB, temp, matrixSize);
			cout << (double)(clock() - tStart) / CLOCKS_PER_SEC << "\n\n";
		}
	}
	//system("pause");
	return 0;
}