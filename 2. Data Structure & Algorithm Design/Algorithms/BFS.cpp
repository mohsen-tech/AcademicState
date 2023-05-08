#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define N 100
using namespace std;
// <in.txt> out.txt
int main()
{
	int n, src, dest, node;
	vector <int> adj[N];
	bool visited[N] = { false };
	int distance[N];
	queue <int> q;
	// cout << "enter number of edge: ";
	cin >> n;
	// cout << "\node src  node dest\n";
	for (int i = 0; i < n; i++)
	{
		cin >> src >> dest;
		adj[src].push_back(dest);
	}
	// cout << "enter node to process: ";
	cin >> node;
	visited[node] = true;
	distance[node] = 0;
	q.push(node);
	while (!q.empty())
	{
		int s = q.front();
		q.pop();
		//
		for (auto u : adj[s])
		{
			if (visited[u])
				continue;
			visited[u] = true;
			distance[u] = distance[s] + 1;
			q.push(u);
		}
	}
	for (int i = 0; i <= n; i++)
		if (visited[i])
			cout << i << " " << distance[i] << "\n";
	system("pause>0");
	return 0;
}