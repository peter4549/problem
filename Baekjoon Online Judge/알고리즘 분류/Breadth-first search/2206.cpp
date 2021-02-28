#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

#define MIN(a, b) (a < b ? a : b)

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

int M, N, map[1001][1001], visited[1001][1001][2];

int bfs() {
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(1, 1, 1));
	visited[1][1][1] = 1;
	
	while (!q.empty()) {
		tuple<int, int, int> t(q.front());
		q.pop();

		int y(get<0>(t));
		int x(get<1>(t));
		int z(get<2>(t));

		if (y == N && x == M)
			return visited[y][x][z];

		for (int i(0); i < 4; ++i) {
			int ny(get<0>(t) + dy[i]);
			int nx(get<1>(t) + dx[i]);

			if (0 >= ny || ny > N || 0 >= nx || nx > M)
				continue;

			if (map[ny][nx] == 1 && z) {
				visited[ny][nx][z - 1] = visited[y][x][z] + 1;
				q.push(make_tuple(ny, nx, z - 1));
			} else if (map[ny][nx] == 0 && visited[ny][nx][z] == 0) {
				visited[ny][nx][z] = visited[y][x][z] + 1;
				q.push(make_tuple(ny, nx, z));
			}
		}
	}

	return -1;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			scanf("%1d", &map[i][j]);

	printf("%d \n", bfs());

	return 0;
}
