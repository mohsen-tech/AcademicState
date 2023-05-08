#include<iostream>
using namespace std;
struct Term
{
	int Row, Col, Value;
};
class sparsematrix
{
private:
	int RowNO, ColNO, ValNO;
	Term * Terms;
	void push_back(Term Arg);
public:
	sparsematrix() { RowNO = 0, ColNO = 0, ValNO = 0; Terms = new Term[ValNO]; }
	void input();
	void reginput(int regmatrix[100][100], int n, int m);
	int get(int i, int j);
	int size() const { return ValNO; }
	sparsematrix & operator = (const sparsematrix & Arg);
	bool operator == (const sparsematrix & Arg);
	void set(int i, int j, int value);
	void sum(sparsematrix & A, sparsematrix & B);
	void tafrigh(sparsematrix & A, sparsematrix & B);
	void transpose();
	void output();
	~sparsematrix() { delete[] Terms; }
};
void sparsematrix::input()
{
	cout << "row, col, val? " << endl;
	cin >> RowNO >> ColNO >> ValNO;
	if (ValNO > (RowNO * ColNO))
	{
		cout << "ERROR" << endl;
	}
	else
	{
		delete[] Terms;
		Terms = new Term[ValNO];
		for (int i = 0; i < ValNO; i++)
		{
			cout << "row col val : " << endl;
			cin >> Terms[i].Row >> Terms[i].Col >> Terms[i].Value;
		}
	}
}
void sparsematrix::reginput(int regmatrix[100][100], int n, int m)
{
	delete[] Terms;
	ValNO = 0;
	Terms = new Term[ValNO];
	RowNO = n, ColNO = m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (regmatrix[i][j])
			{
				Term * temp = new Term;
				temp->Row = i;
				temp->Col = j;
				temp->Value = regmatrix[i][j];
				push_back(*temp);
				delete temp;
			}
		}
	}
}
void sparsematrix::push_back(Term Arg)
{
	Term * temp = new Term[ValNO + 1];
	for (int i = 0; i < ValNO; i++)
	{
		temp[i] = Terms[i];
	}
	temp[ValNO] = Arg;
	delete[] Terms;
	ValNO++;
	Terms = new Term[ValNO];
	for (int i = 0; i < ValNO; i++)
	{
		Terms[i] = temp[i];
	}
	delete[] temp;
}
int sparsematrix::get(int i, int j)
{
	for (int k = 0; k < ValNO; k++)
		if (Terms[k].Row == i && Terms[k].Col == j)
			return Terms[k].Value;
	return 0;
}
sparsematrix & sparsematrix::operator = (const sparsematrix & Arg)
{
	if (size() != Arg.size())
	{
		delete[] Terms;
		ValNO = Arg.size();
		Terms = new Term[ValNO];
	}
	for (int i = 0; i < ValNO; i++)
	{
		Terms[i] = Arg.Terms[i];
	}
	RowNO = Arg.RowNO;
	ColNO = Arg.ColNO;
	return *this;
}
bool sparsematrix::operator == (const sparsematrix & Arg)
{
	if (size() != Arg.size())
	{
		return false;
	}
	for (int i = 0; i < size(); i++)
	{
		if (Terms[i].Row != Arg.Terms[i].Row)
		{
			return false;
		}
		if (Terms[i].Col != Arg.Terms[i].Col)
		{
			return false;
		}
		if (Terms[i].Value != Arg.Terms[i].Value)
		{
			return false;
		}
	}
	return true;
}
void sparsematrix::set(int i, int j, int value)
{
	if (value)
	{
		for (int k = 0; k < ValNO; k++)
		{
			if (Terms[k].Row == i && Terms[k].Col == j)
			{
				Terms[k].Value = value;
				return;
			}
		}
		if (RowNO > i && ColNO > j)
		{
			Term * temp = new Term;
			temp->Row = i;
			temp->Col = j;
			temp->Value = value;
			push_back(*temp);
			delete temp;
			for (int i = 0; i < size(); i++)
			{
				for (int j = i + 1; j < size(); j++)
				{
					if (Terms[i].Row > Terms[j].Row || (Terms[i].Row == Terms[j].Row && Terms[i].Col > Terms[j].Col))
					{
						swap(Terms[i], Terms[j]);
					}
				}
			}
		}
	}
	else if (ValNO)
	{
		bool sw = false;
		for (int k = 0; k < ValNO; k++)
		{
			if (Terms[k].Row == i && Terms[k].Col == j)
			{
				sw = true;
			}
		}
		if (sw == false) { return; }
		Term * temp = new Term[ValNO];
		for (int k = 0; k < ValNO; k++)
		{
			temp[k] = Terms[k];
		}
		delete[] Terms;

		sw = false;
		for (int k = 0; k < ValNO; k++)
		{
			if (temp[k].Row == i && temp[k].Col == j)
			{
				temp[k].Value = value;
				sw = true;
			}
		}
		if (sw)
		{
			for (int k = 0; k < ValNO; k++)
			{
				if (temp[k].Value == 0)
				{
					for (int p = k; p < ValNO - 1; p++)
					{
						temp[p] = temp[p + 1];
					}
					ValNO--;
				}
			}
			Terms = new Term[ValNO];
			for (int k = 0; k < ValNO; k++)
			{
				Terms[k] = temp[k];
			}
			delete[] temp;
		}
	}
}
void sparsematrix::sum(sparsematrix & A, sparsematrix & B)
{
	sparsematrix * Atemp = new sparsematrix;
	sparsematrix * Btemp = new sparsematrix;
	*Atemp = A;
	*Btemp = B;
	delete[] Terms;
	ValNO = 0;
	Terms = new Term[ValNO];
	if (Atemp->ColNO == Btemp->ColNO && Atemp->RowNO == Btemp->RowNO)
	{
		ColNO = Atemp->ColNO;
		RowNO = Atemp->RowNO;
		int j = 0, j1 = 0, j2 = 0;
		while ((j1 < Atemp->ValNO) || (j2 < Btemp->ValNO))
		{
			Term * temp = new Term;
			if (Atemp->Terms[j1].Col == Btemp->Terms[j2].Col && Atemp->Terms[j1].Row == Btemp->Terms[j2].Row)
			{
				if (Atemp->Terms[j1].Value + Btemp->Terms[j2].Value)
				{
					*temp = Atemp->Terms[j1];
					temp->Value = Atemp->Terms[j1].Value + Btemp->Terms[j2].Value;
					push_back(*temp);
				}
				j1++, j2++;
			}
			else
				if (Atemp->Terms[j1].Row == Btemp->Terms[j2].Row)
				{
					if (Atemp->Terms[j1].Col < Btemp->Terms[j2].Col)
					{
						*temp = Atemp->Terms[j1++];
						push_back(*temp);
					}
					else
					{
						*temp = Btemp->Terms[j2++];
						push_back(*temp);
					}
				}
				else
				{
					if (Atemp->Terms[j1].Row < Btemp->Terms[j2].Row && (j1 < Atemp->ValNO))
					{
						*temp = Atemp->Terms[j1++];
						push_back(*temp);
					}
					else if (j2 < Btemp->ValNO)
					{
						*temp = Btemp->Terms[j2++];
						push_back(*temp);
					}
					else if (j1 < Atemp->ValNO)
					{
						*temp = Atemp->Terms[j1++];
						push_back(*temp);
					}
				}
			delete temp;
		}
	}
	delete Atemp;
	delete Btemp;
}
void sparsematrix::tafrigh(sparsematrix & A, sparsematrix & B)
{
	sparsematrix * Atemp = new sparsematrix;
	sparsematrix * Btemp = new sparsematrix;
	*Atemp = A;
	*Btemp = B;
	delete[] Terms;
	ValNO = 0;
	Terms = new Term[ValNO];
	if (Atemp->ColNO == Btemp->ColNO && Atemp->RowNO == Btemp->RowNO)
	{
		ColNO = Atemp->ColNO;
		RowNO = Atemp->RowNO;
		int j = 0, j1 = 0, j2 = 0;
		while ((j1 < Atemp->ValNO) || (j2 < Btemp->ValNO))
		{
			Term * temp = new Term;
			if (Atemp->Terms[j1].Col == Btemp->Terms[j2].Col && Atemp->Terms[j1].Row == Btemp->Terms[j2].Row)
			{
				if (Atemp->Terms[j1].Value - Btemp->Terms[j2].Value)
				{
					*temp = Atemp->Terms[j1];
					temp->Value = Atemp->Terms[j1].Value - Btemp->Terms[j2].Value;
					push_back(*temp);
				}
				j1++, j2++;
			}
			else
				if (Atemp->Terms[j1].Row == Btemp->Terms[j2].Row)
				{
					if (Atemp->Terms[j1].Col < Btemp->Terms[j2].Col)
					{
						*temp = Atemp->Terms[j1++];
						push_back(*temp);
					}
					else
					{
						*temp = Btemp->Terms[j2];
						temp->Value = Btemp->Terms[j2++].Value * -1;
						push_back(*temp);
					}
				}
				else
				{
					if (Atemp->Terms[j1].Row < Btemp->Terms[j2].Row && (j1 < Atemp->ValNO))
					{
						*temp = Atemp->Terms[j1++];
						push_back(*temp);
					}
					else if (j2 < Btemp->ValNO)
					{
						*temp = Btemp->Terms[j2];
						temp->Value = Btemp->Terms[j2++].Value * -1;
						push_back(*temp);
					}
					else if (j1 < Atemp->ValNO)
					{
						*temp = Atemp->Terms[j1++];
						push_back(*temp);
					}
				}
			delete temp;
		}
	}
	delete Atemp;
	delete Btemp;
}
void sparsematrix::transpose()
{
	for (int i = 0; i < size(); i++)
	{
		swap(Terms[i].Row, Terms[i].Col);
	}
	for (int i = 0; i < size(); i++)
	{
		for (int j = i + 1; j < size(); j++)
		{
			if (Terms[i].Row > Terms[j].Row || (Terms[i].Row == Terms[j].Row && Terms[i].Col > Terms[j].Col))
			{
				swap(Terms[i], Terms[j]);
			}
		}
	}
}
void sparsematrix::output()
{
	int  k = 0;
	for (int i = 0; i < RowNO; i++)
	{
		for (int j = 0; j < ColNO; j++)
		{
			if (Terms[k].Col == j && Terms[k].Row == i)
			{
				cout << Terms[k++].Value << "  ";
			}
			else
				cout << "0  ";
		}
		cout << endl;
	}
}