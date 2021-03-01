#include <cstdio>
#include <cstdlib>
#include <vector>

#define MIN(a, b) (a < b ? a : b)

using namespace std;

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

bool visited[101][101];
int N, map[101][101];
vector<vector<pair<int, int>>> v;

void dfs(int n, int m, vector<pair<int, int>>& v) {
	visited[n][m] = true;
	v.push_back({ n, m });

	for (int i(0); i < 4; ++i) {
		int y(n + dy[i]);
		int x(m + dx[i]);

		if (y < 0 || y >= N || x < 0 || x >= N)
			continue;

		if (!visited[y][x] && map[y][x])
			dfs(y, x, v);
	}
}

int main() {
	int min(10001);

	scanf("%d", &N);

	for (int i(0); i < N; ++i)
		for (int j(0); j < N; ++j)
			scanf("%d", &map[i][j]);

	for (int i(0); i < N; ++i) {
		for (int j(0); j < N; ++j) {
			vector<pair<int, int>> k;

			if (!visited[i][j] && map[i][j]) {
				dfs(i, j, k);
				
				if (!k.empty())
					v.push_back(k);
			}
		}
	}

	for (int i(0); i < v.size(); ++i) {
		vector<pair<int, int>> u(v[i]);

		for (int j(i + 1); j < v.size(); ++j) {
			vector<pair<int, int>> w(v[j]);

			for (auto& n : u) {
				for (auto& m : w) {
					int k(abs(n.first - m.first) + abs(n.second - m.second) - 1);
					min = MIN(min, k);
				}
			}
		}
	}

	printf("%d \n", min);

	return 0;
}
