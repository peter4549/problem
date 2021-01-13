#include <cstdio>

#define Max(a, b) (a > b ? a : b)

int n;
int A[10003];
int dp[10003];

int main() {
	int max(0);

	scanf("%d", &n);

	for (int i(3); i < n + 3; ++i)
		scanf("%d", A + i);

	for (int i(3); i < n + 3; ++i) {
		dp[i] = Max(dp[i - 3] + A[i - 1], dp[i - 2]) + A[i];
		dp[i] = Max(dp[i - 1], dp[i]);
		max = Max(max, dp[i]);
	}

	printf("%d", max);

	return 0;
}
