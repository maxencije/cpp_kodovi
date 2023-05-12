#include <iostream>
#include <set>

using namespace std;

set<int64_t> s;

void raspon(int64_t a, int64_t b) {
    
    auto donja_granica = s.lower_bound(a);
    auto gornja_granica = s.lower_bound(b);
    
    if(*gornja_granica != b)
        gornja_granica--;
    
    if(donja_granica == s.end() || *donja_granica >= b) {
        cout << '0' << '\n';
        return;
    }
    
    cout << *gornja_granica - *donja_granica << '\n';
    return;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while(n--) {
        int64_t a, b, x;
        char c;
        cin >> c;
        
        if(c == 't') {
            cin >> x;
            s.insert(x);
        } else if(c == 'i') {
            cin >> a >> b;
            raspon(a, b);
        }
    }
    
    return 0;
}