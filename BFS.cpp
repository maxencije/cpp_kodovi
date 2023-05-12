#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int u, vector< vector<int> >& g) {
	vector<bool> p(g.size());
	p[u] = true;

	queue<int> q;
	q.push(u);

	while(!q.empty()) {
		int t = q.front(); q.pop();
		cout << t << ' ';

		for(int v : g[t])
			if(!p[v]) {
				p[v] = true;
				q.push(v);
			}
	}
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

	bfs(0, g);

	return 0;
}