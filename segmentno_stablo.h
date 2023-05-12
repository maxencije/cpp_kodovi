#ifndef SEGMENTNO_STABLO_H
#define SEGMENTNO_STABLO_H

#include <vector>

using namespace std;

int velicina(int n);
vector<int> napravi_stablo(vector<int>& niz, int n);
int upit(int l, int r, vector<int>& stablo, int n);
void postavi(int i, int x, vector<int>& stablo, int n);
void uvecaj(int i, int x, vector<int>& stablo, int n);

#endif