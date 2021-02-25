#include <cstdio>

#define MAX(a, b) (a > b ? a : b)

int N, T[15], P[15], cache[15];

int solve(int i) {
	if (i > N)
		return -15000;

	if (i == N)
		return 0;

	if (cache[i] != -1)
		return cache[i];

	cache[i] = MAX(solve(i + 1), solve(i + T[i]) + P[i]);
	return cache[i];
}

int main() {
	scanf("%d", &N);

	for (int i(0); i < N; ++i) {
		scanf("%d %d", &T[i], &P[i]);
		cache[i] = -1;
	}

	printf("%d", solve(0));

	return 0;
}
