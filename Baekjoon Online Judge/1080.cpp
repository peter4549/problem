#include <stdio.h>

int N, M;
int A[50][50];
int B[50][50];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void flip(int y, int x) {
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			A[y + i][x + j] = 1 - A[y + i][x + j];
}

bool equals() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (A[i][j] != B[i][j])
				return false;

	return true;
}

int main() {
	int i, j, count(0);

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j)
			scanf("%1d", &A[i][j]);

	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j)
			scanf("%1d", &B[i][j]);

	for (i = 0; i < N - 2; ++i)
		for (j = 0; j < M - 2; ++j)
			if (A[i][j] != B[i][j]) {
				flip(i, j);
				++count;
			}

	if (equals())
		printf("%d", count);
	else
		printf("-1");

	return 0;
}
