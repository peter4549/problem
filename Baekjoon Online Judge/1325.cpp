#include <cstdio>
#include <cstring>
#include <vector>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

bool visited[10001];
int hacked[10001], k;
vector<int> v[10001];

void dfs(int a) {
	visited[a] = true;
	++hacked[a];

	k = MAX(k, hacked[a]);

	for (int i(0); i < v[a].size(); ++i) {
		int b(v[a][i]);

		if (!visited[b])
			dfs(b);
	}
}

int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);

	int a, b;

	for (i = 0; i < M; ++i) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
	}

	for (i = 1; i <= N; ++i) {
		dfs(i);
		memset(visited, false, sizeof(visited));
	}

	for (i = 1; i <= N; ++i) 
		if (hacked[i] == k)
			printf("%d ", i);

	return 0;
}
