#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAX(a, b) (a > b ? a : b)

using namespace std;

inline void swap(int& a, int& b) {
	int c(a);
	a = b;
	b = c;
}

int N, M, K, paper[502][502];

int I[2][4] = {
	{ 1, 1, 1, 1 },
    { 0, 0, 0, 0 }
};

int O[2][4] = {
	{ 1, 1, 0, 0 },
    { 1, 1, 0, 0 }
};

int T[2][4] = {
	{ 1, 1, 1, 0 },
    { 0, 1, 0, 0 }
};

int J[2][4] = {
	{ 1, 1, 1, 0 },
    { 0, 0, 1, 0 }
};

int L[2][4] = {
	{ 1, 1, 1, 0 },
    { 1, 0, 0, 0 }
};

int S[2][4] = {
	{ 0, 1, 1, 0 },
    { 1, 1, 0, 0 },
};

int Z[2][4] = {
	{ 1, 1, 0, 0 },
    { 0, 1, 1, 0 }
};

void rotate() {
	int t[502][502];

	if (N > M) {
		for (int y = 0; y < N; ++y)
			for (int x = 0; x < M; ++x)
				t[x][y] = paper[N - y - 1][x];

		swap(N, M);
	}
	else if (N < M) {
		for (int y = 0; y < N; ++y)
			for (int x = 0; x < M; ++x)
				t[x][y] = paper[N - y - 1][x];

		swap(N, M);
	}
	else {
		for (int y = 0; y < N; ++y)
			for (int x = 0; x < M; ++x)
				t[y][x] = paper[M - x - 1][y];
	}

	memcpy(paper, t, sizeof(t));
}

void solve() {
	for (int i(0); i < N; ++i) {
		for (int j(0); j < M - 2; ++j) {
			int k[7] = { 0, };

			for (int y(0); y < 2; ++y) {
				for (int x(0); x < 4; ++x) {
					if (I[y][x])
						k[0] += paper[i + y][j + x];

					if (O[y][x])
						k[1] += paper[i + y][j + x];

					if (T[y][x])
						k[2] += paper[i + y][j + x];

					if (J[y][x])
						k[3] += paper[i + y][j + x];
				
					if (L[y][x])
						k[4] += paper[i + y][j + x];

					if (S[y][x])
						k[5] += paper[i + y][j + x];

					if (Z[y][x])
						k[6] += paper[i + y][j + x];
				}
			}

			int m(0);

			for (int n(0); n < 7; ++n) {
				if (m < k[n])
					m = k[n];
			}

			K = MAX(K, m);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i(0); i < N; ++i)
		for (int j(0); j < M; ++j)
			scanf("%d", &paper[i][j]);

	for (int i(0); i < 4; ++i) {
		solve();
		rotate();
	}

	printf("%d", K);

	return 0;
}
