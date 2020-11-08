#include <cstdio>

int N, M, H, ladder_count;
int ladder[31][11];

bool go_down() {
	for (int i(1); i <= N; ++i) {
		int x(i);

		for (int j(0); j <= H; ++j) {
			if (ladder[j][x]) {
				++x;
			}
			else if (ladder[j][x - 1]) {
				--x;
			}
		}

		if (x != i)
			return false;
	}

	return true;
}

void dfs(int y, int x, int count) {
	if (ladder_count <= count)
		return;

	if (go_down()) {
		ladder_count = count;
		return;
	}

	if (count >= 3) {
		return;
	}		

	for (int i(y); i <= H; ++i) {
		for (int j(x); j < N; ++j) {
			if (!ladder[i][j] && !ladder[i][j - 1] && !ladder[i][j + 1]) {
				ladder[i][j] = 1;
				dfs(i, j, count + 1);
				ladder[i][j] = 0;
			}
		}

		x = 1;
	}
}

int main() {
	int a, b;

	scanf("%d %d %d", &N, &M, &H);

	for (int i(0); i < M; ++i) {
		scanf("%d %d", &a, &b);
		ladder[a][b] = 1;
	}

	ladder_count = 4;
	dfs(1, 1, 0);

	if (ladder_count == 4)
		ladder_count = -1;

	printf("%d", ladder_count);

	return 0;
}
