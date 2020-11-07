#include <cstdio>

int N, M, H, min;
int ladder[31][11];

bool go_down() {
	for (int i = 1; i <= N; ++i) {
		int x = i;

		for (int j = 0; j <= H; ++j) {
			if (ladder[j][x])
				++x;
			else if (ladder[j][x - 1])
				--x;
		}

		if (x != i)
			return false;
	}

	return true;
}

void dfs(int y, int x, int level) {
	if (level >= min)
		return;
	
	if (go_down()) {
		min = level;
		return;
	}

	if (level == 3)
		return;

	for (int i = y; i <= H; ++i) {
		for (int j = x; j < N; ++j) {
			if (!ladder[i][j] && !ladder[i][j - 1] && !ladder[i][j + 1]) {
				ladder[i][j] = 1;
				dfs(i, j, level + 1);
				ladder[i][j] = 0;
			}
		}

		x = 1;
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &H);

	int y, x;
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &y, &x);
		ladder[y][x] = 1;
	}

	min = 4;
	dfs(1, 1, 0);

	if (min == 4)
		min = -1;

	printf("%d", min);

	return 0;
}
