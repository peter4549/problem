#include <cstdio>
#include <queue>

using namespace std;

bool visited[100001];
int N, K;

int bfs(pair<int, int> start) {
	queue<pair<int, int>> q;
	visited[start.first] = true;
	q.push(start);

	while (!q.empty()) {
		pair<int, int>p(q.front());
		q.pop();

		int x(p.first);
		int s(p.second);

		if (x == K)
			return s;
		
		if (x * 2 < 100001 && !visited[x * 2]) {
			visited[x * 2] = true;
			q.push({ x * 2, s });
		}
		
		if (x - 1 >= 0 && !visited[x - 1]) {
			visited[x - 1] = true;
			q.push({ x - 1, s + 1 });
		}

		if (x + 1 < 100001 && !visited[x + 1]) {
			visited[x + 1] = true;
			q.push({ x + 1, s + 1 });
		}
	}

	return 0;
}

int main() {
	scanf("%d %d", &N, &K);

	printf("%d \n", bfs({ N, 0 }));

	return 0;
}
