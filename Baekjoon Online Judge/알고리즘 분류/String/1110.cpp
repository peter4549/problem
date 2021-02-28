#include <cstdio>

int N;

int solve(int n, int k) {
	int m(0);

	if (n < 10) {
		m = 11 * n;

		if (N == m)
			return k;
	} else {
		int a(n / 10);
		int b(n % 10);
		int c(a + b);
		int d(c % 10);

		m = (b * 10 + d);

		if (N == m)
			return k;
	}

	return solve(m, k + 1);
}

int main() {
	scanf("%d", &N);		

	printf("%d \n", solve(N, 1));

	return 0;
}
