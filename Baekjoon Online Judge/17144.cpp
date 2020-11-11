#include <cstdio>

using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

int R, C, T, n, m;
int A[50][50];

void spread_fine_dust() {
	int B[50][50] = { 0, };

	for (int r(0); r < R; ++r)
		for (int c(0); c < C; ++c) {
			if (A[r][c] && A[r][c] != -1) {
				for (int i(0); i < 4; ++i) {
					int y = r + dy[i];
					int x = c + dx[i];

					if (0 <= y && y < R && 0 <= x && x < C && A[y][x] != -1) {
						int a = A[r][c] / 5;
						B[y][x] += a;
						B[r][c] -= a;
					}
				}
			}
		}

	for (int r(0); r < R; ++r)
		for (int c(0); c < C; ++c)
			A[r][c] += B[r][c];
}

void run_air_purifier() {
	int i;

	for (i = m - 1; i >= 0; --i) {
		if (A[n][i + 1] == -1)
			A[n][i] = 0;
		else {
			A[n][i + 1] = A[n][i];
			A[n][i] = 0;
		}

		if (A[n + 1][i + 1] == -1)
			A[n + 1][i] = 0;
		else {
			A[n + 1][i + 1] = A[n + 1][i];
			A[n + 1][i] = 0;
		}
	}

	for (i = n - 1; i >= 0; --i) {
		if (A[i + 1][0] == -1)
			A[i][0] = 0;
		else {
			A[i + 1][0] = A[i][0];
			A[i][0] = 0;
		}
	}

	for (i = n + 2; i < R; ++i) {
		if (A[i - 1][0] == -1)
			A[i][0] = 0;
		else {
			A[i - 1][0] = A[i][0];
			A[i][0] = 0;
		}
	}

	for (i = 1; i < C; ++i) {
		A[0][i - 1] = A[0][i];
		A[0][i] = 0;
		A[R - 1][i - 1] = A[R - 1][i];
		A[R - 1][i] = 0;
	}
	
	for (i = 1; i <= n; ++i) {
		A[i - 1][C - 1] = A[i][C - 1];
		A[i][C - 1] = 0;
	}

	for (i = R - 2; i >= n + 1; --i) {
		A[i + 1][C - 1] = A[i][C - 1];
		A[i][C - 1] = 0;
	}

	for (i = C - 2; i >= m + 1; --i) {
		A[n][i + 1] = A[n][i];
		A[n][i] = 0;
		A[n + 1][i + 1] = A[n + 1][i];
		A[n + 1][i] = 0;
	}
}

int main() {
	int r, c, t;
	bool b(false);

	scanf("%d %d %d", &R, &C, &T);

	for (r = 0; r < R; ++r)
		for (c = 0; c < C; ++c) {
			scanf("%d", &A[r][c]);
			
			if (!b && A[r][c] == -1) {
				n = r, m = c;
				b = true;
			}
		}

	for (t = 0; t < T; ++t) {
		spread_fine_dust();
		run_air_purifier();
	}

	int fine_dust(0);

	for (r = 0; r < R; ++r)
		for (c = 0; c < C; ++c)
			if (A[r][c] && A[r][c] != -1)
				fine_dust += A[r][c];

	printf("%d", fine_dust);

	return 0;
}
