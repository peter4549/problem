#include <cstdio>

#define MAX(a, b) (a > b ? a : b)

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

int N, M, K, k, passage[101][101];
bool visited[101][101];

void dfs(int y, int x) {
	visited[y][x] = true;
	++k;

	for (int i(0); i < 4; ++i) {
		int r(y + dy[i]);
		int c(x + dx[i]);

		if (r < 1 || r > N || c < 1 || c > M)
			continue;

		if (!visited[r][c] && passage[r][c])
			dfs(r, c);
	}
}

int main() {
	int max(0);

	scanf("%d %d %d", &N, &M, &K);

	for (int i(0); i < K; ++i) {
		int r, c;

		scanf("%d %d", &r, &c);
		passage[r][c] = 1;
	}

	for (int r(1); r <= N; ++r) {
		for (int c(1); c <= M; ++c) {
			if (!visited[r][c] && passage[r][c]) {
				k = 0;
				dfs(r, c);
				max = MAX(max, k);
			}
		}
	}

	printf("%d \n", max);

	return 0;
}
