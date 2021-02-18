#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> people[2001];
bool exist;
bool visited[2001];

void dfs(int u, int count) {
	if (count > 3) {
		exist = true;
		return;
	}

	visited[u] = true;

	for (int i(0); i < people[u].size(); ++i) {
		int v(people[u][i]);

		if (!visited[v])
			dfs(v, count + 1);

		if (exist)
			return;
	}

	visited[u] = false;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i(0); i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		people[a].push_back(b);
		people[b].push_back(a);
	}

	for (int i(0); i < N; ++i) {
		memset(visited, false, sizeof(visited));
		dfs(i, 0);
		
		if (exist)
			break;
	}

	printf("%d", exist);

	return 0;
}
