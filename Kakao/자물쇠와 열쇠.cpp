#include <iostream>
#include <string>

using namespace std;

int key[21][21], lock[21][21];
int M, N;
int A[61][61];
int B[61][61];

void rotate() {
	for (int i = 0; i < M / 2; i++) {
		for (int j = i; j < M - i - 1; j++) {
			int k = key[i][j];
			key[i][j] = key[M - 1 - j][i];
			key[M - 1 - j][i] = key[M - 1 - i][M - 1 - j];
			key[M - 1 - i][M - 1 - j] = key[j][M - 1 - i];
			key[j][M - 1 - i] = k;
		}
	}
}

void insert(int y, int x) {
	for (int i(y); i < y + M; ++i)
		for (int j(x); j < x + M; ++j)
			if (M - 1 < i || i < M + N - 1 && M - 1 < j || j < M + N - 1)
				A[i][j] = A[i][j] != key[i - y][j - x];
}

bool check() {
	for (int i(M - 1); i < M + N - 1; ++i)
		for (int j(M - 1); j < M + N - 1; ++j)
			if (A[i][j] == 0)
				return false;

	return true;
}

int main() {
	scanf("%d %d", &M, &N);
	
	for (int i(0); i < M; ++i)
		for (int j(0); j < M; ++j)
			scanf("%d", &key[i][j]);

	for (int i(0); i < N; ++i)
		for (int j(0); j < N; ++j)
			scanf("%d", &lock[i][j]);

	for (int i(0); i < 4; ++i) {
		rotate();

		for (int y(0); y < N; ++y)
			for (int x(0); x < N; ++x)
				A[y + M - 1][x + M - 1] = lock[y][x];

		for (int y(0); y < M + N - 1; ++y) {
			for (int x(0); x < M + N - 1; ++x) {
				memcpy(B, A, sizeof(A));
				insert(y, x);

				if (check()) {
					printf("true");
					return 0;
				}
				memcpy(A, B, sizeof(A));
			}
		}
		
		memset(A, 0, sizeof(A));
	}

	printf("false");
	return 0;
}
