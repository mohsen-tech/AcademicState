#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define N 100
using namespace std;
// <in.txt> out.txt
bool visited[N];
vector <int> adj[N];
void dfs(int s)
{
	if (visited[s])
		return;
	visited[s] = true;
	cout << s << " ";
	for (auto u : adj[s])
	{
		dfs(u);
	}
}
int main()
{
	int n, src, dest, node;
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
	dfs(node);
	system("pause>0");
	return 0;
}