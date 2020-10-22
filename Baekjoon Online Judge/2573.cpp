#include <stdio.h>

int N, M;

int iceberg[300][300];
int adjacentSeas[300][300];
bool visited[300][300];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int countAdjacentSeas(int y, int x) {
	int n, m, count(0);

	for (int i = 0; i < 4; ++i) {
		n = y + dy[i];
		m = x + dx[i];

		if (n >= 0 && n < N && m >= 0 && m < M)
			if (!iceberg[n][m])
				++count;
	}

	return count;
}

bool melt() {
	int i, j;
	bool noIcebergs(true);

	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j) {
			iceberg[i][j] -= adjacentSeas[i][j];

			if (iceberg[i][j] < 0)
				iceberg[i][j] = 0;

			if (iceberg[i][j])
				noIcebergs = false;
		}

	return noIcebergs;
}

void resetVisited() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			visited[i][j] = false;
}

void dfs(int y, int x) {
	int n, m;
	if (!iceberg[y][x] || visited[y][x])
		return;

	visited[y][x] = true;
	adjacentSeas[y][x] = 0;
	adjacentSeas[y][x] = countAdjacentSeas(y, x);

	for (int i = 0; i < 4; ++i) {
		n = y + dy[i];
		m = x + dx[i];

		if (n >= 0 && n < N && m >= 0 && m < M)
			dfs(n, m);
	}
}

int main() {
	int i, j, icebergs(0), years(0);

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j)
			scanf("%d", &iceberg[i][j]);

	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j) {
			adjacentSeas[i][j] = 0;
			adjacentSeas[i][j] = countAdjacentSeas(i, j);
		}

	while (icebergs < 2) {
		icebergs = 0;
		++years;

		if (melt()) {
			years = 0;
			break;
		}

		resetVisited();

		for (i = 1; i < N; ++i) {
			for (j = 1; j < M; ++j) {
				if (iceberg[i][j] && !visited[i][j]) {
					dfs(i, j);
					++icebergs;

					if (icebergs > 1)
						break;
					
				}
			}

			if (icebergs > 1)
				break;
		}
	}

	printf("%d", years);

	return 0;
}
