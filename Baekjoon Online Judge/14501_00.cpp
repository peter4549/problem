#include <cstdio>

#define Max(a, b) (a > b ? a : b)

int N;
int T[15], P[15];
int cache[15];

int dp(int day) {
	if (day > N)
		return -16000;
	
	if (day == N)
		return 0;
	
	if (cache[day] != -1)
		return cache[day];

	cache[day] = Max(dp(day + 1), dp(day + T[day]) + P[day]);
	return cache[day];
}

int main() {
	scanf("%d", &N);

	for (int i(0); i < N; ++i) {
		scanf("%d %d", &T[i], &P[i]);
		cache[i] = -1;
	}

	printf("%d", dp(0));

	return 0;
}
