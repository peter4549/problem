#include <cstdio>
#include <cstring>

int count_zero(int n, int dp[][41]) {
	if (n == 0)
		return 1;

	if (n == 1)
		return 0;
	
	if (dp[0][n] != -1)
		return dp[0][n];

	dp[0][n] = count_zero(n - 1, dp) + count_zero(n - 2, dp);

	return dp[0][n];
}

int count_one(int n, int dp[][41]) {
	if (n == 1)
		return 1;

	if (n == 0)
		return 0;

	if (dp[1][n] != -1)
		return dp[1][n];

	dp[1][n] = count_one(n - 1, dp) + count_one(n - 2, dp);

	return dp[1][n];
}

int main() {
	int dp[2][41] = { -1, };
	memset(dp, -1, sizeof(dp));
	
	int T;
	scanf("%d", &T);

	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i(0); i < T; ++i) {
		int N;
		scanf("%d", &N);
		printf("%d %d \n", count_zero(N, dp), count_one(N, dp));
	}

	return 0;
}
