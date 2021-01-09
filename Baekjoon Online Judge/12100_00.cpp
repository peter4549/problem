#include <cstdio>
#include <cstring>

using namespace std;

#define MAX(a, b) (a > b ? a : b)

int N, max;

void inline swap(int& a, int& b) {
	int t(a);
	a = b;
	b = t;
}

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
		for (int x(0); x < N; ++x) {
			for (int y(1); y < N; ++y) {
				if (board[y][x] != 0 && board[y - 1][x] == 0) {
					swap(board[y][x], board[y - 1][x]);
					y -= 2;
					if (y < 1)
						y = 1;
				}
			}
		}
	}

	bool merge() {
		bool merged(false);

		for (int x(0); x < N; ++x) {
			for (int y(1); y < N; ++y) {
				if (board[y - 1][x] != 0 && board[y - 1][x] == board[y][x]) {
					board[y - 1][x] *= 2;
					board[y++][x] = 0;
					merged = true;
				}
			}
		}

		return merged;
	}

	int max() {
		int max(0);

		for (int y(0); y < N; ++y)
			for (int x(0); x < N; ++x)
				max = MAX(max, board[y][x]);

		return max;
	}
};

void dfs(Board board, int count) {
	if (count > 4) {
		max = MAX(max, board.max());
		return;
	}

	for (int i(0); i < 4; ++i) {
		Board next = board;
		next.up();
		if (next.merge())
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
