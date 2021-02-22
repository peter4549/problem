#include <cstdio>
#include <cstring>

#define MAX(a, b) (a > b ? a : b)

int dp[501][501], triangle[501][501];

int get(int n, int m) {
	if (dp[n][m] != -1)
		return dp[n][m];

	return dp[n][m] = MAX(get(n + 1, m), get(n + 1, m + 1)) + triangle[n][m];
}

int main() {
	int n;
	scanf("%d", &n);

	memset(dp, -1, sizeof(dp));

	for (int i(1); i <= n; ++i)
		for (int j(1); j <= i; ++j)
			scanf("%d", &triangle[i][j]);
	
	for (int i(1); i <= n; ++i)
		dp[n][i] = triangle[n][i];

	printf("%d", get(1, 1));

	return 0;
}
