#include <cstdio>
#include <cstring>

#define MAX(a, b) (a > b ? a : b)

int N, m;

inline void swap(int& a, int& b) {
	int c(a);
	a = b;
	b = c;
}

struct Board {
	int board[21][21] = { 0, };

	void rotate() {
		for (int i = 0; i < N / 2; i++) {
			for (int j = i; j < N - i - 1; j++) {
				int k = board[i][j];
				board[i][j] = board[N - 1 - j][i];
				board[N - 1 - j][i] = board[N - 1 - i][N - 1 - j];
				board[N - 1 - i][N - 1 - j] = board[j][N - 1 - i];
				board[j][N - 1 - i] = k;
			}
		}
	}

	void up() {
		for (int c(0); c < N; ++c) {
			int i(-1);

			for (int r(0); r < N; ++r) {
				if (!board[r][c]) {
					if (i == -1)
						i = r;
				}
				else {
					if (i != -1) {
						swap(board[i][c], board[r][c]);
						r = i;
						i = -1;
					}
				}
			}
		}
	}

	bool merge() {
		bool merged(false);

		for (int c(0); c < N; ++c) {
			for (int r(1); r < N; ++r) {
				if (board[r - 1][c] == board[r][c]) {
					board[r - 1][c] += board[r][c];
					board[r][c] = 0;
					++r;
					merged = true;
				}
			}
		}

		return merged;
	}

	int max() {
		int max(0);

		for (int r(0); r < N; ++r)
			for (int c(0); c < N; ++c)
				max = MAX(max, board[r][c]);

		return max;
	}
};

void dfs(Board board, int c) {
	if (c > 4) {
		m = MAX(m, board.max());
		return;
	}

	for (int i(0); i < 4; ++i) {
		Board next(board);
		next.up();

		if (next.merge())
			next.up();

		dfs(next, c + 1);
		board.rotate();
	}
}

int main() {
	Board board;

	scanf("%d", &N);

	for (int r(0); r < N; ++r)
		for (int c(0); c < N; ++c)
			scanf("%d", &board.board[r][c]);

	dfs(board, 0);

	printf("%d", m);

	return 0;
}
