#include <iostream>
#include <vector>

using namespace std;

int n, k;

void ispis_rezultata(vector<int> rezultat) {
    for(int i = 0; i < n; i++)
        cout << rezultat[i];
    cout << '\n';
}

void susedi(int popunjeno, vector<int> rezultat) {
    
    if(popunjeno == n) {
        ispis_rezultata(rezultat);
        return;
    }

    if(rezultat[popunjeno - 1] - k >= 0) {
        rezultat[popunjeno] = rezultat[popunjeno - 1] - k;
        susedi(popunjeno + 1, rezultat);
    }
    
    if(rezultat[popunjeno - 1] + k < 10 && k > 0) {
        rezultat[popunjeno] = rezultat[popunjeno - 1] + k;
        susedi(popunjeno + 1, rezultat);
    }
}

void susediOmotac() {
    vector<int> rezultat(n);

    for(int i = 1; i < 10; i++) {
        rezultat[0] = i;
        susedi(1, rezultat);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;

    if(n == 1) {
        for(int i = 1; i < 10; i+=k)
            cout << i << '\n';
        return 0;
    }

    susediOmotac();

    return 0;
        
}