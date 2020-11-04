#include <cstdio>
#include <queue>

using namespace std;

struct Robovac {
	int r, c, d;
};

int N, M;
int map[50][50];

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int bfs(Robovac start) {
	int count(0);
	queue<Robovac> q;
	q.push(start);

	while (!q.empty()) {
		Robovac current = q.front();
		q.pop();
		
		if (map[current.r][current.c] == 0) {
			map[current.r][current.c] = 2;
			++count;
		}
		

		for (int i = 0; i < 4; ++i) {
			int d = (current.d + 3 - i) % 4;
			int r = current.r + dy[d];
			int c = current.c + dx[d];
			
			if (!map[r][c]) {
			    Robovac next;
				next.r = r;
				next.c = c;
				next.d = d;
				q.push(next);
				break;
			} 

			if (i == 3) {
					Robovac next;
					next.d = current.d;
					next.r = current.r + dy[(next.d + 2) % 4];
					next.c = current.c + dx[(next.d + 2) % 4];

					if (map[next.r][next.c] == 1)
						break;

					q.push(next);
				}
		}
	}

	return count;
}

int main() {

	scanf("%d %d", &N, &M);

	Robovac start;
	scanf("%d %d %d", &start.r, &start.c, &start.d);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%d", &map[i][j]);

	printf("%d", bfs(start));

	return 0;
}
