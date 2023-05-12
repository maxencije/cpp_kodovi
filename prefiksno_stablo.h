#ifndef PREFIKSNO_STABLO_H
#define PREFIKSNO_STABLO_H

#include <map>
#include <string>

using namespace std;

struct Cvor {
	bool kraj_reci = 0;
	map<char, Cvor*> prelaz;
};

void dodaj(Cvor* koren, string& s);
bool nadji(Cvor* koren, string& s);
void oslobodi(Cvor* koren);

#endif