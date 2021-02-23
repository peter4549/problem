#include <cstdio>

int main() {
	int T, C;
	scanf("%d", &T);

	for (int i(0); i < T; ++i) {
		int quarter(0), dime(0), nickel(0), penny(0);

		scanf("%d", &C);

		while (C - 25 >= 0) {
			C -= 25;
			++quarter;
		}

		while (C - 10 >= 0) {
			C -= 10;
			++dime;
		}

		while (C - 5 >= 0) {
			C -= 5;
			++nickel;
		}

		while (C - 1 >= 0) {
			C -= 1;
			++penny;
		}

		printf("%d %d %d %d \n", quarter, dime, nickel, penny);
	}

	return 0;
}
