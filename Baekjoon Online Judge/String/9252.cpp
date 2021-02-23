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

	cout << length << endl;

	if (!length)
		return 0;

	int a(length);
	int b(a - 1), k(s2.length() - 1);
	string LCS("");

	for (int i(s1.length() - 1); i > 0; --i) {
		for (int j = k; j > 0; --j) {
			if (table[i][j] == a &&
				table[i][j - 1] == b &&
				table[i - 1][j - 1] == b && 
				table[i - 1][j] == b) {
				a--;
				b--;
				LCS = s1[i] + LCS;
				k = j;
				break;
			}
		}
	}

	cout << LCS;

	return 0;
}
