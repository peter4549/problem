#include <cstdio>

#define MAX(a, b) a > b ? a : b

int N;
int T[15], P[15];
int cache[15];

int solve(int day) {
	if (day > N)
		return -160000;
	if (day == N)
		return 0;

	if (cache[day] != -1)
		return cache[day];

	cache[day] = MAX(solve(day + 1), solve(day + T[day]) + P[day]);
	return cache[day];
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &T[i], &P[i]);
		cache[i] = -1;
	}

	printf("%d", solve(0));

	return 0;
}
