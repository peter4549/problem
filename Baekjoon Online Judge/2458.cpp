#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool visited[501];
int c;
vector<int> A[501];
vector<int> B[501];

void dfs(int a, vector<int>* v) {
	visited[a] = true;
	++c;

	for (int i(0); i < v[a].size(); ++i) {
		int b(v[a][i]);

		if (!visited[b])
			dfs(b, v);
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i(0); i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		A[b].push_back(a);
		B[a].push_back(b);
	}

	int student(0);

	for (int i(1); i <= N; ++i) {
		c = -1;
		dfs(i, A);
		memset(visited, false, sizeof(visited));
		dfs(i, B);
		memset(visited, false, sizeof(visited));
		if (c == N) 			
			++student;
	}

	printf("%d", student);

	return 0;
}
