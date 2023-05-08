#include <iostream>
using namespace std;
class Sparse
{
private:
	struct Sample
	{
		int Row, Col, Val;
	}Element[100];
public:
	Sparse()
	{
		for (size_t i = 0; i < 100; i++)
			Element[i].Col = Element[i].Val = Element[i].Row = 999999;
	}
	int getSize() const
	{
		return Element[0].Val;
	}
	void CreateSparse(int a[][100], int n, int m) // Convert Matrix To Sparse
	{
		Element[0].Col = m, Element[0].Row = n;
		int k = 1;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				if (a[i][j])
				{
					Element[k].Row = i;
					Element[k].Col = j;
					Element[k++].Val = a[i][j];
				}
			}
		}
		Element[0].Val = k - 1;
	}
	void Show() // Print Standard Matrix
	{
		int  k = 1;
		for (size_t i = 0; i < Element[0].Row; i++)
		{
			for (size_t j = 0; j < Element[0].Col; j++)
				if (Element[k].Col == j && Element[k].Row == i)
					cout << Element[k++].Val << "\t";
				else
					cout << "0\t";
			cout << "\n";
		}
	}
	Sparse operator + (const Sparse & Obj) // Calculate Sum Of Two Matrix
	{
		Sparse Result;
		if (Element[0].Col == Obj.Element[0].Col && Element[0].Row == Obj.Element[0].Row)
		{
			Result.Element[0].Col = Element[0].Col;
			Result.Element[0].Row = Element[0].Row;
			int j = 1, j1 = 1, j2 = 1;
			while ((j1 <= Element[0].Val) || (j2 <= Obj.Element[0].Val))
			{
				if (Element[j1].Col == Obj.Element[j2].Col && Element[j1].Row == Obj.Element[j2].Row)
				{
					if (Element[j1].Val + Obj.Element[j2].Val)
					{
						Result.Element[j].Col = Element[j1].Col;
						Result.Element[j].Row = Element[j1].Row;
						Result.Element[j++].Val = Element[j1].Val + Obj.Element[j2].Val;
					}
					j1++, j2++;
				}
				else
					if (Element[j1].Row == Obj.Element[j2].Row)
						if (Element[j1].Col < Obj.Element[j2].Col)
							Result.Element[j++] = Element[j1++];
						else
							Result.Element[j++] = Obj.Element[j2++];
					else
						if (Element[j1].Row < Obj.Element[j2].Row)
							Result.Element[j++] = Element[j1++];
						else
							Result.Element[j++] = Obj.Element[j2++];
			}
			Result.Element[0].Val = j - 1;
		}
		return Result;
	}
	Sparse operator - (const Sparse & Obj) // Calculate Subtract Of Two Matrix
	{
		Sparse Result;
		if (Element[0].Col == Obj.Element[0].Col && Element[0].Row == Obj.Element[0].Row)
		{
			Result.Element[0].Col = Element[0].Col;
			Result.Element[0].Row = Element[0].Row;
			int j = 1, j1 = 1, j2 = 1;
			while ((j1 <= Element[0].Val) || (j2 <= Obj.Element[0].Val))
			{
				if (Element[j1].Col == Obj.Element[j2].Col && Element[j1].Row == Obj.Element[j2].Row)
				{
					if (Element[j1].Val - Obj.Element[j2].Val)
					{
						Result.Element[j].Col = Element[j1].Col;
						Result.Element[j].Row = Element[j1].Row;
						Result.Element[j++].Val = Element[j1].Val - Obj.Element[j2].Val;
					}
					j1++, j2++;
				}
				else
					if (Element[j1].Row == Obj.Element[j2].Row)
						if (Element[j1].Col < Obj.Element[j2].Col)
						{
							Result.Element[j++] = Element[j1++];
						}
						else
						{
							Result.Element[j] = Obj.Element[j2];
							Result.Element[j++].Val = -1 * Obj.Element[j2++].Val;
						}
					else
						if (Element[j1].Row < Obj.Element[j2].Row)
						{
							Result.Element[j++] = Element[j1++];
						}
						else
						{
							Result.Element[j] = Obj.Element[j2];
							Result.Element[j++].Val = -1 * Obj.Element[j2++].Val;
						}
			}
			Result.Element[0].Val = j - 1;
		}
		return Result;
	}
	Sparse operator * (const Sparse & Obj) // Calculate Multi Of Two Matrix
	{
		Sparse Result;
		if (Element[0].Col == Obj.Element[0].Row)
		{
			Result.Element[0].Row = Element[0].Row;
			Result.Element[0].Col = Obj.Element[0].Col;
			int p = 1;
			for (size_t i = 1; i <= Element[0].Val; i++)
			{
				for (size_t j = 1; j <= Obj.Element[0].Val; j++)
				{
					if (Element[i].Col == Obj.Element[j].Row)
					{
						int temp = Element[i].Val * Obj.Element[j].Val;
						if (temp)
						{
							bool sw = false;
							for (size_t k = 1; k <= p; k++)
							{
								if (Result.Element[k].Row == Element[i].Row && Result.Element[k].Col == Obj.Element[j].Col)
								{
									Result.Element[k].Val += temp;
									sw = true;
								}
							}
							if (sw == false)
							{
								Result.Element[p].Row = Element[i].Row;
								Result.Element[p].Col = Obj.Element[j].Col;
								Result.Element[p++].Val = temp;
							}
						}
					}
				}
			}
			Result.Element[0].Val = p - 1;
		}
		for (size_t i = 1; i <= Result.Element[0].Val; i++)
		{
			for (size_t j = i + 1; j <= Result.Element[0].Val; j++)
			{
				if (Result.Element[i].Row > Result.Element[j].Row)
					swap(Result.Element[i], Result.Element[j]);
				else if (Result.Element[i].Row == Result.Element[j].Row && Result.Element[i].Col > Result.Element[j].Col)
					swap(Result.Element[i], Result.Element[j]);
			}
		}
		return Result;
	}
};
int main()
{
	Sparse A, B, C;
	int a[100][100] = { { 2 , 0 , 0 } , { 2 , 0 , 0 } , { 2 , 0 , 0 } };
	int b[100][100] = { { -1 , 0 , 0 } , { 0 , 1 , 0 } , { 1 , 0 , 1 } };
	int n = 3, m = 3;
	/*cin >> n >> m;

	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			cin >> a[i][j];

	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			cin >> b[i][j];*/

	A.CreateSparse(a, n, m);
	B.CreateSparse(b, n, m);
	C = A * B;
	C.Show();
	cout << C.getSize();

	//cout << "\n\nOrder: O(n ^ 2)";

	system("pause>0");
	return 0;
}

/*union Test
{
int num;
char ch[1];
};

Test test;
test.num = 0;

cout << sizeof(test) << endl;
cout << test.num << endl;

test.ch[1] = 1;

cout << sizeof(test) << endl;
cout << test.num << endl;*/
