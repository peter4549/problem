#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool visited[100001];
vector<pair<int, int>> graph[100001];
int maximumDiameter, maximumIndex;

void dfs(int v, int w) {
	if (visited[v])
		return;

	visited[v] = true;

	if (maximumDiameter < w) {
		maximumDiameter = w;
		maximumIndex = v;
	}

	for (int i = 0; i < graph[v].size(); ++i) {
		if (!visited[graph[v][i].first]) 
			dfs(graph[v][i].first, w + graph[v][i].second);
	}
}

int main() {
	int V, i, u, v, w;

	scanf("%d", &V);

	for (i = 0; i < V; ++i) {
		scanf("%d", &v);

		while (true) {
			scanf("%d", &u);

			if (u == -1)
				break;

			scanf("%d", &w);

			graph[v].push_back(make_pair(u, w));
		}
	}	

	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(maximumIndex, 0);

	printf("%d", maximumDiameter);

	return 0;
}
