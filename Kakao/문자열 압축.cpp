#include <iostream>
#include <string>

#define MIN(a, b) (a < b ? a : b)

using namespace std;

int main() {
	int min(1001);
	string s;

	cin >> s;

	if (s.size() < 2) {
		cout << s;
		return 0;
	}

	for (int i(1); i <= s.size() / 2; ++i) {
		int j(0), n(1), m(0);
		string b = "";

		while (j <= s.size()) {
			string a = s.substr(j, i);
			
			if (a == b)
				++n;
			else if (b != "") {
				if (n > 1)
					m += i + to_string(n).size();
				else
					m += i;

				n = 1;

				if (a.size() < i)
					m += a.size();
			}
				
			b = a;
			j += i;
		}

		min = MIN(min, m);
	}

	printf("%d", min);

	return 0;
}
