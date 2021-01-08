#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

char board[10][11];
int N, M;
bool visited[10][10][10][10] = { false, };

struct U {
	int ry, rx, by, bx;
	int count = 0;
};

U tilt(U u, int d) {
	int ry(u.ry);
	int rx(u.rx);
	int by(u.by);
	int bx(u.bx);
	
	while (true) {
		if (board[ry][rx] != '.') {
			if (board[ry][rx] == '#') {
				ry -= dy[d];
				rx -= dx[d];
			}

			break;
		}

		ry += dy[d];
		rx += dx[d];
	}

	while (true) {
		if (board[by][bx] != '.') {
			if (board[by][bx] == '#') {
				by -= dy[d];
				bx -= dx[d];
			}

			break;
		}

		by += dy[d];
		bx += dx[d];
	}

	if (ry == by && rx == bx && board[ry][rx] != 'O') {
		int dr(abs(ry - u.ry) + abs(rx - u.rx));
		int db(abs(by - u.by) + abs(bx - u.bx));

		if (dr > db) {
			ry -= dy[d];
			rx -= dx[d];
		}
		else {
			by -= dy[d];
			bx -= dx[d];
		}
	}

	u.ry = ry;
	u.rx = rx;
	u.by = by;
	u.bx = bx;

	return u;
}

int bfs(U start) {
	int count(-1);
	queue<U> q;
	visited[start.ry][start.rx][start.by][start.bx] = true;
	q.push(start);

	while (!q.empty()) {
		U u = q.front();
		q.pop();

		if (u.count > 10)
			break;

		if (board[u.ry][u.rx] == 'O' && board[u.by][u.bx] != 'O') {
			count = u.count;
			break;
		}

		for (int d(0); d < 4; ++d) {
			U v = tilt(u, d);

			if (!visited[v.ry][v.rx][v.by][v.bx]) {
				++v.count;
				visited[v.ry][v.rx][v.by][v.bx] = true;
				q.push(v);
			}
		}
	}

	return count;
}

int main() {
	scanf("%d %d", &N, &M);

	U u;

	for (int i(0); i < N; ++i) {
		scanf("%s", &board[i]);

		for (int j(0); j < M; ++j) {
			if (board[i][j] == 'R') {
				u.ry = i;
				u.rx = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				u.by = i;
				u.bx = j;
				board[i][j] = '.';
			}
		}
	}

	printf("%d", bfs(u));

	return 0;
}
