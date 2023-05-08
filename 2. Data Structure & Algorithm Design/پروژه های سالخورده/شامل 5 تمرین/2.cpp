#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <iomanip>
using namespace std;
// <in.txt> out.txt

#define N 5
#define MAX 9999
#define arr2d vector<vector<float>>

const char * OUTPUT_FILE = "RandomGraph.txt";

int minPRIME_MST(const vector <float> & key, const vector <bool> & visited, const int & n)
{
	int min = MAX, minIndex;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false && key[i] < min)
		{
			min = key[i];
			minIndex = i;
		}
	}
	return minIndex;
}
void PRIME_MST(const arr2d & graph, const int & n)
{
	vector <int> parent(n);
	vector <float> key(n);
	vector <bool> visited(n);

	for (int i = 0; i < n; i++)
	{
		key[i] = MAX;
		visited[i] = false;
		parent[i] = -1;
	}
	key[0] = 0;
	parent[0] = -1;
	for (int i = 0; i < n; i++)
	{
		int u = minPRIME_MST(key, visited, n);
		visited[u] = true;

		for (int j = 0; j < n; j++)
		{
			if (graph[u][j] != 0 && visited[j] == false && graph[u][j] < key[j])
			{
				parent[j] = u;
				key[j] = graph[u][j];
			}
		}
	}
	float totalCost = 0;
	for (int i = 1; i < n; i++)
		totalCost += graph[i][parent[i]];
	cout << "[PRIME_MST]   Total cost is: " << totalCost << "\n";
}
//-------------------------------------------------------------------------------------
int findKRUSKAL_MST(const vector <int> & parent, int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}
void unionKRUSKAL_MST(vector <int> & parent, const int & i, const int & j)
{
	int a = findKRUSKAL_MST(parent, i);
	int b = findKRUSKAL_MST(parent, j);
	parent[a] = b;
}
void KRUSKAL_MST(arr2d & graph, const int & n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (graph[i][j] == 0)
				graph[i][j] = MAX;

	vector <int> parent(n);
	float totalCost = 0;
	for (int i = 0; i < n; i++)
		parent[i] = i;

	int edge_count = 0;
	while (edge_count < n - 1)
	{
		float min = MAX;
		int a = -1, b = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (findKRUSKAL_MST(parent, i) != findKRUSKAL_MST(parent, j) && graph[i][j] < min)
				{
					min = graph[i][j];
					a = i;
					b = j;
				}
			}
		}
		unionKRUSKAL_MST(parent, a, b);
		edge_count++;
		totalCost += min;
	}
	cout << "[KRUSKAL_MST] Total cost is: " << totalCost << "\n";
}
//-------------------------------------------------------------------------------------
void getNumbers(arr2d & graph, const int & len)
{
	ifstream file(OUTPUT_FILE);
	int n = rand() % len + len, cnt = 0;
	while (cnt < n)
	{
		int i, j;
		float w;
		file >> i >> j >> w;
		if (i != j && graph[i][j] == MAX && i < len && j < len)
		{
			graph[i][j] = graph[j][i] = w;
			cnt++;
		}
	}
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			if (graph[i][j] == MAX)
				graph[i][j] = 0;

	file.close();
}
void createRandomNumbers(const int & len)
{
	ofstream file(OUTPUT_FILE);
	for (int i = 0; i < len * 50; i++)
	{
		file << rand() % len << " " << rand() % len << " ";
		double temp = (rand() % 20 + rand() % 10) + (double)rand() / RAND_MAX;
		file << temp << "\n";
	}
	file.close();
}
//-------------------------------------------------------------------------------------
int main()
{
	//ios_base::sync_with_stdio(false);
	//ios::sync_with_stdio(false), cin.tie(0);

	unsigned int matrixSize = N;
	srand(time(NULL));
	cout << fixed << setprecision(10);
	createRandomNumbers(matrixSize);

	arr2d graph(matrixSize, vector<float>(matrixSize, MAX));
	getNumbers(graph, matrixSize);

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
			cout << graph[i][j] << "\t";
		cout << "\n";
	}

	clock_t tStart;
	cout << "\nmatrixSize (" << matrixSize << " * " << matrixSize << ") \n\n";

	tStart = clock();
	PRIME_MST(graph, matrixSize);
	cout << "PRIME_MST (sec): " << (double)(clock() - tStart) / CLOCKS_PER_SEC << "\n\n";
	//----------------------------------------------------------------------------------------------------------------------------------------------------
	tStart = clock();
	KRUSKAL_MST(graph, matrixSize);
	cout << "KRUSKAL_MST (sec): " << (double)(clock() - tStart) / CLOCKS_PER_SEC << "\n\n";

	system("pause>0");
	return 0;
}