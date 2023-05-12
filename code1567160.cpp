#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string x, y;
	cin >> x >> y;

	int len1 = x.length(), len2 = y.length();

	vector<int64_t> tmp(len2 + 1, 0);
	tmp[0] = 1;

	for(int i = 0; i < len1; i++)
		for(int j = len2; j > 0; j--)
			if(x[i] == y[j-1])
				tmp[j] += tmp[j-1];


	cout << tmp[len2] << '\n';

	return 0;
}