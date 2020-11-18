#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int N, d;
int A[21][21], B[21][21];

int getD() {
	int sum[5] = { 0, };

	for (int r(1); r <= N; ++r)
		for (int c(1); c <= N; ++c) {
			if (B[r][c] == 1)
				sum[0] += A[r][c];
			else if (B[r][c] == 2)
				sum[1] += A[r][c];
			else if (B[r][c] == 3)
				sum[2] += A[r][c];
			else if (B[r][c] == 4)
				sum[3] += A[r][c];
			else if (B[r][c] == 5 || !B[r][c])
				sum[4] += A[r][c];
		}

	return *max_element(sum, sum + 5) - *min_element(sum, sum + 5);
}

int main() {
	int y, x, d2, d1, r, c;

	d = 0x7FFFFFFF;

	scanf("%d", &N);

	for (y = 1; y <= N; ++y)
		for (x = 1; x <= N; ++x)
			scanf("%d", &A[y][x]);

	for (y = 1; y <= N; ++y)
		for (x = 1; x <= N; ++x)
			for (d2 = 1; d2 < N; ++d2)
				for (d1 = 1; d1 < N; ++d1) {
					if (x + d2 + d1 > N)
						continue;

					if (y - d1 < 1 || y + d2 > N)
						continue;

					for (r = 0; r <= d1; ++r) {
						B[x + r][y - r] = 5;
						B[x + d2 + r][y + d2 - r] = 5;
					}

					for (r = 0; r <= d2; ++r) {
						B[x + r][y + r] = 5;
						B[x + d1 + r][y - d1 + r] = 5;
					}

					for (c = 1; c <= y; ++c)
						for (r = 1; r < x + d1; ++r) {
							if (B[r][c] == 5)
								break;

							B[r][c] = 1;
						}

					for (c = y + 1; c <= N; ++c)
						for (r = 1; r <= x + d2; ++r) {
							if (B[r][c] == 5)
								break;

							B[r][c] = 2;
						}

					for (r = x + d1; r <= N; ++r)
					    for (c = 1; c < y - d1 + d2; ++c) {
							if (B[r][c] == 5)
								break;

							B[r][c] = 3;
						}

					for (r = x + d2 + 1; r <= N; ++r)
						for (c = N; c >= y - d1 + d2; --c) {
							if (B[r][c] == 5)
								break;

							B[r][c] = 4;
						}
					
					d = min(d, getD());

					memset(B, 0, sizeof(B));
				}

	printf("%d", d);

	return 0;
}
