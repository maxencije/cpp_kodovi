#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, vector<bool>& p, vector< vector<int> >& g) {
	p[u] = true;
	cout << u << ' ';
	for(int v : g[u])
		if(!p[v])
			dfs(v, p, g);
}

int main() {
	int n, m;
	cin >> n >> m;

	vector< vector<int> > g(n);

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<bool> posecen(n);
	dfs(0, posecen, g);

	return 0;
}