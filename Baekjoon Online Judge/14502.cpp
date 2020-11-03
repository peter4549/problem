#include <cstdio>
#include <cstring>
#include <queue>

#define MAX(a, b) a > b ? a : b

using namespace std;

int N, M, maxSafeZoneSize;
int laboratory[64][64], originalLaboratory[64][64];
pair<int, int> walls[64];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void bfs(queue<pair<int, int>> q) {
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int n = p.first + dy[i];
			int m = p.second + dx[i];

			if (n >= 0 && n < N && m >= 0 && m < M && !laboratory[n][m]) {
				laboratory[n][m] = 2;
				q.push(make_pair(n, m));
			}
		}
	}
}

int getSafeZoneSize() {
	int safeZoneSize(0);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (!laboratory[i][j])
				++safeZoneSize;

	return safeZoneSize;
}

int main() {
	queue<pair<int, int>> q;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			scanf("%d", &laboratory[i][j]);

			if (laboratory[i][j] == 2)
				q.push(make_pair(i, j));
		}

	memcpy(originalLaboratory, laboratory, sizeof(laboratory));

	int k(0);
	int size = N * M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			walls[k++] = make_pair(i, j);

	for (int i = 0; i < size - 2; ++i) {
		pair<int, int> wall1 = walls[i];

		if (!laboratory[wall1.first][wall1.second]) {
			for (int j = i + 1; j < size - 1; ++j) {
				pair<int, int> wall2 = walls[j];

				if (!laboratory[wall2.first][wall2.second]) {
					for (k = j + 1; k < size; ++k) {
						pair<int, int> wall3 = walls[k];

						if (!laboratory[wall3.first][wall3.second]) {
							laboratory[wall1.first][wall1.second] = 1;
							laboratory[wall2.first][wall2.second] = 1;
							laboratory[wall3.first][wall3.second] = 1;
							bfs(q);				
							maxSafeZoneSize = MAX(maxSafeZoneSize, getSafeZoneSize());
							memcpy(laboratory, originalLaboratory, sizeof(laboratory));
						}
					}
				}
			}
		}
	}

	printf("%d", maxSafeZoneSize);

	return 0;
}
