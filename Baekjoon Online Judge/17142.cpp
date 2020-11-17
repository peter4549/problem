#include <cstdio>
#include <queue>

#define MAX_TIME 2500
#define MIN(a, b) a > b ? b : a

using namespace std;

struct Virus {
	int y, x, time;
};

int N, M, virus_count, min_time;
int laboratory[50][50];
Virus viruses[10];

int bfs(int* picked) {
	const int dy[4] = { -1, 0, 1, 0 };
	const int dx[4] = { 0, -1, 0, 1 };

	int empty_count(0);

	for (int i(0); i < N; ++i)
		for (int j(0); j < N; ++j)
			if (!laboratory[i][j])
				++empty_count;
	
	queue<Virus> q;
	bool visited[50][50] = { false, };

	for (int i(0); i < M; ++i) {
		Virus virus = viruses[picked[i]];
		q.push(virus);
		visited[virus.y][virus.x] = true;
	}

	while (!q.empty()) {
		Virus virus = q.front();
		q.pop();

		if (!laboratory[virus.y][virus.x])
			--empty_count;

		if (!empty_count)
			return virus.time;

		for (int i(0); i < 4; ++i) {
			int y = virus.y + dy[i];
			int x = virus.x + dx[i];

			if (0 <= y && y < N && 0 <= x && x < N && !visited[y][x] && laboratory[y][x] != 1) {
				Virus next_virus;
				next_virus.y = y, next_virus.x = x, next_virus.time = virus.time + 1;

				q.push(next_virus);
				visited[y][x] = true;
			}
		}
	}

	return MAX_TIME;
}

void dfs(int virus_index, int m, int* picked) {
	if (m == M) {
		min_time = MIN(bfs(picked), min_time);
		return;
	}

	for (int i(virus_index + 1); i < virus_count; ++i) {
		picked[m] = i;
		dfs(i, m + 1, picked);
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i(0); i < N; ++i)
		for (int j(0); j < N; ++j) {
			scanf("%d", &laboratory[i][j]);

			if (laboratory[i][j] == 2) {
				Virus virus;
				virus.y = i, virus.x = j, virus.time = 0;
				viruses[virus_count++] = virus;
			}
		}

	int picked[10] = { 0, };
	min_time = MAX_TIME;
	dfs(-1, 0, picked);

	if (min_time == MAX_TIME)
		printf("-1");
	else
		printf("%d", min_time);
			
	return 0;
}
