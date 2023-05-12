#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;

int main() {

    unsigned n;
    cin >> n;
    
    unsigned ukupno = 0, zbir = 0;
    unsigned min = UINT_MAX, index = 0;
    vector<long> p(n);
    for(unsigned i = 0; i < n; i++) {
        cin >> p[i];
        ukupno += p[i];
    }
    
    for(unsigned i = 0; i < n; i++) {
        zbir += p[i];
        if(labs(ukupno - 2*zbir) < min) {
            min = labs(ukupno - 2*zbir);
            index = i;
        }
    }
    
    cout << index << '\n';
    
    return 0;
}