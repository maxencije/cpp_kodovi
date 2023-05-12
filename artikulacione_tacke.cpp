#include <iostream>
#include <vector>

using namespace std;

int dfs(int u, int p, int& c, vector<int>& num, vector< vector<int> >& graf) {	
	int low = num[u] = ++c, br = 0;
	bool ap = false;
	for(int v : graf[u])
		if(num[v] == 0) {
			int low_v = dfs(v, u, c, num, graf);

			if(p != -1 && low_v >= num[u])
				ap = true;

			low = min(low, low_v);
			br++;
		}
		else if(v != p)
			low = min(low, num[v]);
	if(ap || (p == -1 && br > 0))
		cout << u << ' ';
	return low;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector< vector<int> > graf(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graf[u].push_back(v);
		graf[v].push_back(u);
	}

	vector<int> num(n);
	int c = 0;
	dfs(0, -1, c, num, graf);
	cout << '\n';

	return 0;
}