#include <cstdio>

int main()
{
	int N, n, digit(0), M;

	scanf("%d", &N);

	n = N;

	do {
		n = int(n / 10);
		++digit;
	} while (n > 0);

	for (int i = N - 9 * digit; i < N; ++i) {
		M = i;
		n = i;

		while (n > 0) {
			M += n % 10;
			n /= 10;
		}

		if (M == N) {
			printf("%d", i);

			return 0;
		}
	}

	printf("0");

	return 0;
}
