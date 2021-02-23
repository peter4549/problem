#include <cstdio>
#include <queue>

using namespace std;

int visited[1000001];
int F, S, G, U, D;

int bfs(int s) {
	queue<int> q;
	q.push(s);

	visited[s] = 0;

	while (!q.empty()) {
		int p(q.front());
		q.pop();

		if (p == G)
			return visited[G];

		if (U && p + U <= F) {
			int u(p + U);

			if (!visited[u]) {
				visited[u] = visited[p] + 1;
				q.push(u);
			}
		}

		if (D && p - D > 0) {
			int d(p - D);
			
			if (!visited[d]) {
				visited[d] = visited[p] + 1;
				q.push(d);
			}
		}

	}

	return -1;
}

int main() {
	int min(-1);

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	min = bfs(S);

	if (min == -1)
		printf("use the stairs");
	else
		printf("%d", min);

	return 0;
}
