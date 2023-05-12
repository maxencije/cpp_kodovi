#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int m, n;
	cin >> m >> n;

	vector<vector<int>> p(m, vector<int>(n));
    
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> p[i][j];

    for(int i = 1; i < n; i++)
        if(p[0][i] > p[0][i-1])
            p[0][i] = p[0][i-1];
    
    for(int i = 1; i < m; i++)
        if(p[i][0] > p[i-1][0])
            p[i][0] = p[i-1][0];
        
    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            p[i][j] = min({p[i][j], p[i][j-1], p[i-1][j]});
    
    for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			cout << p[i][j] << ' ';
        cout << '\n';
    }
        
	return 0;
}