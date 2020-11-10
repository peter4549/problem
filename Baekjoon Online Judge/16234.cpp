#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

int N, L, R;
int A[50][50];

void bfs(int r, int c, int unions[][50], int union_number, int& sum, int& count) {
    queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	unions[r][c] = union_number;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		
		sum += A[r][c];
		++count;

		for (int i(0); i < 4; ++i) {
			int y = r + dy[i];
			int x = c + dx[i];

			if (y < 0 || y >= N || x < 0 || x >= N)
				continue;

			int d = abs(A[r][c] - A[y][x]);

			if (!unions[y][x] && d >= L && d <= R) {
				unions[y][x] = union_number;
				q.push(make_pair(y, x));
			}
		}
	}
}

int main() {
	int r, c, move_count(0);
	scanf("%d %d %d", &N, &L, &R);

	for (r = 0; r < N; ++r)
		for (c = 0; c < N; ++c)
			scanf("%d", &A[r][c]);

	bool moved(true);
	while (moved) {
		moved = false;
		int union_number(0);
		int sum[25000] = { 0, }, count[25000] = { 0, };
		int unions[50][50] = { 0, };

		for (r = 0; r < N; ++r)
			for (c = 0; c < N; ++c) {
				if (!unions[r][c]) {
					++union_number;
					bfs(r, c, unions, union_number, sum[union_number], count[union_number]);
				}
			}

		for (r = 0; r < N; ++r)
			for (c = 0; c < N; ++c) {
				int average = sum[unions[r][c]] / count[unions[r][c]];

				if (A[r][c] != average) {
					A[r][c] = average;
					moved = true;
				}
			}

		if (moved)
		    ++move_count;
	}

	printf("%d", move_count);

	return 0;
}
