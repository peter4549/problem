#include <cstdio>
#include <queue>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

const int dh[6] = { 1, -1, 0, 0, 0, 0 };
const int dy[6] = { 0, 0, 1, -1, 0, 0 };
const int dx[6] = { 0, 0, 0, 0, 1, -1 };

struct Position {
	int h, y, x;
};

int M, N, H;
int box[101][101][101];
queue<Position> q;

void bfs() {
	while (!q.empty()) {
		Position p = q.front();
		q.pop();

		for (int d(0); d < 6; ++d) {
			int h(p.h + dh[d]);
			int y(p.y + dy[d]);
			int x(p.x + dx[d]);

			if (0 > h || h >= H || 0 > y || y >= N || 0 > x || x >= M)
				continue;

			if (!box[h][y][x]) {
				box[h][y][x] = box[p.h][p.y][p.x] + 1;
				Position np;
				np.h = h;
				np.y = y;
				np.x = x;
				q.push(np);
			}
		}
	}
}

int checkBox() {
	int max(-1);

	for (int h(0); h < H; ++h) {
		for (int n(0); n < N; ++n) {
			for (int m(0); m < M; ++m) {
				if (!box[h][n][m])
					return -1;

				max = MAX(max, box[h][n][m]);
			}
		}
	}

	return max;
}

int main() {
	scanf("%d %d %d", &M, &N, &H);

	for (int h(0); h < H; ++h) {
		for (int n(0); n < N; ++n) {
			for (int m(0); m < M; ++m) {
				scanf("%d", &box[h][n][m]);
				
				if (box[h][n][m] == 1) {
					Position p;
					p.h = h;
					p.y = n;
					p.x = m;
					q.push(p);
				}
			}
		}
	}

	bfs();
	int day = checkBox();
	
	if (day < 0)
		printf("-1");
	else
	    printf("%d", checkBox() - 1);

	return 0;
}
