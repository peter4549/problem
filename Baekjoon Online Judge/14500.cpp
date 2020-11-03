#include <cstdio>
#include <cstring>

#define MAX(a, b) a > b ? a : b

using namespace std;

inline void swap(int& a, int& b) {
	int t(a);
	a = b;
	b = t;
}

int N, M;
int map[502][502];

struct Tetromino {
	int max = 0;

	void rotate() {
		int t[502][502];

		if (N > M) {
			for (int y = 0; y < N; ++y)
				for (int x = 0; x < M; ++x)
					t[x][y] = map[N - y - 1][x];

			swap(N, M);
		}
		else if (N < M) {
			for (int y = 0; y < N; ++y)
				for (int x = 0; x < M; ++x)
					t[x][y] = map[N - y - 1][x];
			
			swap(N, M);
		}
		else {
			for (int y = 0; y < N; ++y)
				for (int x = 0; x < M; ++x)
					t[y][x] = map[M - x - 1][y];
		}
		
		memcpy(map, t, sizeof(t));
	}

	void I() {
		int sum(0);

		for (int i(0); i < N; ++i)
			for (int j(0); j < M - 3; ++j) {
				sum = 0;

				for (int k(j); k < j + 4; ++k)
					sum += map[i][k];

				max = MAX(max, sum);
			}
	}

	void O() {
		int sum(0);

		for (int i(0); i < N - 1; ++i)
			for (int j(0); j < M - 1; ++j) {
				sum = 0;
				sum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
				max = MAX(max, sum);
			}
	}

	void L() {
		int sum(0);

		for (int i(0); i < N - 2; ++i)
			for (int j(0); j < M - 1; ++j) {
				sum = 0;
				sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
				max = MAX(max, sum);
			}
	}

	void S() {
		int sum(0);

		for (int i(0); i < N - 2; ++i)
			for (int j(0); j < M - 1; ++j) {
				sum = 0;
				sum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
				max = MAX(max, sum);
			}
	}

	void T() {
		int sum(0);

		for (int i(0); i < N - 1; ++i)
			for (int j(0); j < M - 2; ++j) {
				sum = 0;
				sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
				max = MAX(max, sum);
			}
	}

	void J() {
		int sum(0);

		for (int i(0); i < N - 2; ++i)
			for (int j(0); j < M - 1; ++j) {
				sum = 0;
				sum = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j] + map[i + 2][j + 1];
				max = MAX(max, sum);
			}
	}

	void Z() {
		int sum(0);

		for (int i(0); i < N - 2; ++i)
			for (int j(0); j < M - 1; ++j) {
				sum = 0;
				sum = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
				max = MAX(max, sum);
			}
	}

	void calculateMax() {
		for (int t(0); t < 4; ++t) {
			if (t < 1)
				O();
			
			if (t < 2)
				I();

			L(), S(), T(), J(), Z();
			rotate();
		}
	}
};



int main() {
	scanf("%d %d", &N, &M);

	for (int i(0); i < N; ++i)
		for (int j(0); j < M; ++j)
			scanf("%d", &map[i][j]);

	Tetromino tetromino;
	tetromino.calculateMax();

	printf("%d", tetromino.max);

	return 0;
}
