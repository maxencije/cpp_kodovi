#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using tacka = pair<int, int>;

int vektorski(tacka a, tacka b) {
  return a.first * b.second - a.second * b.first; 
}

tacka vektor(tacka a, tacka b) {
  return {b.first - a.first, b.second - a.second};
}

int orijentacija(tacka a, tacka b, tacka c) {
  return vektorski(vektor(a, b), vektor(a, c));
}

bool unutarUgla(tacka a, tacka b, tacka c, tacka d) {
  if(orijentacija(a, b, c) < 0)
    swap(b, c);
  return orijentacija(a, b, d) >= 0 && orijentacija(a, d, c) >= 0;
}

bool unutarTrougla(tacka a, tacka b, tacka c, tacka d) {
  return unutarUgla(a, b, c, d) && unutarUgla(b, c, a, d);
}

bool pripada_mnogouglu(tacka t, vector<tacka>& p) {
  auto it = lower_bound(p.begin() + 1, p.end, t,
                        [p](tacka a, tacka b) {
                          return orijentacija(p[0], a, b) > 0;
                        });
  if(it == p.end())
    return false;
  int i = it - p.begin();
  return unutarTrougla(p[0], p[i-1], p[i], t);
}

int main() {
  
  int n; cin >> n;
  
  vector<tacka> p[n];
  for(int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    p[i] = {x, y};
  }

  for(int i = 0; i < n; i++)
    cout << p[i].first << ' ' << p[i].second;

  return 0;
}
