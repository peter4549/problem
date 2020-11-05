#include <cstdio>

#define MAX(a, b) a > b ? a : b

int N;
int stairs[300];
int dp[300];

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
		scanf("%d", &stairs[i]);

	dp[0] = stairs[0];
	dp[1] = MAX(dp[0] + stairs[1], stairs[1]);
	dp[2] = MAX(dp[0] + stairs[2], stairs[1] + stairs[2]);

	for (int i = 3; i < N; ++i)
		dp[i] = MAX(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);

	printf("%d", dp[N - 1]);

	return 0;
}
