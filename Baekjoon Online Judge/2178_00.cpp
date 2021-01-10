#include <cstdio>
#include <queue>

using namespace std;

#define MAX(a, b) (a > b ? a : b)

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

int N, M;
int maze[101][101];

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	maze[0][0] = 2;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int d(0); d < 4; ++d) {
			int y(p.first + dy[d]);
			int x(p.second + dx[d]);

			if (0 > y || y >= N || 0 > x || x >= M)
				continue;
			
			if (maze[y][x] == 1) {
				maze[y][x] += maze[p.first][p.second];
				q.push(make_pair(y, x));
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int y(0); y < N; ++y)
		for (int x(0); x < M; ++x)
			scanf("%1d", &maze[y][x]);

	bfs();
	
	printf("%d", maze[N - 1][M - 1] - 1);

	return 0;
}
