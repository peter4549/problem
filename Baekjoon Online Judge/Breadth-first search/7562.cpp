#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int visited[301][301];

void bfs(int l, pair<int, int> start, pair<int, int> end) {
	visited[start.first][start.second] = true;

	queue<pair<int, int>> q;
	q.push(start);

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		if (end.first == p.first && end.second == p.second)
			return;
		
		for (int i(0); i < 8; ++i) {
			int y(p.first + dy[i]);
			int x(p.second + dx[i]);

			if (y < 0 || y >= l || x < 0 || x >= l)
				continue;

			if (!visited[y][x]) {
				q.push(make_pair(y, x));
				visited[y][x] = visited[p.first][p.second] + 1;
			}
		}
	}
}

int main() {
	int T, l, y, x;
	scanf("%d", &T);

	for (int i(0); i < T; ++i) {
		scanf("%d", &l);
		scanf("%d %d", &y, &x);
		pair<int, int> start = make_pair(y, x);
		scanf("%d %d", &y, &x);
		pair<int, int> end = make_pair(y, x);
		bfs(l, start, end);
		printf("%d \n", visited[end.first][end.second] - 1);
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}
