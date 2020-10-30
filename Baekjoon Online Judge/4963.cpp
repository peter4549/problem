#include <cstdio>
#include <cstring>

int w, h;
int map[50][50];
bool visited[50][50];

int dy[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dx[8] = { 0, -1, 0, 1, -1, 1, -1, 1 };

void dfs(int y, int x) {
	int n, m;

	if (visited[y][x])
		return;

	visited[y][x] = true;

	for (int i = 0; i < 8; ++i) {
		n = y + dy[i];
		m = x + dx[i];

		if (n >= 0 && n < h && m >= 0 && m < w && map[n][m])
			dfs(n, m);
	}
}

int main() {
	int i, j, count(0);

	while (scanf("%d %d", &w, &h) != EOF) {
		if (!w || !h)
			return 0;

		for (i = 0; i < h; ++i)
			for (j = 0; j < w; ++j)
				scanf("%d", &map[i][j]);

		for (i = 0; i < h; ++i)
			for (j = 0; j < w; ++j) {
				if (!visited[i][j] && map[i][j]) {
					dfs(i, j);
					++count;
				}
			}

		printf("%d\n", count);

		count = 0;

		for (int i = 0; i < h; i++) {
			memset(map[i], 0, sizeof(int) * w);
			memset(visited[i], false, sizeof(bool) * w);
		}
	}

	return 0;
}
