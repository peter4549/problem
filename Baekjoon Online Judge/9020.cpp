#include <cstdio>

bool isPrimeNumber(int n) {
	for (int i(2); i <= n / 2; ++i) {
		if (n % i == 0)
			return false;
	}

	return true;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t(0); t < T; ++t) {
		int n;
		scanf("%d", &n);

		int m = n / 2;

		if (isPrimeNumber(m)) {
			printf("%d %d \n", m, m);
			continue;
		}

		for (int i(1); i < m - 2; ++i) {
			if (isPrimeNumber(m - i) && isPrimeNumber(m + i)) {
				printf("%d %d \n", m - i, m + i);
				break;
			}
		}
	}

	return 0;
}
