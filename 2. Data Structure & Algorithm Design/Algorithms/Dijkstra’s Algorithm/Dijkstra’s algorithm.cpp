#include <iostream>
#include <vector>
#include <queue>
#define INF 999999
#define N 101
using namespace std;
int main()
{
	vector <pair<int, int>> adj[N];
	queue <pair<int, int>> q;
	bool processed[N] = { false };
	int distance[N] = { 0 };

	int n, src, dest, node, weight;
	cout << "Enter Number Of Edge: ";
	cin >> n;
	cout << "\nNode Src\tNode Dest\tWeight\n";
	for (int i = 0; i < n; i++)
	{
		cin >> src >> dest >> weight;
		adj[src].push_back({ dest, weight });
	}

	cout << "Enter Node To Process: ";
	cin >> node;

	for (int i = 1; i <= n; i++)
		distance[i] = INF;

	distance[node] = 0;
	q.push({ 0 , node });

	int cnt = 0;

	while (!q.empty())
	{
		int a = q.front().second;
		q.pop();
		if (processed[a])
			continue;
		processed[a] = true;
		for (auto u : adj[a])
		{
			int b = u.first, w = u.second;
			if (distance[a] + w < distance[b])
			{
				distance[b] = distance[a] + w;
				q.push({ -distance[b],b });
				cnt++;
			}
		}
	}
	cout << "\nDijkstras Algorithm Is:\n\n";
	cout << "Node:\tWeight:\n";
	for (size_t i = 0; i <= cnt + 2; i++)
	{
		if (distance[i] == INF)
		{
			cout << node << "\t" << 0 << "\n";
			break;
		}
	}
	for (size_t i = 0; i <= cnt + 2; i++)
		if (distance[i] != 0 && distance[i] != INF)
			cout << i << "\t" << distance[i] << "\n";

	system("pause>0");
	return 0;
}