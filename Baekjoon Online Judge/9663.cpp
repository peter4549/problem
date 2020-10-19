#include <stdio.h>

int N(0), count(0);
int prohibitedArea[15][15];

void putQueen(int n, int m) {
	int i;

	for (i = 0; i < N; ++i) {
		++prohibitedArea[n][i];

		if (i >= n)
		    ++prohibitedArea[i][m];

		if (n + i < N && m + i < N)
			++prohibitedArea[n + i][m + i];

		if (n + i < N && m - i >= 0)
			++prohibitedArea[n + i][m - i];
	}
}

void putAwayQueen(int n, int m) {
	int i;

	for (i = 0; i < N; ++i) {
		--prohibitedArea[n][i];

		if (i >= n)
			--prohibitedArea[i][m];

		if (n + i < N && m + i < N)
			--prohibitedArea[n + i][m + i];

		if (n + i < N && m - i >= 0)
			--prohibitedArea[n + i][m - i];
	}
}

void backtrack(int n) {
	if (n == N) {
		++count;
		return;
	}

	for (int i = 0; i < N; ++i) {

		if (prohibitedArea[n][i] == 0) {
			putQueen(n, i);
			backtrack(n + 1);
			putAwayQueen(n, i);
		}
	}
}

int main() {
	scanf("%d", &N);

	backtrack(0);

	printf("%d", count);

	return 0;
}
