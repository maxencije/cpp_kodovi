#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    unsigned n;
    cin >> n;
    
    vector<long long> p(n);
    vector<long long> q(n);
    
    for(unsigned i = 0; i < n; i++)
        cin >> p[i];
        
    sort(p.begin(), p.end());
    
    unsigned i = 0, j = n-1;
    
    for(unsigned k = 0; k < n; k++) {
        if(k % 2 == 0)
            q[i++] = p[k];
        else
            q[j--] = p[k];
    }
    
    for(unsigned k = 0; k < n; k++)
        cout << q[k] << '\n';
        
    return 0;
}