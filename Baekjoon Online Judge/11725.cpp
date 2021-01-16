#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<int> tree[100001];
bool visited[100001];
int A[100001];

void dfs(int u) {
	visited[u] = true;

	for (int i(0); i < tree[u].size(); ++i) {
		int v(tree[u][i]);

		if (!visited[v]) {
			A[v] = u;
			dfs(v);
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i(0); i < N - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	
	dfs(1);

	for (int i(2); i <= N; ++i)
		printf("%d \n", A[i]);

	return 0;
}
