#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[1001] = { false };
vector<int> graph[1001];

void dfs(int v) {
	if (visited[v])
		return;

	visited[v] = true;

	for (int i = 0; i < graph[v].size(); ++i) {
		dfs(graph[v][i]);
	}
}


int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int connectedComponentCount(0);

	for (int i = 1; i <= N; i++)
	{
		if (visited[i])
			continue;

		dfs(i);
		++connectedComponentCount;
	}

	printf("%d", connectedComponentCount);

	return 0;
}
