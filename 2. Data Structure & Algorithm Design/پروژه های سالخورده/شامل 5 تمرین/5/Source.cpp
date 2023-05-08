#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

#define arr2d vector<vector<int>> 
arr2d graph;

void TSP(vector <bool> & node, int currPos, const int & n, int count, int cost, int & ans)
{
	if (count == n && graph[currPos][0])
	{
		ans = min(ans, cost + graph[currPos][0]);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!node[i] && graph[currPos][i])
		{
			node[i] = true;
			TSP(node, i, n, count + 1, cost + graph[currPos][i], ans);
			node[i] = false;
		}
	}
}
void readFromFile(int & n)
{
	ifstream file("TSPnodes.txt");
	if (file.is_open())
	{
		file >> n;
		for (int i = 0; i < n; i++)
		{
			vector <int> temp(n);
			for (int j = 0; j < n; j++)
				file >> temp[j];
			graph.push_back(temp);
		}
		file.close();
	}
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//ios::sync_with_stdio(false), cin.tie(0);

	int n;
	readFromFile(n);

	vector<bool> node(n);
	for (int i = 0; i < n; i++)
		node[i] = false;

	node[0] = true;
	int ans = INT_MAX;
	TSP(node, 0, n, 1, 0, ans);
	cout << ans;

	system("pause>0");
	return 0;
}