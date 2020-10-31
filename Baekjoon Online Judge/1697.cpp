#include <cstdio>
#include <queue>

using namespace std;

int N, K;
bool visited[100001];

int bfs() {
	int p, depth;
	queue<pair<int, int>> q;
	
	q.push(make_pair(N, 0));
	visited[N] = true;

	while (!q.empty()) {
		p = q.front().first;
		depth = q.front().second;
		q.pop();

		if (p == K) 
			return depth;

		if (p + 1 < 100001 && !visited[p + 1]) {
			q.push(make_pair(p + 1, depth + 1));
			visited[p + 1] = true;
		}

		if (p - 1 >= 0 && !visited[p - 1]) {
			q.push(make_pair(p - 1, depth + 1));
			visited[p - 1] = true;
		}

		if (p * 2 < 100001 && !visited[p * 2]) {
			q.push(make_pair(p * 2, depth + 1));
			visited[p * 2] = true;
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);

	printf("%d", bfs());

	return 0;
}
