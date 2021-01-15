#include <cstdio>

#define Max(a, b) (a > b ? a : b)

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

int n, max;
int forest[501][501];
int dp[501][501];

int dfs(int y, int x) {
	if (dp[y][x])
		return dp[y][x];

	dp[y][x] = 1;

	for (int d(0); d < 4; ++d) {
		int ny(y + dy[d]);
		int nx(x + dx[d]);
		
		if (0 > ny || ny >= n || 0 > nx || nx >= n)
			continue;
		
		if (forest[ny][nx] <= forest[y][x])
			continue;

		dp[y][x] = Max(dp[y][x], dfs(ny, nx) + 1);
	}

	return dp[y][x];
}

int main() {
	scanf("%d", &n);

	for (int i(0); i < n; ++i)
		for (int j(0); j < n; ++j)
			scanf("%d", &forest[i][j]);

	for (int i(0); i < n; ++i)
		for (int j(0); j < n; ++j) {
			max = Max(max, dfs(i, j));
		}

	printf("%d", max);

	return 0;
}
