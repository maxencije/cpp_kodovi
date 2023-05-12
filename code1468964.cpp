#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int najbliza_reklama(vector<int>& reklame, int x) {
    int l = 0, n = reklame.size(), d = n - 1;
    
    if(reklame[d] < x)
        return najbliza_reklama(reklame, reklame[d]);
    
    while(l <= d) {
        int s = l + (d-l)/2;
        
        if(reklame[s] < x)
            l = s + 1;
        else
            d = s - 1;
    }
    
    if(l > 0) {
        int razlika = abs(reklame[l] - x);
        int nova_razlika = abs(reklame[l-1] - x);
        if(razlika < nova_razlika)
            return l;
        else
            return najbliza_reklama(reklame, reklame[l-1]);
    } else
        return l;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n, x;
    cin >> n;
    
    vector<int> reklame(n);
    for(int i = 0; i < n; i++)
        cin >> reklame[i];
    
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> x;
        
        cout << najbliza_reklama(reklame, x) << '\n';
    }
    
    return 0;
}