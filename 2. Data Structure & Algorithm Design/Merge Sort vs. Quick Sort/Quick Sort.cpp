#include<iostream>
using namespace std;
void quicksort(int[], int, int);
int part(int[], int, int);
int main()
{
	int a[9];
	for (int i = 0; i < 9; i++)
		cin >> a[i];
	quicksort(a, 0, 8);
	for (int i = 0; i < 9; i++)
		cout << a[i] << '\t';
	system("pause");
}
void quicksort(int a[], int l, int r)
{
	int j;
	if (l < r)
	{
		j = part(a, l, r);
		quicksort(a, l, j - 1);
		quicksort(a, j + 1, r);
	}
}
int part(int a[], int l, int r)
{
	int pivet, i, j, t;
	pivet = a[l];
	i = l;
	j = r + 1;
	while (1)
	{
		do ++i; while (a[i] <= pivet&&i <= r);
		do --j; while (a[j] > pivet);
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	swap(a[l], a[j]);
	return j;
}