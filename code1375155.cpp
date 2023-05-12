#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    
    unsigned k, n;
    
    cin >> k >> n;
    
    map<string, int> p;
    map<string, bool> q;
    
    int broj = 0;
    while(n--) {
        string ime;
        cin >> ime;
        
        p[ime]++;
        
        if(p[ime] >= k && q[ime] == false) {
            broj++;
            q[ime] = true;
        }
        cout << broj << '\n';
    }
    
    return 0;
}