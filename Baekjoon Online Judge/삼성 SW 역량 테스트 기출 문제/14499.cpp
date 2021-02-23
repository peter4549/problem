#include <cstdio>

enum Direction {
	East = 0,
	West,
	North,
	South
};

inline void swap(int& a, int& b) {
	int c(a);
	a = b;
	b = c;
}

const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { 1, -1, 0, 0 };

int N, M, map[21][21];

struct Dice {
	int array[6] = { 0, }, r, c;

	void roll(int direction) {
		int y(r + dy[direction]);
		int x(c + dx[direction]);

		if (y < 0 || y >= N || x < 0 || x >= M)
			return;

		r = y;
		c = x;

		switch (direction)
		{
		case East:
			swap(array[0], array[2]);
			swap(array[2], array[5]);
			swap(array[5], array[3]);
			break;
		case West:
			swap(array[0], array[3]);
			swap(array[3], array[5]);
			swap(array[5], array[2]);
			break;
		case North:
			swap(array[0], array[1]);
			swap(array[1], array[5]);
			swap(array[5], array[4]);
			break;
		case South:
			swap(array[0], array[4]);
			swap(array[4], array[5]);
			swap(array[5], array[1]);
			break;
		default:
			break;
		}

		if (!map[r][c])
			map[r][c] = array[5];
		else {
			array[5] = map[r][c];
			map[r][c] = 0;
		}

		printf("%d \n", array[0]);
	}
};

int main() {
	int y, x, K, k;
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);

	for (int r(0); r < N; ++r)
		for (int c(0); c < M; ++c)
			scanf("%d", &map[r][c]);

	Dice dice;
	dice.r = y;
	dice.c = x;

	for (int i(0); i < K; ++i) {
		scanf("%d", &k);
		dice.roll(k - 1);
	}

	return 0;
}
