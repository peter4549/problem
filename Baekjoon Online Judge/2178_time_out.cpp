#include <cstdio>

int N, M, count, minCount(10000);
int maze[100][100];
bool visited[100][100];
bool reachedOnce;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
	int n, m;
	
	if (visited[y][x] || !maze[y][x])
		return;

	visited[y][x] = true;
	++count;

	if (reachedOnce)
		if (count >= minCount) {
			visited[y][x] = false;
			--count;
			return;
		}

	if (y >= N - 1 && x >= M - 1) {
		if (minCount > count)
			minCount = count;

		visited[y][x] = false;
		--count;
		reachedOnce = true;
		
		return;
	}

	for (int i = 0; i < 4; ++i) {
		n = y + dy[i];
		m = x + dx[i];

		if (n >= 0 && n < N && m >= 0 && m < M) {
			dfs(n, m);
		}
	}

	visited[y][x] = false;
	--count;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%1d", &maze[i][j]);

	dfs(0, 0);

	printf("%d", minCount);

	return 0;
}
