#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <tuple>
#include <algorithm>

using namespace std;

using edge = pair<int, int>;

void dijkstra(int u, vector<int>& _udaljenost, vector<int>& _prethodnik, vector< vector<edge> >& graf) {
	int n = graf.size();

	vector<int> udaljenost(n, numeric_limits<int>::max());
	vector<int> prethodnik(n, -1);
	set< pair<int, int> > pq;

	pq.insert({udaljenost[u] = 0, u});
	prethodnik[u] = -1;

	while(!pq.empty()) {
		int v = pq.begin()->second;
		pq.erase(pq.begin());

		for(auto e : graf[v]) {
			int w, duzina; tie(w, duzina) = e;
			if(udaljenost[v] + duzina < udaljenost[w]) {
				pq.erase({udaljenost[w], w});
				udaljenost[w] = udaljenost[v] + duzina;
				prethodnik[w] = v;
				pq.insert({udaljenost[w], w});
			}
		}
	}

	_udaljenost = udaljenost;
	_prethodnik = prethodnik;
}

// Rekonstruise put od cvora u (za koji smo pokrenuli dijkstru) do cvora v
vector<int> put(int v, vector<int>& prethodnik) {
	vector<int> p;
	while(v != -1) {
		p.push_back(v);
		v = prethodnik[v];
	}
	reverse(p.begin(), p.end());
	return p;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector< vector<edge> > graf(n);
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graf[u].push_back({v, w});
	}

	vector<int> d, p;
	dijkstra(0, d, p, graf);

	// Ispisujemo duzinu najkraceg puta od 0 do 1
	cout << d[1] << '\n';
	// Ispisujemo najkraci put od 0 do 1
	vector<int> put_0_1 = put(1, p);
	for(int v : put_0_1)
		cout << v << ' ';
	cout << '\n';

	return 0;
}