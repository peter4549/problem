#include <cstdio>

int R, C, count, maxCount;

char RC[20][20];
bool alphabets[26];
bool visited[20][20];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void dfs(int y, int x) {
	int n, m;

	if (alphabets[RC[y][x]] || visited[y][x])
		return;

    visited[y][x] = true;
	alphabets[RC[y][x]] = true;
	++count;

	if (maxCount < count)
		maxCount = count;

	for (int i = 0; i < 4; ++i) {
		n = y + dy[i];
		m = x + dx[i];

		if (alphabets[RC[n][m]])
			continue;
		
		if (n >= 0 && n < R && m >= 0 && m < C)
			dfs(n, m);
	}

	visited[y][x] = false;
	alphabets[RC[y][x]] = false;
	--count;
}

int main() {
	int i, j;
	char s[20];

	scanf("%d %d", &R, &C);

	for (i = 0; i < R; ++i) {
		scanf("%s", &s);
		
		for (j = 0; j < C; ++j)
			RC[i][j] = s[j] - 65;
	}

	dfs(0, 0);

	printf("%d", maxCount);

	return 0;
}
