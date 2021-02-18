#include <cstdio>

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };


int R, C, Y, X, K;
int matrix[1001][1001];
bool visited[1001][1001];

void dfs(int y, int x, int k) {
	visited[y][x] = true;

	matrix[y][x] = K;

	for (int d(0); d < 4; ++d) {
		int r(y + dy[d]);
		int c(x + dx[d]);

		if (r < 0 || R <= r || c < 0 || C <= c)
			continue;

		if (matrix[r][c] != k)
			continue;

		if (!visited[r][c])
			dfs(r, c, k);
	}
}

void print() {
	for (int r(0); r < R; ++r) {
		for (int c(0); c < C; ++c) {
			printf("%d", matrix[r][c]);
		}

		printf("\n");
	}
}

int main() {
	
	scanf("%d %d", &R, &C);

	for (int r(0); r < R; ++r)
		for (int c(0); c < C; ++c)
			scanf("%1d", &matrix[r][c]);

	scanf("%d %d %d", &Y, &X, &K);
	int k(matrix[Y][X]);

	dfs(Y, X, k);
	print();

	return 0;
}
