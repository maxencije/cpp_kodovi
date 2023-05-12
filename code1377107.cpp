#include <iostream>
#include <stack>

using namespace std;

int main()
{
    
    string s;
    cin >> s;
    
    stack<char> p;
    
    unsigned len = s.size();
    
    for(unsigned i = 0; i < len; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            p.push(s[i]);
        
        if(s[i] == ')' && !s.empty()) {
            if(p.top() == '(')
                p.pop();
            else {
                cout << "ne\n";
                return 0;
            }
        }
        
        if(s[i] == ']' && !s.empty()) {
            if(p.top() == '[')
                p.pop();
            else {
                cout << "ne\n";
                return 0;
            }
        }
        
        if(s[i] == '}' && !s.empty()) {
            if(p.top() == '{')
                p.pop();
            else {
                cout << "ne\n";
                return 0;
            }
        }
    }
    
    if(p.empty())
        cout << "da\n";
    else
        cout << "ne\n";

    return 0;
}