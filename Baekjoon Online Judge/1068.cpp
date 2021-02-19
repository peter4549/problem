#include <cstdio>
#include <vector>

using namespace std;

bool visited[51];
int leaf_node;
vector<int> tree[51];

void dfs(int u) {
	if (visited[u])
		return;

	visited[u] = true;

	if (tree[u].empty()) {
		++leaf_node;
		return;
	}

	int j(1), size(tree[u].size());

	for (int i(0); i < size; ++i) {
		int v(tree[u][i]);

		if (!visited[v])
			dfs(v);
		else {
			if (j == size) {
				++leaf_node;
				return;
			}

			++j;
		}
	}
}

int main() {
	int N, root;
	scanf("%d", &N);

	for (int i(0); i < N; ++i) {
		int node;
		scanf("%d", &node);
		if (node != -1)
		    tree[node].push_back(i);
		else
			root = i;
	}
	
	int node;
	scanf("%d", &node);
	visited[node] = true;

	dfs(root);
	printf("%d", leaf_node);

	return 0;
}
