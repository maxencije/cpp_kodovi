#include <iostream>
#include <vector>

using namespace std;

int main() {

    unsigned p;
    unsigned long k, n;
    
    cin >> p >> k >> n;
    
    vector<unsigned> partije(n);
    for(unsigned long i = 0; i < n; i++)
        cin >> partije[i];
    
    unsigned long sjajna_partija = 0;
    
    for(unsigned long i = 0; i < n; i++) {
        
        if(partije[i] >= p)
            sjajna_partija++;
        else
            sjajna_partija = 0;
        
        if(sjajna_partija >= k) {
            cout << "da\n";
            return 0;
        }
        
    }
    
    cout << "ne\n";
    
    return 0;
}