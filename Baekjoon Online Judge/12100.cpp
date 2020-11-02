#include <cstdio>
#include <cstring>

#define MAX(a, b) a > b ? a : b

using namespace std;

int N, max;

struct Board {
	int board[20][20];

	void rotate() {
		int t[20][20];

		for (int y = 0; y < N; ++y)
			for (int x = 0; x < N; ++x)
				t[y][x] = board[N - x - 1][y];

		memcpy(board, t, sizeof(t));
	}

	void up() {
		int t[20][20] = { 0, };

		for (int x = 0; x < N; ++x) {
			bool notMerged = false;
			int z = -1;

			for (int y = 0; y < N; ++y) {
				if (!board[y][x])
					continue;

				if (notMerged && board[y][x] == t[z][x])
					t[z][x] *= 2, notMerged = false;
				else
					t[++z][x] = board[y][x], notMerged = true;
			}

			for (++z; z < N; ++z)
				t[z][x] = 0;
		}

		memcpy(board, t, sizeof(t));
	}

	int getMax() {
		int max(0);

		for (int y = 0; y < N; ++y)
			for (int x = 0; x < N; ++x)
				max = MAX(max, board[y][x]);
			
		return max;
	}
};

void dfs(Board board, int count) {
	if (count == 5) {
		max = MAX(max, board.getMax());
		return;
	}

	for (int i = 0; i < 4; ++i) {
		Board next = board;
		next.up();
		dfs(next, count + 1);
		board.rotate();
	}
}

int main() {
	Board board;

	scanf("%d", &N);

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			scanf("%d", &board.board[y][x]);

	dfs(board, 0);

	printf("%d", max);

	return 0;
}
