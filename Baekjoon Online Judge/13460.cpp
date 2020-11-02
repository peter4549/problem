#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct Position {
	int ry, rx, by, bx, count;
};

char board[10][11];

int bfs(Position start) {
	const int dy[4] = { -1, 0, 1, 0 };
	const int dx[4] = { 0, -1, 0, 1 };

	bool visited[10][10][10][10] = { false };
	int i, count(-1);
	Position p, np;
	queue<Position> q;

	q.push(start);
	visited[start.ry][start.rx][start.by][start.bx] = true;

	while (!q.empty()) {
		p = q.front();
		q.pop();

		if (p.count > 10)
			break;

		if (board[p.ry][p.rx] == 'O' && board[p.by][p.bx] != 'O') {
			count = p.count;
			break;
		}

		for (i = 0; i < 4; ++i) {
			np = p;
		
			while (true) {
				if (board[np.ry][np.rx] != '#' && board[np.ry][np.rx] != 'O')
					np.ry += dy[i], np.rx += dx[i];
				else {
					if (board[np.ry][np.rx] == '#')
						np.ry -= dy[i], np.rx -= dx[i];
					break;
				}
			}

			while (true) {
				if (board[np.by][np.bx] != '#' && board[np.by][np.bx] != 'O')
					np.by += dy[i], np.bx += dx[i];
				else {
					if (board[np.by][np.bx] == '#')
						np.by -= dy[i], np.bx -= dx[i];
					break;
				}
			}

			if (np.ry == np.by && np.rx == np.bx) {
				if (board[np.ry][np.rx] != 'O') {
					int rd = abs(np.ry - p.ry) + abs(np.rx - p.rx);
					int bd = abs(np.by - p.by) + abs(np.bx - p.bx);
					
					if (rd > bd)
						np.ry -= dy[i], np.rx -= dx[i];
					else
						np.by -= dy[i], np.bx -= dx[i];
				}
			}

			if (!visited[np.ry][np.rx][np.by][np.bx]) {
				visited[np.ry][np.rx][np.by][np.bx] = true;
				np.count = p.count + 1;
				q.push(np);
			}
		}
	}

	return count;
}

int main() {
	int N, M, i;
	Position start;
	
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; ++i)
		scanf("%s", &board[i]);

	for (i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == 'R')
				start.ry = i, start.rx = j;
			if (board[i][j] == 'B')
				start.by = i, start.bx = j;
		}

	start.count = 0;

	printf("%d", bfs(start));

	return 0;
}
