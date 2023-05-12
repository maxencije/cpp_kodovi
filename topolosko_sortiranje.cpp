#include <iostream>
#include <vector>

using namespace std;

vector<int> topsort(vector< vector<int> >& graf) {
	int n = graf.size();
	vector<int> indeg(n);
	for(int u = 0; u < n; u++)
		for(int v : graf[u])
			indeg[v]++;

	vector<int> q;
	for(int u = 0; u < n; u++)
		if(indeg[u] == 0)
			q.push_back(u);

	for(int i = 0; i < q.size(); i++) {
		int u = q[i];
		for(int v : graf[u]) {
			indeg[v]--;
			if(indeg[v] == 0)
				q.push_back(v);
		}
	}

	return q;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector< vector<int> > graf(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graf[u].push_back(v);
	}

	vector<int> s = topsort(graf);
	for(int u : s)
		cout << u << ' ';
	cout << '\n';

	return 0;
}