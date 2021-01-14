#include <cstdio>

int main() {
	int N, sum(0);
	int dp[1001][10] = { 0, };

	scanf("%d", &N);

	for (int i(0); i < 10; ++i)
		dp[0][i] = 1;

	for (int i(1); i < N; ++i)
		for (int j(0); j < 10; ++j)
			for (int k(j); k < 10; ++k) 
			    dp[i][j] += dp[i - 1][k] % 10007;
		
	for (int i(0); i < 10; ++i)
		sum += dp[N - 1][i];

	printf("%d", sum % 10007);

	return 0;
}
