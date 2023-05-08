#include <iostream>
using namespace std;
class SparseMatrix;
class MatrixTerm
{
	friend class SparseMatrix;
private:
	int Row, Col, Val;
public:
	MatrixTerm()
	{
		Row = Col = Val = 1e8;
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class SparseMatrix
{
private:
	MatrixTerm smTerm[1000];
	int rowNo, colNo, valNo;
public:
	SparseMatrix() { rowNo = colNo = valNo = 0; }
	SparseMatrix(int temp[][100], int row, int col);
	void Input();
	int Get(int i, int j);
	void Set(int i, int j, int Value);
	void Print();
	int getVal() const;
	void Transpose();
	SparseMatrix operator + (const SparseMatrix & Obj);
	SparseMatrix operator - (const SparseMatrix & Obj);
	SparseMatrix operator * (const SparseMatrix & Obj);
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SparseMatrix::SparseMatrix(int temp[][100], int row, int col)
{
	rowNo = row;
	colNo = col;
	int k = 0;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			if (temp[i][j] != 0)
			{
				smTerm[k].Row = i;
				smTerm[k].Col = j;
				smTerm[k++].Val = temp[i][j];
			}
		}
	}
	valNo = k;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SparseMatrix::Input()
{
	cin >> rowNo >> colNo >> valNo;
	for (size_t i = 0; i < valNo; i++)
		cin >> smTerm[i].Row >> smTerm[i].Col >> smTerm[i].Val;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int SparseMatrix::Get(int i, int j)
{
	for (size_t k = 0; k < valNo; k++)
		if (smTerm[k].Row == i && smTerm[k].Col == j)
			return smTerm[k].Val;
	if (rowNo <= i || colNo <= j)
		return -999;
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SparseMatrix::Set(int i, int j, int Value)
{
	if (Value != 0)
	{
		for (size_t k = 0; k < valNo; k++)
			if (smTerm[k].Row == i && smTerm[k].Col == j)
			{
				smTerm[k].Val = Value;
				return;
			}
		if (rowNo > i && colNo > j)
		{
			smTerm[valNo].Row = i;
			smTerm[valNo].Col = j;
			smTerm[valNo++].Val = Value;

			for (size_t i = 0; i < valNo; i++)
				for (size_t j = i + 1; j < valNo; j++)
					if (smTerm[i].Row > smTerm[j].Row)
						swap(smTerm[i], smTerm[j]);
					else if (smTerm[i].Row == smTerm[j].Row && smTerm[i].Col > smTerm[j].Col)
						swap(smTerm[i], smTerm[j]);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SparseMatrix::Print()
{
	for (size_t i = 0; i < rowNo; i++)
	{
		for (size_t j = 0; j < colNo; j++)
			cout << Get(i, j) << "\t";
		cout << "\n";
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int SparseMatrix::getVal() const
{
	return valNo;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SparseMatrix::Transpose()
{
	for (size_t i = 0; i < valNo; i++)
		swap(smTerm[i].Row, smTerm[i].Col);

	for (size_t i = 0; i < valNo; i++)
		for (size_t j = i + 1; j < valNo; j++)
			if (smTerm[i].Row > smTerm[j].Row)
				swap(smTerm[i], smTerm[j]);
			else if (smTerm[i].Row == smTerm[j].Row && smTerm[i].Col > smTerm[j].Col)
				swap(smTerm[i], smTerm[j]);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SparseMatrix SparseMatrix::operator + (const SparseMatrix & Obj)
{
	if (rowNo == Obj.rowNo && colNo == Obj.colNo)
	{
		SparseMatrix Result;
		Result.rowNo = rowNo;
		Result.colNo = colNo;
		int i = 0, j = 0, k = 0;
		while (i < valNo || j < Obj.valNo)
		{
			if (smTerm[i].Row == Obj.smTerm[j].Row && smTerm[i].Col == Obj.smTerm[j].Col)
			{
				if (smTerm[i].Val + Obj.smTerm[j].Val != 0)
				{
					Result.smTerm[k] = smTerm[i];
					Result.smTerm[k++].Val = smTerm[i++].Val + Obj.smTerm[j++].Val;
				}
				else
					i++, j++;
			}
			else
			{
				if (smTerm[i].Row == Obj.smTerm[j].Row)
				{
					if (smTerm[i].Col < Obj.smTerm[j].Col)
					{
						Result.smTerm[k++] = smTerm[i++];
					}
					else
					{
						Result.smTerm[k++] = Obj.smTerm[j++];
					}
				}
				else
				{
					if (smTerm[i].Row < Obj.smTerm[j].Row)
					{
						Result.smTerm[k++] = smTerm[i++];
					}
					else
					{
						Result.smTerm[k++] = Obj.smTerm[j++];
					}
				}
			}
		}
		Result.valNo = k;
		return Result;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SparseMatrix SparseMatrix::operator - (const SparseMatrix & Obj)
{
	if (rowNo == Obj.rowNo && colNo == Obj.colNo)
	{
		SparseMatrix Result;
		Result.rowNo = rowNo;
		Result.colNo = colNo;
		int i = 0, j = 0, k = 0;
		while (i < valNo || j < Obj.valNo)
		{
			if (smTerm[i].Row == Obj.smTerm[j].Row && smTerm[i].Col == Obj.smTerm[j].Col)
			{
				if (smTerm[i].Val - Obj.smTerm[j].Val != 0)
				{
					Result.smTerm[k] = smTerm[i];
					Result.smTerm[k++].Val = smTerm[i++].Val - Obj.smTerm[j++].Val;
				}
				else
					i++, j++;
			}
			else
			{
				if (smTerm[i].Row == Obj.smTerm[j].Row)
				{
					if (smTerm[i].Col < Obj.smTerm[j].Col)
					{
						Result.smTerm[k++] = smTerm[i++];
					}
					else
					{
						Result.smTerm[k] = Obj.smTerm[j];
						Result.smTerm[k++].Val = -1 * Obj.smTerm[j++].Val;
					}
				}
				else
				{
					if (smTerm[i].Row < Obj.smTerm[j].Row)
					{
						Result.smTerm[k++] = smTerm[i++];
					}
					else
					{
						Result.smTerm[k] = Obj.smTerm[j];
						Result.smTerm[k++].Val = -1 * Obj.smTerm[j++].Val;
					}
				}
			}
		}
		Result.valNo = k;
		return Result;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SparseMatrix SparseMatrix::operator * (const SparseMatrix & Obj)
{
	SparseMatrix Result;
	if (colNo == Obj.rowNo)
	{
		Result.rowNo = rowNo;
		Result.colNo = Obj.colNo;
		int p = 0;
		for (size_t i = 0; i < valNo; i++)
		{
			for (size_t j = 0; j < Obj.valNo; j++)
			{
				if (smTerm[i].Col == Obj.smTerm[j].Row)
				{
					int temp = smTerm[i].Val * Obj.smTerm[j].Val;
					if (temp)
					{
						bool sw = false;
						for (size_t k = 0; k < p; k++)
						{
							if (Result.smTerm[k].Row == smTerm[i].Row && Result.smTerm[k].Col == Obj.smTerm[j].Col)
							{
								Result.smTerm[k].Val += temp;
								sw = true;
							}
						}
						if (sw == false)
						{
							Result.smTerm[p].Row = smTerm[i].Row;
							Result.smTerm[p].Col = Obj.smTerm[j].Col;
							Result.smTerm[p++].Val = temp;
						}
					}
				}
			}
		}
		Result.valNo = p;
	}
	for (size_t i = 0; i < Result.valNo; i++)
		for (size_t j = i + 1; j < Result.valNo; j++)
			if (Result.smTerm[i].Row > Result.smTerm[j].Row)
				swap(Result.smTerm[i], Result.smTerm[j]);
			else if (Result.smTerm[i].Row == Result.smTerm[j].Row && Result.smTerm[i].Col > Result.smTerm[j].Col)
				swap(Result.smTerm[i], Result.smTerm[j]);

	return Result;
}