#include <cstdio>
#include <queue>

using namespace std;

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

struct Hedgehog {
	int r, c;
	int k;
};

char map[50][51];
int C, R;
queue<Hedgehog> hedgehog;
queue<pair<int, int>> q;

int bfs() {
	while (!hedgehog.empty()) {
		int size(q.size());

		for (int i(0); i < size; ++i) {
			pair<int, int> p(q.front());
		    q.pop();

			for (int i(0); i < 4; ++i) {
				int y(p.first + dy[i]);
				int x(p.second + dx[i]);

				if (y < 0 || y >= R || x < 0 || x >= C)
					continue;

				if (map[y][x] == '.') {
					map[y][x] = '*';
					q.push({ y, x });
				}
			}
		}
		
		size = hedgehog.size();

		for (int i(0); i < size; ++i) {
			Hedgehog S(hedgehog.front());
			hedgehog.pop();

			for (int i(0); i < 4; ++i) {
				int y(S.r + dy[i]);
				int x(S.c + dx[i]);

				if (map[y][x] == 'D')
					return S.k;

				if (y < 0 || y >= R || x < 0 || x >= C)
					continue;

				if (map[y][x] == '.') {
					map[y][x] = 'S';
					hedgehog.push({ y, x, S.k + 1 });
				}
			}
		}
	}

	return -1;
}

int main() {
	scanf("%d %d", &R, &C);

	for (int r(0); r < R; ++r)
		scanf("%s", &map[r]);

	for (int r(0); r < R; ++r) {
		for (int c(0); c < C; ++c) {
			if (map[r][c] == 'S')
				hedgehog.push({ r, c, 1 });
			else if (map[r][c] == '*')
				q.push({ r, c });
		}
	}

	int k(bfs());

	if (k == -1)
		printf("KAKTUS \n");
	else
		printf("%d \n", k);

	return 0;
}
