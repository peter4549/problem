#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

bool pushed[101], visited[101];
int N;
vector<int> cycle, v[101];

void dfs(int n, int m) {
	visited[n] = true;

	for (int i(0); i < v[n].size(); ++i) {
		int u(v[n][i]);

		if (u == m) {
			for (int j(1); j <= N; ++j)
				if (visited[j] && !pushed[j]) {
					cycle.push_back(j);
					pushed[j] = true;
				}
			
			return;
		}

		if (!visited[u]) {
			dfs(u, m);
			visited[u] = false;
		}
	}
}

int main() {
	int n;
	scanf("%d", &N);

	for (int i(1); i <= N; ++i) {
		scanf("%d", &n);
		v[i].push_back(n);
	}

	for (int i(1); i <= N; ++i) {
		dfs(i, i);
		memset(visited, false, sizeof(visited));
	}

	printf("%d \n", cycle.size());

	sort(cycle.begin(), cycle.end());

	for (auto& it : cycle)
		printf("%d \n", it);

	return 0;
}
