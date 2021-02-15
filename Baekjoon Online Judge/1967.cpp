#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<pair<int, int>> tree[10001];
int length, end_point;
bool visited[10001];

void dfs(int u, int l) {
	if (visited[u])
		return;

	visited[u] = true;

	if (length < l) {
		end_point = u;
		length = l;
	}

	for (int i(0); i < tree[u].size(); ++i) {
		pair<int, int> v(tree[u][i]);
		if (!visited[v.first]) {
			dfs(v.first, l + v.second);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i(0); i < n - 1; ++i) {
		int u, v, x;
		scanf("%d %d %d", &u, &v, &x);
		tree[u].push_back(make_pair(v, x));
		tree[v].push_back(make_pair(u, x));
	}

	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(end_point, 0);

	printf("%d", length);

	return 0;
}
