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

void dfs(int count, int max_count) {
	if (min != 4)
		return;

	if (count == max_count) {
		if (go_down())
			min = min > count ? count : min;

		return;
	}

	for (int j(1); j < N; j++) {
		for (int i(1); i <= H; i++) {
			if (ladder[i][j] || ladder[i][j + 1] || ladder[i][j - 1])
				continue;

			ladder[i][j] = 1;
			dfs(count + 1, max_count);
			ladder[i][j] = 0;

			while (!ladder[i][j - 1] && !ladder[i][j + 1])
				++i;
		}
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

	for (int i(0); i < 4; ++i) {
		dfs(0, i);

		if (min != 4) {
			printf("%d", min);
			return 0;
		}
	}

	if (min == 4)
		printf("-1");

	return 0;
}
