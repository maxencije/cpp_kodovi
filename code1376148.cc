#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    unsigned broj_dece;
    cin >> broj_dece;
    
    vector<unsigned> cene(broj_dece);
    for(unsigned i = 0; i < broj_dece; i++)
        cin >> cene[i];
    
    unsigned broj_upita;
    cin >> broj_upita;
    
    vector<pair<unsigned, unsigned>> upiti(broj_upita);
    for(unsigned i = 0; i < broj_upita; i++) {
        unsigned pozicija, budzet;
        cin >> pozicija >> budzet;
        upiti[i] = {pozicija, budzet};
    }
    
    for(unsigned i = 0; i < broj_upita; i++) {
        unsigned j = upiti[i].first, tmp = upiti[i].second;
        unsigned kupljeno = 0;
        while(tmp > cene[j] && j < cene.size()) {
            tmp -= cene[j];
            kupljeno++;
            j++;
        }
        
        cout << kupljeno << '\n';
    }
    
    return 0;
}