#include <cstdio>

#define MIN(a, b) (a > b ? b : a)

int N;
int costs[1001][3], dp[1001][3];

int main() {
	scanf("%d", &N);

	for (int i(1); i <= N; ++i)
		for (int j(0); j < 3; ++j)
			scanf("%d", &costs[i][j]);

	for (int i(1); i <= N; ++i) {
		dp[i][0] = MIN(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
		dp[i][1] = MIN(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
		dp[i][2] = MIN(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
	}

	printf("%d", MIN(MIN(dp[N][0], dp[N][1]), dp[N][2]));

	return 0;
}
