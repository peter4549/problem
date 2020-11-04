#include <cstdio>
#include <vector>

using namespace std;

int n, a, b, m, count(-1);
vector<int> graph[100];
bool visited[100];

void dfs(int u, int v) {
	if (visited[u])
		return;

	if (u == b) {
		::count = v;
		return;
	}

	visited[u] = true;

	for (int i = 0; i < graph[u].size(); ++i) {
		dfs(graph[u][i], v + 1);
	}
}

int main() {
	int x, y;

	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &m);

	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(a, 0);
	printf("%d", ::count);

	return 0;
}
