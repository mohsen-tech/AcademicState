#include<iostream>
using namespace std;
class Sparse;
class MatrixTerm
{
	friend class Sparse;
private:
	int Row, Col, Val;
};
class Sparse
{
private:
	MatrixTerm SmTerm[1000];
	int Row, Col, Value;
public:
	void ChangeToSparse(int a[100][100], int row, int col);
	Sparse() { Row = Col = Value = 0; }
	Sparse operator + (Sparse & Right);
	Sparse operator - (Sparse & Right);
	void Set(int i, int j, int Value);
	int Get(int i, int j);
	void Transpose();
	void Input();
	void Print();
};
void Sparse::ChangeToSparse(int a[100][100], int row, int col)
{
	Row = row;
	Col = col;
	int cnt = 0;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			if (a[i][j])
			{
				SmTerm[cnt].Row = i;
				SmTerm[cnt].Col = j;
				SmTerm[cnt++].Val = a[i][j];
			}
		}
	}
	Value = cnt;
}
void Sparse::Input()
{
	cin >> Row >> Col >> Value;
	for (size_t i = 0; i < Value; i++)
	{
		cin >> SmTerm[i].Row;
		cin >> SmTerm[i].Col;
		cin >> SmTerm[i].Val;
	}
}
int Sparse::Get(int row, int col)
{
	for (size_t i = 0; i < Value; i++)
		if (SmTerm[i].Row == row && SmTerm[i].Col == col)
			return SmTerm[i].Val;
	return 0;
}
void Sparse::Print()
{
	for (size_t i = 0; i < Row; i++)
	{
		for (size_t j = 0; j < Col; j++)
			cout << Get(i, j) << "\t";
		cout << "\n";
	}
}
void Sparse::Transpose()
{
	for (size_t i = 0; i < Value; i++)
		swap(SmTerm[i].Row, SmTerm[i].Col);
	int flag = 1;
	for (size_t i = 1; (i <= Value) && flag; i++)
	{
		flag = 0;
		for (size_t j = 0; j < (Value - 1); j++)
		{
			if (SmTerm[i].Row > SmTerm[j].Row)
			{
				swap(SmTerm[i], SmTerm[j]);
				flag = 1;
			}
			else if (SmTerm[i].Row == SmTerm[j].Row && SmTerm[i].Col > SmTerm[j].Col)
			{
				swap(SmTerm[i], SmTerm[j]);
				flag = 1;
			}
		}
	}
}
Sparse Sparse::operator + (Sparse & Right)
{
	Sparse res;
	if (Row == Right.Row && Col == Right.Col)
	{
		res.Row = Right.Row;
		res.Col = Right.Col;
		int i = 0, j = 0, k = 0;
		while (i < Value || j < Right.Value)
		{
			if (SmTerm[i].Row == Right.SmTerm[j].Row && SmTerm[i].Col == Right.SmTerm[j].Col)
			{
				if (SmTerm[i].Val + Right.SmTerm[j].Val)
				{
					res.SmTerm[k].Col = SmTerm[i].Col;
					res.SmTerm[k].Row = SmTerm[i].Row;
					res.SmTerm[k++].Val = SmTerm[i].Val + Right.SmTerm[j].Val;
				}
				i++, j++;
			}
			else
				if (SmTerm[i].Row == Right.SmTerm[j].Row)
					if (SmTerm[i].Col < Right.SmTerm[j].Col)
						res.SmTerm[k++] = SmTerm[i++];
					else
						res.SmTerm[k++] = Right.SmTerm[j++];
				else
					if (SmTerm[i].Row < Right.SmTerm[j].Row && i < Value)
						res.SmTerm[k++] = SmTerm[i++];
					else if (j < Right.Value)
						res.SmTerm[k++] = Right.SmTerm[j++];
					else if (i < Value)
						res.SmTerm[k++] = SmTerm[i++];
		}
		res.Value = k;
	}
	return res;
}
Sparse Sparse::operator - (Sparse & Right)
{
	Sparse res;
	if (Row == Right.Row && Col == Right.Col)
	{
		res.Row = Right.Row;
		res.Col = Right.Col;
		int i = 0, j = 0, k = 0;
		while (i < Value || j < Right.Value)
		{
			if (SmTerm[i].Row == Right.SmTerm[j].Row && SmTerm[i].Col == Right.SmTerm[j].Col)
			{
				if (SmTerm[i].Val - Right.SmTerm[j].Val)
				{
					res.SmTerm[k].Col = SmTerm[i].Col;
					res.SmTerm[k].Row = SmTerm[i].Row;
					res.SmTerm[k++].Val = SmTerm[i].Val - Right.SmTerm[j].Val;
				}
				i++, j++;
			}
			else
				if (SmTerm[i].Row == Right.SmTerm[j].Row)
					if (SmTerm[i].Col < Right.SmTerm[j].Col)
						res.SmTerm[k++] = SmTerm[i++];
					else
					{
						res.SmTerm[k].Col = Right.SmTerm[j].Col;
						res.SmTerm[k].Row = Right.SmTerm[j].Row;
						res.SmTerm[k++].Val = -1 * Right.SmTerm[j++].Val;
					}
				else
					if (SmTerm[i].Row < Right.SmTerm[j].Row && i < Value)
						res.SmTerm[k++] = SmTerm[i++];
					else if (j < Right.Value)
					{
						res.SmTerm[k].Col = Right.SmTerm[j].Col;
						res.SmTerm[k].Row = Right.SmTerm[j].Row;
						res.SmTerm[k++].Val = -1 * Right.SmTerm[j++].Val;
					}
					else if (i < Value)
						res.SmTerm[k++] = SmTerm[i++];
		}
		res.Value = k;
	}
	return res;
}
void Sparse::Set(int row, int col, int value)
{
	int flag = 0;
	for (size_t i = 0; i < Value; i++)
		if (SmTerm[i].Row == row && SmTerm[i].Col == col)
		{
			SmTerm[i].Val = value;
			flag = 1;
		}
	if (flag == 0)
		if (Row > row && Col > col)
		{
			SmTerm[Value].Row = row;
			SmTerm[Value].Col = col;
			SmTerm[Value].Val = value;
			Value++;
			int flag1 = 1;
			for (size_t i = 1; (i <= Value) && flag1; i++)
			{
				flag1 = 0;
				for (size_t j = 0; j < (Value - 1); j++)
				{
					if (SmTerm[i].Row > SmTerm[j].Row)
					{
						swap(SmTerm[i], SmTerm[j]);
						flag1 = 1;
					}
					else if (SmTerm[i].Row == SmTerm[j].Row && SmTerm[i].Col > SmTerm[j].Col)
					{
						swap(SmTerm[i], SmTerm[j]);
						flag1 = 1;
					}
				}
			}
		}
}