#include <cstdio>
#include <queue>

using namespace std;

int M, N;
int box[1000][1000];
queue<pair<int, int>> q;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void bfs() {

	int i, n, m;
	pair<int, int> position;

	while (!q.empty()) {
		position = q.front();
		q.pop();

		for (i = 0; i < 4; ++i) {
			n = position.first + dy[i];
			m = position.second + dx[i];
			
			if (n >= 0 && n < N && m >= 0 && m < M && box[n][m] != -1) {
				if (!box[n][m]) {
					box[n][m] = box[position.first][position.second] + 1;
					q.push(make_pair(n, m));
				}
			}
		}
	}
}

int main() {
	int i, j, max(0);
	pair<int, int> position;

	scanf("%d %d", &M, &N);

	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j) {
			scanf("%d", &box[i][j]);

			if (box[i][j] == 1)
				q.push(make_pair(i, j));
		}

	bfs();

	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j) {
			if (!box[i][j]) {
				printf("-1");
				return 0;
			}

			if (max < box[i][j])
				max = box[i][j];
		}

	printf("%d", max - 1);
	
	return 0;
}
