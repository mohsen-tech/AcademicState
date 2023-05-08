#include <iostream>
using namespace std;
int Raqam(int n);
int PaeinMosalasiMatrix(int a[100][100], int n);
int BalaMosalasiMatrix(int a[100][100], int n);
void ScanMatrix(int a[100][100], int n, int m);
void PrintMatrix(int a[100][100], int Raqam[100][100], int n, int m);
void IntMatrix(int a[100][100], int b[100][100], int n, int m);
void IntRaqamMatrix(int a[100][100], int b[100][100], int n, int m);
void FixMatrix(int a[100][100], int b[100][100], int n, int m);
void ImpNumbers(int IntRaqamA[][100], int IntRaqamB[][100], int IntRaqamC[][100], int IntA[][100], int IntB[][100], int n, int m);
void PlusMatrix(int a[][100], int b[][100], int c[][100], int n, int m);
void MinusMatrix(int a[][100], int b[][100], int c[][100], int n, int m);
void ZarbNumber(int a[100][100], int x, int n, int m);
void RemoveSoton(int a[100][100], int b[100][100], int x, int n, int m);
void RemoveSatr(int a[100][100], int b[100][100], int x, int n, int m);
void TaraMatrix(int a[100][100], int b[100][100], int m);
void MultiMatrix(int IntA[100][100], int IntB[100][100], int c[100][100], int IntRaqamA[][100], int IntRaqamB[][100], int IntRaqamC[][100], int n, int m, int p);
//----------------------------------------------------------------------------------------------//
int main()
{
	int a[100][100], IntA[100][100], IntRaqamA[100][100], FixA[100][100];
	int b[100][100], IntB[100][100], IntRaqamB[100][100], FixB[100][100];
	int c[100][100], IntC[100][100], IntRaqamC[100][100], FixC[100][100];
	int n, m, p;
	int Choose;
	/////////////////////////////////////////////
	cout << "\n*HELP*\n\n";
	cout << " 1    2    3\n";
	cout << "---  ---  --- = 1.003\n\n";
	/////////////////////////////////////////////
	cout << "Now Choose One:  \n\n";
	cout << "1. Plus Two Matrix\n\n";
	cout << "2. Minus Two Matrix\n\n";
	cout << "3. Multi Two Matrix\n\n";
	cout << "4. Multi Number*Matrix\n\n";
	cout << "5. Bala Mosalasi\n\n";
	cout << "6. Paein Mosalasi\n\n";
	cout << "7. Remove One Satr\n\n";
	cout << "8. Remove One Soton\n\n";
	cout << "9. Taranahade Matrix\n\n";
	while (cin >> Choose)
	{
		if (Choose == 1)
		{
			cout << "Satr: ";
			cin >> n;
			cout << "Soton: ";
			cin >> m;
			cout << "Enter Matrix A:\n";
			ScanMatrix(a, n, m);
			FixMatrix(a, FixA, n, m);
			cout << "Enter Matrix B:\n";
			ScanMatrix(b, n, m);
			FixMatrix(b, FixB, n, m);
			IntMatrix(a, IntA, n, m);
			FixMatrix(FixA, a, n, m);
			IntMatrix(b, IntB, n, m);
			FixMatrix(FixB, b, n, m);
			IntRaqamMatrix(a, IntRaqamA, n, m);
			FixMatrix(FixA, a, n, m);
			IntRaqamMatrix(b, IntRaqamB, n, m);
			FixMatrix(FixB, b, n, m);
			ImpNumbers(IntRaqamA, IntRaqamB, IntRaqamC, IntA, IntB, n, m);
			PlusMatrix(IntA, IntB, c, n, m);
			cout << "Result Of Plus Matrix:\n";
			PrintMatrix(c, IntRaqamC, n, m);
		}
		else if (Choose == 2)
		{
			cout << "Satr: ";
			cin >> n;
			cout << "Soton: ";
			cin >> m;
			cout << "Enter Matrix A:\n";
			ScanMatrix(a, n, m);
			FixMatrix(a, FixA, n, m);
			cout << "Enter Matrix B:\n";
			ScanMatrix(b, n, m);
			FixMatrix(b, FixB, n, m);
			IntMatrix(a, IntA, n, m);
			FixMatrix(FixA, a, n, m);
			IntMatrix(b, IntB, n, m);
			FixMatrix(FixB, b, n, m);
			IntRaqamMatrix(a, IntRaqamA, n, m);
			FixMatrix(FixA, a, n, m);
			IntRaqamMatrix(b, IntRaqamB, n, m);
			FixMatrix(FixB, b, n, m);
			ImpNumbers(IntRaqamA, IntRaqamB, IntRaqamC, IntA, IntB, n, m);
			MinusMatrix(IntA, IntB, c, n, m);
			cout << "Result Of Minus Matrix:\n";
			PrintMatrix(c, IntRaqamC, n, m);
		}
		else if (Choose == 3)
		{
			cout << "Satr: ";
			cin >> n;
			cout << "Soton: ";
			cin >> m;
			cout << "Soton Matrix B: ";
			cin >> p;
			cout << "Enter Matrix A:\n";
			ScanMatrix(a, n, m);
			FixMatrix(a, FixA, n, m);
			cout << "Enter Matrix B:\n";
			ScanMatrix(b, m, p);
			FixMatrix(b, FixB, m, p);
			IntMatrix(a, IntA, n, m);
			FixMatrix(FixA, a, n, m);
			IntMatrix(b, IntB, m, p);
			FixMatrix(FixB, b, m, p);
			IntRaqamMatrix(a, IntRaqamA, n, m);
			FixMatrix(FixA, a, n, m);
			IntRaqamMatrix(b, IntRaqamB, m, p);
			FixMatrix(FixB, b, m, p);
			MultiMatrix(IntA, IntB, c, IntRaqamA, IntRaqamB, IntRaqamC, n, m, p);
			cout << "Result Of Multi Two Matrix:\n";
			PrintMatrix(c, IntRaqamC, n, p);
		}
		else if (Choose == 4)
		{
			int x;
			cout << "Satr: ";
			cin >> n;
			cout << "Soton: ";
			cin >> m;
			cout << "Enter a Number: ";
			cin >> x;
			cout << "Enter Matrix:\n";
			ScanMatrix(a, n, m);
			FixMatrix(a, FixA, n, m);
			IntMatrix(a, IntA, n, m);
			FixMatrix(FixA, a, n, m);
			IntRaqamMatrix(a, IntRaqamA, n, m);
			FixMatrix(FixA, a, n, m);
			ZarbNumber(IntA, x, n, m);
			cout << "Result Of Zarb Number:\n";
			PrintMatrix(IntA, IntRaqamA, n, m);
		}
		else if (Choose == 5)
		{
			cout << "Satr,Soton: ";
			cin >> n;
			cout << "Enter Matrix:\n";
			ScanMatrix(a, n, n);
			FixMatrix(a, FixA, n, n);
			IntMatrix(a, IntA, n, n);
			FixMatrix(FixA, a, n, n);
			IntRaqamMatrix(a, IntRaqamA, n, n);
			FixMatrix(FixA, a, n, n);
			cout << "Result Of Bala Mosalasi:\n";
			if (BalaMosalasiMatrix(IntA, n))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		else if (Choose == 6)
		{
			cout << "Satr,Soton: ";
			cin >> n;
			cout << "Enter Matrix:\n";
			ScanMatrix(a, n, n);
			FixMatrix(a, FixA, n, n);
			IntMatrix(a, IntA, n, n);
			FixMatrix(FixA, a, n, n);
			IntRaqamMatrix(a, IntRaqamA, n, n);
			FixMatrix(FixA, a, n, n);
			cout << "Result Of Paein Mosalasi:\n";
			if (PaeinMosalasiMatrix(IntA, n))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		else if (Choose == 7)
		{
			cout << "Starting From 0\n";
			int x;
			cout << "Satr: ";
			cin >> n;
			cout << "Soton: ";
			cin >> m;
			cout << "Enter a Satr: ";
			cin >> x;
			cout << "Enter Matrix:\n";
			ScanMatrix(a, n, m);
			FixMatrix(a, FixA, n, m);
			IntMatrix(a, IntA, n, m);
			FixMatrix(FixA, a, n, m);
			IntRaqamMatrix(a, IntRaqamA, n, m);
			FixMatrix(FixA, a, n, m);
			RemoveSatr(IntA, IntRaqamA, x, n, m);
			n--;
			cout << "Result Of Remove Satr:\n";
			PrintMatrix(IntA, IntRaqamA, n, m);
		}
		else if (Choose == 8)
		{
			cout << "Starting From 0\n";
			int x;
			cout << "Satr: ";
			cin >> n;
			cout << "Soton: ";
			cin >> m;
			cout << "Enter a Soton: ";
			cin >> x;
			cout << "Enter Matrix:\n";
			ScanMatrix(a, n, m);
			FixMatrix(a, FixA, n, m);
			IntMatrix(a, IntA, n, m);
			FixMatrix(FixA, a, n, m);
			IntRaqamMatrix(a, IntRaqamA, n, m);
			FixMatrix(FixA, a, n, m);
			RemoveSoton(IntA, IntRaqamA, x, n, m);
			m--;
			cout << "Result Of Remove Soton:\n";
			PrintMatrix(IntA, IntRaqamA, n, m);
		}
		else if (Choose == 9)
		{
			cout << "Satr: ";
			cin >> n;
			cout << "Soton: ";
			cin >> m;
			cout << "Enter Matrix:\n";
			ScanMatrix(a, n, m);
			FixMatrix(a, FixA, n, m);
			IntMatrix(a, IntA, n, m);
			FixMatrix(FixA, a, n, m);
			IntRaqamMatrix(a, IntRaqamA, n, m);
			FixMatrix(FixA, a, n, m);
			TaraMatrix(IntA, IntRaqamA, m);
			cout << "Result Of Taranahade Matrix:\n";
			PrintMatrix(IntA, IntRaqamA, m, n);
		}
		else
			cout << "\t:|\n";
	}
	return 0;
}
//----------------------------------------------------------------------------------------------//
int Raqam(int n) //تعداد رقم
{
	int i = 0;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return i;
}
//----------------------------------------------------------------------------------------------//
void ScanMatrix(int a[100][100], int n, int m) //گرفتن ماتریس
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3 * m; j++)
			cin >> a[i][j];
}
//----------------------------------------------------------------------------------------------//
void PrintMatrix(int a[100][100], int Raqam[100][100], int n, int m) //نمایش ماتریس
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] / pow(10, Raqam[i][j]) << "\t";
		}
		cout << "\n";
	}
}
//----------------------------------------------------------------------------------------------//
void IntMatrix(int a[100][100], int b[100][100], int n, int m) //عدد بدون در نظر گرفتن اعشار
{
	int x;
	for (int i = 0; i < n; i++)
	{
		x = 0;
		for (int j = 0; j < 3 * m; j++)
			if (j % 3 == 0)
			{
				for (int k = 0; k < a[i][j + 1]; k++)
				{
					a[i][j] = a[i][j] * 10;
				}
				for (int k = 0; k < Raqam(a[i][j + 2]); k++)
				{
					a[i][j] = a[i][j] * 10;
				}
				a[i][j] = a[i][j] + a[i][j + 2];
				b[i][x] = a[i][j];
				x++;
			}
	}
}
//----------------------------------------------------------------------------------------------//
void IntRaqamMatrix(int a[100][100], int b[100][100], int n, int m) //تعداد رقم اعشار
{
	int x;
	for (int i = 0; i < n; i++)
	{
		x = 0;
		for (int j = 0; j < 3 * m; j++)
			if (j % 3 == 0)
			{
				a[i][j] = a[i][j + 1] + Raqam(a[i][j + 2]);
				b[i][x] = a[i][j];
				x++;
			}
	}
}
//----------------------------------------------------------------------------------------------//
void FixMatrix(int a[100][100], int b[100][100], int n, int m) //سیو کردن ماتریس
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3 * m; j++)
			b[i][j] = a[i][j];
}
//----------------------------------------------------------------------------------------------//
void ImpNumbers(int IntRaqamA[][100], int IntRaqamB[][100], int IntRaqamC[][100], int IntA[][100], int IntB[][100], int n, int m)
{
	//لازمه انجام عملیات جمع و تفریق
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (IntRaqamA[i][j] >= IntRaqamB[i][j])
			{
				IntB[i][j] = IntB[i][j] * pow(10, (IntRaqamA[i][j] - IntRaqamB[i][j]));
				IntRaqamC[i][j] = IntRaqamA[i][j];
			}
			else if (IntRaqamA[i][j] < IntRaqamB[i][j])
			{
				IntA[i][j] = IntA[i][j] * pow(10, (IntRaqamB[i][j] - IntRaqamA[i][j]));
				IntRaqamC[i][j] = IntRaqamB[i][j];
			}
			/*else
			{
			IntRaqamC[i][j] = IntRaqamA[i][j];
			}*/
		}
	}
}
//----------------------------------------------------------------------------------------------//
void PlusMatrix(int a[][100], int b[][100], int c[][100], int n, int m) //جمع ماتریس
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			c[i][j] = a[i][j] + b[i][j];
}
//----------------------------------------------------------------------------------------------//
void MinusMatrix(int a[][100], int b[][100], int c[][100], int n, int m) //تفریق ماتریس
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			c[i][j] = a[i][j] - b[i][j];
}
//----------------------------------------------------------------------------------------------//
void ZarbNumber(int a[100][100], int x, int n, int m) //ضرب عدد در ماتریس
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = a[i][j] * x;
}
//----------------------------------------------------------------------------------------------//
void RemoveSoton(int a[100][100], int b[100][100], int x, int n, int m) //حذف ستون
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (j >= x)
			{
				a[i][j] = a[i][j + 1];
				b[i][j] = b[i][j + 1];
			}
	m--;
}
//----------------------------------------------------------------------------------------------//
void RemoveSatr(int a[100][100], int b[100][100], int x, int n, int m) //حذف سطر
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (i >= x)
			{
				a[i][j] = a[i + 1][j];
				b[i][j] = b[i + 1][j];
			}
	n--;
}
//----------------------------------------------------------------------------------------------//
int PaeinMosalasiMatrix(int a[100][100], int n) //پایین مثلثی
{
	int x = 1;
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i && x; j--)
			if (a[i][j] == 0)
				x = 1;
			else
				x = 0;
	return x;
}
//----------------------------------------------------------------------------------------------//
int BalaMosalasiMatrix(int a[100][100], int n) //بالا مثلثی
{
	int x = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i && x; j++)
			if (a[i][j] == 0)
				x = 1;
			else
				x = 0;
	return x;
}
//----------------------------------------------------------------------------------------------//
void TaraMatrix(int a[100][100], int b[100][100], int m) //ترانهاده ماتریس
{
	for (int i = 0; i <= m; i++)
		for (int j = 0; j < i; j++)
		{
			swap(a[i][j], a[j][i]);
			swap(b[i][j], b[j][i]);
		}
}
//----------------------------------------------------------------------------------------------//
void MultiMatrix(int IntA[100][100], int IntB[100][100], int c[100][100], int IntRaqamA[][100], int IntRaqamB[][100], int IntRaqamC[][100], int n, int m, int p)
{
	//ضرب ماتریس

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < p;j++)
		{
			int Result = 0, x = 0, max = -999999;
			for (int k = 0;k < m;k++)
			{
				x = IntRaqamA[i][k] + IntRaqamB[k][j];
				if (x > max)
					max = x;
			}
			for (int k = 0;k < m;k++)
			{
				x = IntRaqamA[i][k] + IntRaqamB[k][j];
				if (max >= x)
				{
					Result = Result + (IntA[i][k] * IntB[k][j]) * pow(10, (max - x));
				}
			}
			c[i][j] = Result;
			IntRaqamC[i][j] = max;
		}
	}
}