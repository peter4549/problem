#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N, complexCount;
int map[25][25], printArray[313];
bool visited[25][25];

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void bfs(int y, int x) {
	int n, m, houseCount(0);

	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();
		++houseCount;

		for (int i = 0; i < 4; ++i) {
			n = y + dy[i];
			m = x + dx[i];

			if (n >= 0 && n < N && m >= 0 && m < N) {
				if (map[n][m] && !visited[n][m]) {
					visited[n][m] = true;
					q.push(make_pair(n, m));
				}
			}
		}
	}

	printArray[complexCount] = houseCount;
}


int main() {
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			scanf("%1d", &map[i][j]);

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			if (!visited[i][j] && map[i][j]) {
				bfs(i, j);
				++complexCount;
			}

	sort(printArray, printArray + complexCount);

	printf("%d\n", complexCount);

	for (i = 0; i < complexCount; ++i)
		printf("%d\n", printArray[i]);

	return 0;
}
