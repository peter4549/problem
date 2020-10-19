#include <stdio.h>

int T, M, N;
int field[50][50];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void dfs(int y, int x) {
	if (field[y][x] == 0)
		return;

	field[y][x] = 0;

	for (int i = 0; i < 4; ++i) {
		int n = y + dy[i];
		int m = x + dx[i];

		if (n >= 0 && n < N && m >= 0 && m < M)
			dfs(n, m);
	}

}

int main() {
	int K, m, n, count;
	
	scanf("%d", &T);
	
	for (int t = 0; t < T; ++t) {
		count = 0;
		scanf("%d %d %d", &M, &N, &K);

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j)
				field[i][j] = 0;
		}
		
		for (int k = 0; k < K; ++k) {
			scanf("%d %d", &m, &n);
			field[n][m] = 1;
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j)
				if (field[i][j]) {
					dfs(i, j);
					++count;
				}
		}

		printf("%d\n", count);
	}

	return 0;
}
