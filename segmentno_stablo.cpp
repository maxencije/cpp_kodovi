#include "segmentno_stablo.h"

#include <vector>
#include <cmath>
#include <iostream>

int velicina(int n) {
	return pow(2, ceil(log2(n)));
}

vector<int> napravi_stablo(vector<int>& niz, int n) {
	vector<int> stablo(2 * n);

	copy(niz.begin(), niz.end(), stablo.begin() + n);
	for(int k = n - 1; k > 0; k--)
		stablo[k] = min(stablo[2 * k], stablo[2 * k + 1]);

	return stablo;
}

int upit(int l, int r, vector<int>& stablo, int n) {
	int najmanji = numeric_limits<int>::max();
	for(l += n, r += n; l <= r; l /= 2, r /= 2) {
		if(l % 2 == 1) najmanji = min(najmanji, stablo[l++]);
		if(r % 2 == 0) najmanji = min(najmanji, stablo[r--]);
	}
	return najmanji;
}

void postavi(int i, int x, vector<int>& stablo, int n) {
	stablo[i += n] = x;
	for(i /= 2; i > 0; i /= 2)
		stablo[i] = min(stablo[2 * i], stablo[2 * i + 1]);
}

void uvecaj(int i, int x, vector<int>& stablo, int n) {
	stablo[i += n] += x;
	for(i /= 2; i > 0; i /= 2)
		stablo[i] = min(stablo[2 * i], stablo[2 * i + 1]);
}
