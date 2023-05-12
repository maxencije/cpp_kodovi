#include "prefiksno_stablo.h"

void dodaj(Cvor* koren, string& s) {
	for(char c : s) {
		if(koren->prelaz.find(c) == koren->prelaz.end())
			koren->prelaz[c] = new Cvor();
		koren = koren->prelaz[c];
	}
	koren->kraj_reci = true;
}

bool nadji(Cvor* koren, string& s) {
	for(char c : s) {
		if(koren->prelaz.find(c) == koren->prelaz.end())
			return false;
		koren = koren->prelaz[c];
	}
	return koren->kraj_reci;
}

void oslobodi(Cvor* koren) {
	// {'c' : Cvor}
	for(auto podstablo : koren->prelaz)
		oslobodi(podstablo.second);
	delete koren;
}