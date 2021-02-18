#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

typedef struct Position {
	int y, x;
} position;

int N;
string grid[101];
bool visited[101][101];

void bfs(position start) {
	queue<position> q;
	q.push(start);
	visited[start.y][start.x] = true;

	while (!q.empty()) {
		position p = q.front();
		q.pop();

		for (int d(0); d < 4; ++d) {
			int y(p.y + dy[d]);
			int x(p.x + dx[d]);

			if (y < 0 || N <= y || x < 0 || N <= x)
				continue;

			if (!visited[y][x] && grid[p.y][p.x] == grid[y][x]) {
				position p;
				p.y = y;
				p.x = x;
				q.push(p);
				visited[y][x] = true;
			}
		}
	}
}

void RToG() {
	for (int i(0); i < N; ++i)
		for (int j(0); j < N; ++j) 
			if (grid[i][j] == 'R')
				grid[i][j] = 'G';
}

int main() {
	int n(0), m(0);
	cin >> N;

	for (int i(0); i < N; ++i)
		cin >> grid[i];

	for (int i(0); i < N; ++i)
		for (int j(0); j < N; ++j) {
			if (!visited[i][j]) {
				position p;
				p.y = i;
				p.x = j;
				bfs(p);
				++n;
			}
		}

	RToG();
	memset(visited, false, sizeof(visited));

	for (int i(0); i < N; ++i)
		for (int j(0); j < N; ++j) {
			if (!visited[i][j]) {
				position p;
				p.y = i;
				p.x = j;
				bfs(p);
				++m;
			}
		}

	cout << n << ' ' << m << endl;

	return 0;
}
