#include <cstdio>

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { 1, 0, -1, 0 };

int N;
int grid[101][101];

int main() {
	int x, y, d, g;

	scanf("%d", &N);
	
	for (int i(0); i < N; ++i) {
		int curve_count = 0;
		int curve[1024] = { 0, };

		scanf("%d %d %d %d", &x, &y, &d, &g);

		curve[curve_count++] = d;
		grid[y][x] = 1;

		for (int j(0); j < g; ++j) {
			for (int k = curve_count - 1; k >= 0; --k)
				curve[curve_count++] = (curve[k] + 1) % 4;
		}

		for (int j(0); j < curve_count; ++j) {
			y += dy[curve[j]];
			x += dx[curve[j]];

			if (y < 0 || y >= 101 || x < 0 || x > 101)
				break;

			grid[y][x] = 1;
		}
	}

	int count(0);

	for (int i(0); i < 100; ++i) {
		for (int j(0); j < 100; ++j) {
			if (grid[i][j] && grid[i][j + 1] && grid[i + 1][j] && grid[i + 1][j + 1])
				++count;
		}
	}

	printf("%d", count);
	
	return 0;
}
