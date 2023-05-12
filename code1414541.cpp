#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    uint64_t k;
    cin >> k;
    
    set<uint64_t> p;
    
    for(uint64_t i = 2; i < k ; i++)
        for(uint64_t j = 2; pow(j, i) < k*k ; j++)
            p.insert(pow(j, i));

    uint64_t tmp = 0;
    for(auto it : p) {
        if(tmp == k) {
            cout << it << '\n';
            break;
        }
        tmp++;
    }

    return 0;
}