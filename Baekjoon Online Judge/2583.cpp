#include <cstdio>
#include <algorithm>

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

int M, N, K;
int grid[101][101];

int count(0), width(1);
int widths[101];

void dfs(int y, int x) {
	for (int d(0); d < 4; ++d) {
		int m(y + dy[d]);
		int n(x + dx[d]);

		if (0 > m || m >= M || 0 > n || n >= N)
			continue;

		if (grid[m][n])
			continue;

		grid[m][n] = 1;
		dfs(m, n);
		++width;
	}
}

int main() {
	scanf("%d %d %d", &M, &N, &K);

	for (int i(0); i < K; ++i) {
		int leftBottomX, leftBottomY, rightTopX, rightTopY;
		scanf("%d %d %d %d", &leftBottomX, &leftBottomY, &rightTopX, &rightTopY);
		for (int y(leftBottomY); y < rightTopY; ++y) {
			for (int x(leftBottomX); x < rightTopX; ++x) {
				grid[y][x] = 1;
			}
		}
	}

	for (int i(0); i < M; ++i)
		for (int j(0); j < N; ++j) {
			if (!grid[i][j]) {
				grid[i][j] = 1;
				dfs(i, j);
				widths[count++] = width;
				width = 1;
			}
		}

	std::sort(widths, widths + count);

	printf("%d \n", count);
	for (int i(0); i < count; ++i)
		printf("%d ", widths[i]);

	return 0;
}
