#include <cstdio>
#include <cstring>

int s[100001], k;
bool visited[100001];
bool done[100001];

void dfs(int u) {
	visited[u] = true;

	int v(s[u]);

	if (!visited[v])
		dfs(v);
	else if (!done[v]) {
		for (int i(v); i != u; i = s[i])
			++k;

		++k;
	}

	done[u] = true;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int i(0); i < T; ++i) {
		int n;
		scanf("%d", &n);

		for (int j(1); j <= n; ++j)
			scanf("%d", &s[j]);

		k = 0;

		for (int j(1); j <= n; ++j)
			if (!visited[j])
				dfs(j);

		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));

		printf("%d \n", n - k);
	}

	return 0;
}
