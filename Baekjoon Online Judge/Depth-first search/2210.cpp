#include <iostream>
#include <set>

using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

int dial[5][5];
set<int> s;

void dfs(int y, int x, int c, int number) {
	if (c == 5) {
		s.insert(number);
		return;
	}
	
	for (int i(0); i < 4; ++i) {
		int n(y + dy[i]);
		int m(x + dx[i]);

		if (n < 0 || n >= 5 || m < 0 || m >= 5)
			continue;
		
		dfs(n, m, c + 1, number * 10 + dial[n][m]);
	}
}

int main() {
	for (int i(0); i < 5; ++i)
		for (int j(0); j < 5; ++j)
			scanf("%d", &dial[i][j]);
	

	for (int i(0); i < 5; ++i)
		for (int j(0); j < 5; ++j)
	        dfs(i, j, 0, dial[i][j]);

	printf("%d", s.size());

	return 0;
}
