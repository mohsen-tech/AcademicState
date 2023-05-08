#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#define N 10000000
using namespace std;
// <in.txt> out.txt
bool isEmpty(ifstream & file)
{
	return file.peek() == ifstream::traits_type::eof();
}
void getNumbers(vector <int> & numbers, const int & len) // get numbers from file
{
	ifstream file("RandomNumbers.txt");
	for (int i = 0; i < len; i++)
	{
		file >> numbers[i];
	}
	file.close();
}
void createRandomNumbers() // create numbers to file
{
	ofstream file("RandomNumbers.txt");
	for (int i = 0; i < N; i++)
	{
		int temp = rand();
		file << temp << "\n";
	}
	file.close();
}
void heapify(vector <int> & numbers, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && numbers[l] > numbers[largest])
		largest = l;

	if (r < n && numbers[r] > numbers[largest])
		largest = r;

	if (largest != i)
	{
		swap(numbers[i], numbers[largest]);
		heapify(numbers, n, largest);
	}
}
void heapSort(vector <int> & numbers)
{
	for (int i = numbers.size() / 2 - 1; i >= 0; i--)
	{
		heapify(numbers, numbers.size(), i);
	}
	for (int i = numbers.size() - 1; i > 0; i--)
	{
		swap(numbers[0], numbers[i]);
		heapify(numbers, i, 0);
	}
}
void insertionSort(vector <int> & numbers)
{
	for (int i = 1; i < numbers.size(); i++)
	{
		int temp = numbers[i], j;
		for (j = i - 1; j >= 0 && numbers[j] > temp; j--)
		{
			numbers[j + 1] = numbers[j];
		}
		numbers[j + 1] = temp;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	ifstream ifile("RandomNumbers.txt");
	if (isEmpty(ifile)) // run first time & init numbers to file
	{
		ifile.close();
		createRandomNumbers();
	}
	else
	{
		clock_t tStart;
		cout << "len" << "  |  " << "insertionSort (sec)" << "  |  " << "heapSort (sec)\n";
		for (int len = 100; len < N / 20; len += len / 2)
		{
			vector <int> numbers(len), temp1, temp2;
			getNumbers(numbers, len);
			temp1 = temp2 = numbers;

			tStart = clock();
			insertionSort(temp1);
			cout /*<< "\n"*/ << len << " \t\t";
			cout << fixed << setprecision(10) << (double)(clock() - tStart) / CLOCKS_PER_SEC << "\t\t";

			tStart = clock();
			heapSort(temp2);
			cout << fixed << (double)(clock() - tStart) / CLOCKS_PER_SEC << "\n";
		}
	}
	system("pause>0");
	return 0;
}