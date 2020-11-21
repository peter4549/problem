#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

char grid[100][101];
bool visited[100][100];

void bfs(pair<int, int> begin) {
	queue<pair<int, int>> q;
	q.push(begin);

	visited[begin.first][begin.second] = true;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int i(0); i < 4; ++i) {
			int y = p.first + dy[i];
			int x = p.second + dx[i];

			if (!visited[y][x] && grid[p.first][p.second] == grid[y][x]) {
				visited[y][x] = true;
				
				q.push(make_pair(y, x));
			}
		}
	}
}

int main() {
	int N, i, j, n(0), m(0);

	scanf("%d", &N);

	for (i = 0; i < N; ++i)
		scanf("%s", &grid[i]);

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j) {
			if (!visited[i][j]) {
				bfs(make_pair(i, j));
				++n;
			}
		}

	memset(visited, false, sizeof(visited));	

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j) {
			if (grid[i][j] == 'G')
				grid[i][j] = 'R';
		}

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j) {
			if (!visited[i][j]) {
				bfs(make_pair(i, j));
				++m;
			}
		}

	printf("%d %d", n, m);
	
	return 0;
}
