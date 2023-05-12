#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;

bool provera(vector<string>& p, int i, int j, int z) {
    for(int k = 0; k < n; k++)
        if(p[i][k] - '0' == z || p[k][j] - '0' == z)
            return false;
        
    return true;
}

void popuni(vector<string>& p, int q) {
    
    //vrsta u kojoj se nalazi polje koje gledamo
    int i = q / n;
    //kolona u kojoj se nalazi polje koje gledamo
    int j = q % n;
    
    //provera da li je polje popunjeno
    if(p[i][j] != '0') {
        
        //da li je rekurzija uspela da dodje do kraja
        //matrice, ako jeste, ispisujemo dobijeno resenje
        if(q + 1 == n*n) {
            for(int x = 0; x < n; x++) {
                for(int y = 0; y < n; y++)
                    cout << p[x][y];
                cout << '\n';
            }
            cout << '\n';
        //ako nismo popunili celu matricu,
        //pozivamo funkciju za index + 1
        } else
            popuni(p, q+1);
    } else {
        //proveravamo posebno za svaku vrednost iz [1, n]
        //da li mozemo da je upisemo na trenutno polje
        for(int z = 1; z <= n; z++)
            //ako provera vrati true, mozemo da 
            //upisemo broj z na polje (i, j) u matrici
            if(provera(p, i, j, z)) {
                p[i][j] = z + '0';
                popuni(p, q);
            }
        //vracamo 0 na trenutnu poziciju da bi sledeci poziv
        //funkcije mogao da razmatra novo resenje (ako postoji)
        p[i][j] = '0';
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    vector<string> p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];
    
    popuni(p, 0);
        
    return 0;
}