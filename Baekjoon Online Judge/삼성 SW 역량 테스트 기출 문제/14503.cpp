#include <cstdio>
#include <queue>

using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

struct Robovac {
	int r, c, direction;
};

int M, N, map[50][50];

int bfs(Robovac start) {
	int n(0);
	queue<Robovac> q;
	q.push(start);

	while (!q.empty()) {
		Robovac robovac(q.front());
		q.pop();

		int r(robovac.r);
		int c(robovac.c);
		int direction(robovac.direction);

		if (map[r][c] == 0) {
			map[r][c] = 2;
			++n;
		}

		for (int i(0); i < 4; ++i) {
			int z((direction + 3 - i) % 4);
			int y(r + dy[z]);
			int x(c + dx[z]);

			if (map[y][x] == 0) {
				q.push({ y, x, z });
				break;
			}

			if (i == 3) {
				int n(r + dy[(direction + 2) % 4]);
				int m(c + dx[(direction + 2) % 4]);

				if (map[n][m] == 1)
					break;

				q.push({ n, m, direction });
			}
		}
	}

	return n;
}

int main() {
	Robovac start;

	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &start.r, &start.c, &start.direction);

	for (int r(0); r < N; ++r)
		for (int c(0); c < M; ++c)
			scanf("%d", &map[r][c]);

	printf("%d \n", bfs(start));

	return 0;
}
