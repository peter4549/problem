#include <cstdio>
#include <queue>

using namespace std;

int N, M, count, minCount(10000);
int maze[100][100];
int distances[100][100];
bool visited[100][100];

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void bfs(int y, int x) {
	int n, m;

	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i) {
			n = y + dy[i];
			m = x + dx[i];

			if (n >= 0 && n < N && m >= 0 && m < M) {
				if (maze[n][m] && !visited[n][m]) {
					distances[n][m] = distances[y][x] + 1;
					visited[n][m] = true;
					q.push(make_pair(n, m));
				}
			}
		}
	}
}


int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%1d", &maze[i][j]);

	bfs(0, 0);

	printf("%d", distances[N - 1][M - 1] + 1);

	return 0;
}
