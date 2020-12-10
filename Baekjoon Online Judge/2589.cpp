#include <cstdio>
#include <queue>
#include <cstring>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

int N, M;
char map[50][51];
int visited[50][51] = { 0, };

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = 1;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int i(0); i < 4; ++i) {
			int y = p.first + dy[i];
			int x = p.second + dx[i];

			if (0 <= y && y < N && 0 <= x && x < M) {
				if (!visited[y][x] && map[y][x] == 'L') {
					visited[y][x] = visited[p.first][p.second] + 1;
					q.push(make_pair(y, x));
				}
			}
		}
	}

	int max(0);

	for (int i(0); i < N; ++i)
		for (int j(0); j < M; ++j)
			max = MAX(max, visited[i][j]);

	return max;
}

void clear() {
	memset(visited, 0, sizeof(visited));
}

int main() {
	int i, j, max= 0;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; ++i)
		scanf("%s", &map[i]);
	
	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j) {
			if (map[i][j] == 'L') {
				max = MAX(max, bfs(i, j));
				clear();
			}
		}

	printf("%d", max - 1);

	return 0;
}
