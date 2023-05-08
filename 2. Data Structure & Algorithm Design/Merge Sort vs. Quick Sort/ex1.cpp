#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#define SIZE 100000000
int Data[SIZE], mySize = 1000000;
using namespace std;
void merge(int a[], int l, int m, int r)
{
	int i, j, k, leftSize = m - l + 1, rightSize = r - m, *L = new int[leftSize], *R = new int[rightSize];
	for (i = 0; i < leftSize; i++)
		L[i] = a[l + i];
	for (j = 0; j < rightSize; j++)
		R[j] = a[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < leftSize && j < rightSize)
	{
		if (L[i] <= R[j])
			a[k++] = L[i++];
		else
			a[k++] = R[j++];
	}
	while (i < leftSize)
		a[k++] = L[i++];
	while (j < rightSize)
		a[k++] = R[j++];
	delete[] L;
	delete[] R;
}
void mergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}
int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (a[j] < pivot)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[high]);
	return i + 1;
}
void quickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int p = partition(a, low, high);
		quickSort(a, low, p - 1);
		quickSort(a, p + 1, high);
	}
}
void writeFile(fstream & f)
{
	f << mySize << endl;
	srand(time(NULL));
	for (int i = 0; i < mySize; i++)
		f << rand() % 100000 << endl;
	cout << " - ";
}
void readFile(fstream & f)
{
	f.seekg(0, ios::beg);
	f >> mySize;
	for (int i = 0; i < mySize; i++)
		f >> Data[i];
}
void func()
{
	fstream file;
	streampos begin, end;
	file.open("Data.txt", ios::in | ios::out | ios::app);
	begin = file.tellg();
	file.seekg(0, ios::end);
	end = file.tellg();
	file.seekg(0, ios::beg);
	if (end - begin == 0)
	{
		writeFile(file);
	}
	else
	{
		readFile(file);
		cout << "size = " << mySize << "\n\n";
		clock_t start = clock();
		mergeSort(Data, 0, mySize - 1);
		cout << "MergeSort = " << double(clock() - start) / CLOCKS_PER_SEC << "\n\n";
		readFile(file);
		start = clock();
		quickSort(Data, 0, mySize - 1);
		cout << "QuickSort = " << double(clock() - start) / CLOCKS_PER_SEC << "\n\n";
	}
}
int main()
{
	func();
	system("pause>0");
	return 0;
}