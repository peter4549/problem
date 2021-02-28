#include <cstdio>

#define MAX(a, b) (a > b ? a : b)

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

int drawing_paper[501][501], m, max, mf, n;

int dfs(int r, int c, int& k) {
	for (int i(0); i < 4; ++i) {
		int y(r + dy[i]);
		int x(c + dx[i]);

		if (y < 0 || y >= n || x < 0 || x >= m)
			continue;

		if (drawing_paper[y][x] != 1)
			continue;

		drawing_paper[y][x] = drawing_paper[r][c];
		k++;
		dfs(y, x, k);
	}

	return k;
}

int main() {
	int k(1);

	scanf("%d %d", &n, &m);

	for (int i(0); i < n; ++i)
		for (int j(0); j < m; ++j)
			scanf("%d", &drawing_paper[i][j]);

	for (int i(0); i < n; ++i)
		for (int j(0); j < m; ++j) {
			if (drawing_paper[i][j] == 1) {
				++k;
				drawing_paper[i][j] = k;

				int u(0);

				max = MAX(max, dfs(i, j, u));
			}
		}

	printf("%d \n", k - 1);

	if (k - 1 == 0) {
		printf("0");
		return 0; 
	}

	printf("%d \n", max + 1);

	return 0;
}
