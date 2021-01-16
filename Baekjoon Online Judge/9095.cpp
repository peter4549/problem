#include <cstdio>

int dp[11];

int main() {
	int T;
	scanf("%d", &T);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i(4); i < 11; ++i)
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

	for (int t(0); t < T; ++t) {
		int n;
		scanf("%d", &n);
		printf("%d \n", dp[n]);
	}

	return 0;
}
