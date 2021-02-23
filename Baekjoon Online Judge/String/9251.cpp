#include <iostream>
#include <string>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

int table[1001][1001];

int main() {
	int length(0);
	string s1, s2;
	cin >> s1 >> s2;

	s1 = "0" + s1;
	s2 = "0" + s2;

	for (int i(1); i < s1.length(); ++i) {
		int k(0);

		for (int j(1); j < s2.length(); ++j) {
			if (s1[i] == s2[j]) {
				k = table[i - 1][j - 1] + 1;
				table[i][j] = k;
			}
			else {
				if (table[i - 1][j] > table[i][j - 1])
					table[i][j] = table[i - 1][j];
				else
					table[i][j] = table[i][j - 1];
			}
		}

		length = MAX(length, k);
	}

	cout << length;

	return 0;
}
