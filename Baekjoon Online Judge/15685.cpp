#include <cstdio>

int N;
int grid[101][101];

int main() {
	int x, y, d, g, i, j, k;
	int directions[1024];

	scanf("%d", &N);
	
	for (i = 0; i < N; ++i) {
		scanf("%d %d %d %d", &x, &y, &d, &g);

		grid[y][x] = 1;

		if (d == 0) {
			if (x + 1 <= 100)
				++x;
			else
				break;
		}
		else if (d == 1) {
			if (y - 1 >= 0)
				--y;
			else
				break;
		}
		else if (d == 2) {
			if (x - 1 >= 0)
				--x;
			else
				break;
		}
		else if (d == 3) {
			if (y + 1 <= 100)
				++y;
			else
				break;
		}

		directions[0] = d;
		grid[y][x] = 1;
		
		for (j = 1; j <= g; ++j) {
			for (k = (1 << j - 1); k < (1 << j); ++k) {
				directions[k] = (directions[(1 << j) - k - 1] + 1) % 4;
				if (directions[k] == 0) {
					if (x + 1 <= 100)
						++x;
					else
						break;
				}
				else if (directions[k] == 1) {
					if (y - 1 >= 0)
						--y;
					else
						break;
				}
				else if (directions[k] == 2) {
					if (x - 1 >= 0)
						--x;
					else
						break;
				}
				else if (directions[k] == 3) {
					if (y + 1 <= 100)
						++y;
					else
						break;
				}

				grid[y][x] = 1;
			}
		}
	}

	int count(0);

	for (i = 0; i < 100; ++i) {
		for (j = 0; j < 100; ++j) {
			if (grid[i][j] && grid[i][j + 1] && grid[i + 1][j] && grid[i + 1][j + 1])
				++count;
		}
	}

	printf("%d", count);
	
	return 0;
}
