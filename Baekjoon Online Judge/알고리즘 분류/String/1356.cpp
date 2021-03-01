#include <iostream>
#include <string>

using namespace std;

int main() {
	int m, n;
	string N;

	cin >> N;

	for (int i(1); i < N.size(); ++i) {
		m = 1, n = 1;

		for (int j(0); j < i; ++j)
			m *= N[j] - '0';

		for (int j(i); j < N.size(); ++j)
			n *= N[j] - '0';

		if (m == n) {
			printf("YES \n");
			return 0;
		}
	}

	printf("NO \n");

	return 0;
}
