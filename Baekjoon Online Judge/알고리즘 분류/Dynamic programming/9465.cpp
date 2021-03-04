#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int D[2][100001], sticker[2][100001];

void solve(int n) {
	if (n < 0)
		return;

	D[0][n] = max(D[1][n + 1], D[1][n + 2]) + sticker[0][n];
	D[1][n] = max(D[0][n + 1], D[0][n + 2]) + sticker[1][n];

	solve(n - 1);
}

int main() {
	int T, n;

	scanf("%d", &T);

	for (int t(0); t < T; ++t) {
		scanf("%d", &n);

		for (int i(0); i < 2; ++i)
			for (int j(1); j <= n; ++j) 
				scanf("%d", &sticker[i][j]);

		D[0][n] = sticker[0][n];
		D[1][n] = sticker[1][n];
		D[0][n - 1] = sticker[0][n - 1] + sticker[1][n];
		D[1][n - 1] = sticker[1][n - 1] + sticker[0][n];

		solve(n - 2); // or n

		printf("%d \n", max(max(D[0][0], D[0][1]), max(D[1][0], D[1][1])));

		memset(D, 0, sizeof(D));
		memset(sticker, 0, sizeof(sticker));
	}

	return 0;
}
